/*************************************************************************
                           CmdLoad  -  description
                             -------------------
    d�but                : 15 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CmdLoad> (fichier CmdLoad.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "CmdLoad.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

bool CmdLoad::Executer ( )
// Algorithme :
//
{
	if(ok)
	{
		bool fichierValide = true;

		//On remplit d'abord le vecteur des commandes charg�es � partir du fichier texte
		string ligne;
		while(getline(fichier, ligne))
		{
			istringstream iss(ligne);
			string mot;
			vector<string> parametres;

			//Pour chaque commande, on s�pare les diff�rents param�tres dans un vecteur
			while (getline( iss, mot, ' ' ))
			{
				parametres.push_back(mot);
			}
			commandesChargees.push_back(parametres);
		}
		fichier.close();

		//Puis on parcourt le vecteur en faisant diff�rentes v�rifications
		for(size_t i=0 ; i<commandesChargees.size() ; i++)
		{
			//Si le type de la commande est correct (C,R,L,PL ou OA)
			if(TypeEstCorrect(commandesChargees[i][0]))
			{
				//On v�rifie que la commande est valide (types des parametres)
				if( ( commandesChargees[i][0]!=OA && !CmdEstCorrecte(commandesChargees[i],false) ) || ( commandesChargees[i][0]==OA && !CmdEstCorrecte(commandesChargees[i],true) ) )
				{
					fichierValide = false;
					cout << "ERR" << endl;
					cout << "#Le fichier contient au moins une commande ayant un type de parametre invalide." << endl;
					return 0;
				}
				else
				{
					if( (commandesChargees[i][0]==OA && commandesChargees[i].size()<=2) || (commandesChargees[i][0]==C && commandesChargees[i].size()!=5) || (commandesChargees[i][0]==R && commandesChargees[i].size()!=6) || (commandesChargees[i][0]==L && commandesChargees[i].size()!=6) || (commandesChargees[i][0]==PL && commandesChargees[i].size()%2!=0 && commandesChargees[i].size()<2) )
					{
						fichierValide = false;
						cout << "ERR" << endl;
						cout << "#Le fichier contient au moins une commande ayant un nombre de parametres invalide." << endl;
						return 0;
					}
				}
			}
			else
			{
				fichierValide = false;
				cout << "ERR" << endl;
				cout << "#Le fichier contient au moins une commande inexistante." << endl;
				return 0;
			}

			//On verifie que l'element n'existe pas deja dans le modele
			if(modele->ElementExiste(commandesChargees[i][1]))
			{
				fichierValide = false;
				cout << "ERR" << endl;
				cout << "#Le fichier contient au moins un element deja existant." << endl;
				return 0;
			}
			//Sinon, s'il n'existe pas dans le modele
			else
			{
				if(i!=0)
				{
					//On verifie qu'il n'existe pas deja ailleurs dans le fichier a charger
					int taille = commandesEnCours.size();
					for(int k=0;k<taille;k++)
					{
						if (commandesEnCours[k]==commandesChargees[i][1])
						{
							fichierValide = false;
							cout << "ERR" << endl;
							cout << "#Le fichier contient au moins deux elements ayant le meme nom." << endl;
							return 0;
						}
						//S'il n'est pas non plus dans le fichier a charger, on l'ajoute à la liste
						//des autres elements du fichier.
						else
						{
							commandesEnCours.push_back(commandesChargees[i][1]);
						}
					}
				}
				else
				{
					commandesEnCours.push_back(commandesChargees[i][1]);
				}
			}

			//Si c'est un OA, on verifie en plus que les elements qu'il contient existent bien dans le modele
			//ou précedemment dans le fichier a charger
			if(commandesChargees[i][0]==OA)
			{
				for(size_t a=2;a<commandesChargees[i].size();a++)
				{
					if(!modele->ElementExiste(commandesChargees[i][a]))
					{
						bool existeDansFichier = false;
						for(size_t b=0;b<commandesEnCours.size();b++)
						{
							if(commandesEnCours[b]==commandesChargees[i][a])
							{
								existeDansFichier = true;
							}
						}
						if(!existeDansFichier)
						{
							fichierValide = false;
							cout << "ERR" << endl;
							cout << "#Le fichier contient au moins un objet agrege invalide." << endl;
							return 0;
						}
					}
				}
			}

		}

		//Si tout est bon, on cree/ajoute les elements
		if (fichierValide)
		{
			//cout << "fichier valide" << endl;

			for (size_t i=0 ; i<commandesChargees.size() ; i++)
			{
				string laCommande = "";
				for (size_t j=0 ; j<commandesChargees[i].size() ; j++)
				{
					if (laCommande == "")
					{
						laCommande = commandesChargees[i][j];
					}
					else
					{
						laCommande = laCommande + " " + commandesChargees[i][j];
					}
				}
				//cout << laCommande << endl;
				TraiterCommande(laCommande);
			}
			if(historiser)
			{
				cout<<"OK"<<endl;
				cout<<"#Fichier charge" << endl;
				historiser = false;
			}
			return 1;
		}
	}

} //----- Fin de Methode

void CmdLoad::Undo ()
// Algorithme :
//
{
	for (size_t i=0 ; i<commandesChargees.size() ; i++)
	{
		//for (size_t j=0 ; j<commandesChargees[i].size() ; j++)
		//{
			//supprimer commandesChargees[i] -> le nom de l'�l�ment est commandesChargees[i][1]
			modele->Delete(commandesChargees[i][1]);
		//}
	}

} //----- Fin de Méthode

void CmdLoad::Redo (  )
// Algorithme :
//
{
	//Executer();
	for (size_t i=0 ; i<commandesChargees.size() ; i++)
	{
		string laCommande = "";
		for (size_t j=0 ; j<commandesChargees[i].size() ; j++)
		{
			if (laCommande == "")
			{
				laCommande = commandesChargees[i][j];
			}
			else
			{
				laCommande = laCommande + " " + commandesChargees[i][j];
			}
		}
		//cout << laCommande << endl;
		TraiterCommande(laCommande);
	}
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'op�rateurs
CmdLoad & CmdLoad::operator = ( const CmdLoad & uneCmdLoad )
// Algorithme :
//
{
	if (& uneCmdLoad != this)
	{
			Commande::operator =(uneCmdLoad);
			//fichier=uneCmdLoad.fichier;
			ok = uneCmdLoad.ok;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdLoad::CmdLoad ( const CmdLoad & uneCmdLoad ):CommandeHis(uneCmdLoad),ok(uneCmdLoad.ok)
// Algorithme :
//
{
	//fichier=uneCmdLoad.fichier;
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdLoad>" << endl;
#endif
} //----- Fin de CmdLoad (constructeur de copie)


CmdLoad::CmdLoad ( Modele * leModele, string nomFichier, bool his ):CommandeHis(leModele,his),fichier(nomFichier.c_str())
// Algorithme :
//
{
    //fichier(nomFichier.c_str());  // on ouvre en lecture

    if(!fichier)  // si l'ouverture a echoue
    {
		cout << "ERR" << endl;
		cout << "#Ouverture du fichier "<< nomFichier << " impossible."<< endl;
		ok=false;
    }
    else
    {
    	ok = true;
    }

#ifdef MAP
    cout << "Appel au constructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de CmdLoad


CmdLoad::~CmdLoad ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
//Utilis� pour v�rifier que les noms commencent bien par une lettre
//et ne contiennent ensuite que des caract�res alphanum�riques.
// -> Renvoie 1 si le nom est corect, 0 sinon
bool CmdLoad::NomEstCorrect(string nom)
{
	//cout << "trace: NomEstCorrect( " << nom << " )" << endl;

	//Conversion string en char* pour pouvoir utiliser isalpha
	//(savoir si le 1er caract�re du nom est bien une lettre)
	//et isalnum (savoir si les autres sont bien des caract�res alpha-num�riques)
	char* cstr = new char [nom.length()+1];
	strcpy (cstr, nom.c_str());

	if (!isalpha(cstr[0]))
	{
		return 0;
	}
	else
	{
		for (size_t i=1; i<strlen(cstr); i++)
		{
			if (!isalnum(cstr[i]))
			{
				return 0;
			}
		}
	}
	delete[] cstr;
	return 1;
}


//Utilis� pour v�rifier que les param�tres sont bien des chiffres
// -> Renvoie 1 si le param�tre est correct, 0 sinon
bool CmdLoad::ParamEstCorrect(string param)
{
	//cout << "trace: ParamEstCorrect( " << param << " )" << endl;

	//Conversion string en char* pour pouvoir utiliser isdigit
	//(savoir si les caract�res du param�tre sont bien des chiffres)
	char* cstr = new char [param.length()+1];
	strcpy (cstr, param.c_str());

	for (size_t i=0; i<strlen(cstr); i++)
	{
		if (!isdigit(cstr[i]))
		{
			return 0;
		}
	}
	delete[] cstr;
	return 1;
}

//Utilis� pour v�rifier que le type de commande est correct
// -> Renvoie 1 si la commande est correcte, 0 sinon
bool CmdLoad::TypeEstCorrect(string type)
{
	if ( type == C || type == R || type == L || type == PL || type == OA )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//Utilis� pour v�rifier que les param�tres des diff�rentes commandes sont corrects
//estUnOA est � false par d�faut, on le met � true uniquement dans le cas de l'ajout
//d'un OA (obj agr�g�) ou d'une suppression
// -> Renvoie 1 si la commande est correcte, 0 sinon
bool CmdLoad::CmdEstCorrecte(vector<string> commande, bool estUnOA)
{
	if (!TypeEstCorrect(commande[0]) || !NomEstCorrect(commande[1]))
	{
		return 0;
	}

	int longueur = commande.size();
	for (int i=2 ; i<longueur ; i++)
	{
		//Si ce n'est pas un OA -> on regarde si ce sont des param corrects
		//Si c'est un OA -> on regarde si ce sont des noms corrects (m�me s'ils n'existent pas forc�ment)
		if ((!estUnOA && !ParamEstCorrect(commande[i])) || (estUnOA && !NomEstCorrect(commande[i])))
		{
			return 0;
		}
	}

	return 1;
}


bool CmdLoad::TraiterCommande(string cmd)
{
	istringstream iss(cmd);
	string mot;
	vector <string> parametres;

	while (getline( iss, mot, ' ' ))
	{
	    parametres.push_back(mot);
	}

	//D�t�ction de la commande demand�e
	if (parametres[0] == C)
	{
		//cout << "cercle " << endl;

		//Pour que la commande soit valide, on doit avoir 5 arguments:
		//C Name X Y rayon
		if (parametres.size()==5 && CmdEstCorrecte(parametres,false))
		{
			//cout << "OK" << endl;

			//La map params permet de r�cup�rer les param�tres qui sont des chiffres en int
			map<int,int> params;
			for(size_t i=2 ; i<parametres.size() ; i++)
			{
				int valeur;
				istringstream iss( parametres[i] );
				// convertir en un int
				iss >> valeur;
				params[i] = valeur;
			}

			CmdAjoutC c(modele,parametres[1],params[2],params[3],params[4],false);
			c.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Param�tres invalides" << endl;
		}
	}
	else if (parametres[0] == R)
	{
		//cout << "rectangle" << endl;

		//Pour que la commande soit valide, on doit avoir 6 arguments:
		//R Name X1 Y1 X2 Y2
		if (parametres.size() == 6 && CmdEstCorrecte(parametres,false))
		{
			//cout << "OK" << endl;

			//La map params permet de r�cup�rer les param�tres qui sont des chiffres en int
			map<int,int> params;
			for(size_t i=2 ; i<parametres.size() ; i++)
			{
				int valeur;
				istringstream iss( parametres[i] );
				// convertir en un int
				iss >> valeur;
				params[i] = valeur;
			}

			CmdAjoutR r(modele,parametres[1],params[2],params[3],params[4],params[5],false);
			r.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Param�tres invalides" << endl;
		}
	}
	else if (parametres[0] == L)
	{
		//cout << "ligne" << endl;

		//Pour que la commande soit valide, on doit avoir 6 arguments:
		//L Name X1 Y1 X2 Y2
		if (parametres.size() == 6 && CmdEstCorrecte(parametres,false))
		{
			//cout << "OK" << endl;

			//La map params permet de r�cup�rer les param�tres qui sont des chiffres en int
			map<int,int> params;
			for(size_t i=2 ; i<parametres.size() ; i++)
			{
				int valeur;
				istringstream iss( parametres[i] );
				// convertir en un int
				iss >> valeur;
				params[i] = valeur;
			}

			CmdAjoutL l(modele,parametres[1],params[2],params[3],params[4],params[5],false);
			l.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Param�tres invalides" << endl;
		}
	}
	else if (parametres[0] == PL)
	{
		//cout << "polyligne" << endl;

		//Pour que la commande soit valide, on doit avoir un nombre pair d'arguments (au moins 4):
		//PL Name X1 Y1 X2 Y2 ... Xn Yn
		if (parametres.size() >=4 && parametres.size()%2 == 0 && CmdEstCorrecte(parametres, false))
		{
			//cout << "OK" << endl;

			//Le vecteur params permet de r�cup�rer les param�tres qui sont des chiffres en int
			vector<Point> params;
			for(size_t i=2 ; i<parametres.size() ; i=i+2)
			{
				int valeur1;
				int valeur2;
				istringstream iss1( parametres[i] );
				istringstream iss2( parametres[i+1] );
				// convertir en un int
				iss1 >> valeur1;
				iss2 >> valeur2;
				params.push_back(Point(valeur1,valeur2));
			}

			CmdAjoutPL pl(modele,parametres[1],params,false);
			pl.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Param�tres invalides" << endl;
		}
	}
	else if (parametres[0] == OA)
	{
		//cout << "objet aggr�g�" << endl;

		//Pour que la commande soit valide, on doit avoir plus de 3 param�tres (au moins un EG):
		//OA Name EG1 EG2 ... EGn
		if (parametres.size() >=3 && CmdEstCorrecte(parametres, true))
		{
			//cout << "OK" << endl;

			vector<string> params;
			for(size_t i=2 ; i<parametres.size() ; i++)
			{
				params.push_back(parametres[i]);
			}

			CmdAjoutOA oa(modele,parametres[1],params,false);
			oa.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Param�tres invalides" << endl;
		}
	}


	return 0;
}
