/*
 * Application.cpp
 *
 *  Created on: 14 janv. 2014
 *      Author: xrazanajat
 */





#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <ctype.h>
#include <cstring>
#include <map>
using namespace std;

#include "EltGeo.h"
#include "Point.h"
#include "Rectangle.h"
#include "Polyligne.h"
#include "ObjAgr.h"
#include "Cercle.h"
#include "Modele.h"
#include "Commande.h"
#include "CmdAjoutC.h"
#include "CmdAjoutR.h"
#include "CmdAjoutL.h"
#include "CmdAjoutPL.h"
#include "CmdAjoutOA.h"
#include "CmdClear.h"
#include "CmdMove.h"
#include "CommandeHis.h"
#include "CmdSuppression.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CommandesManager.h"


//Les constantes sont d�j� d�finies dans la classe CmdLoad
/*const string C = "C";
const string R = "R";
const string L = "L";
const string PL = "PL";
const string OA = "OA";
const string DELETE = "DELETE";
const string MOVE = "MOVE";
const string LIST = "LIST";
const string UNDO = "UNDO";
const string REDO = "REDO";
const string LOAD = "LOAD";
const string SAVE = "SAVE";
const string CLEAR = "CLEAR";
const string EXIT = "EXIT";*/


vector <string> parametres;
bool exit = false;
Modele * modele;
CommandesManager cm;

//Utilis� pour v�rifier que les noms commencent bien par une lettre
//et ne contiennent ensuite que des caract�res alphanum�riques.
// -> Renvoie 1 si le nom est corect, 0 sinon
bool NomEstCorrect(string nom)
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
bool ParamEstCorrect(string param)
{
	//cout << "trace: ParamEstCorrect( " << param << " )" << endl;

	//Conversion string en char* pour pouvoir utiliser isdigit
	//(savoir si les caract�res du param�tre sont bien des chiffres)
	char* cstr = new char [param.length()+1];
	strcpy (cstr, param.c_str());

	if (!isdigit(cstr[0]) && cstr[0]!='-')
	{
		return 0;
	}

	for (size_t i=1; i<strlen(cstr); i++)
	{
		if (!isdigit(cstr[i]))
		{
			return 0;
		}
	}
	delete[] cstr;
	return 1;
}


//Utilis� pour v�rifier que les param�tres des diff�rentes commandes sont corrects
//estUnOA est � false par d�faut, on le met � true uniquement dans le cas de l'ajout
//d'un OA (obj agr�g�) ou d'une suppression
// -> Renvoie 1 si la commande est correcte, 0 sinon
bool CmdEstCorrecte(vector<string> commande, bool estUnOA = false)
{
	//cout << "trace: CmdAjoutEstCorrecte( ... )" << endl;

	if (!NomEstCorrect(commande[1]))
	{
		return 0;
	}

	int longueur = commande.size();
	for (int i=2 ; i<longueur ; i++)
	{
		//Si ce n'est pas un OA/suppression -> on regarde si ce sont des param corrects
		//Si c'est un OA/suupression -> on regarde si ce sont des noms corrects
		//(m�me s'ils n'existent pas forc�ment)
		if ((!estUnOA && !ParamEstCorrect(commande[i])) || (estUnOA && !NomEstCorrect(commande[i])))
		{
			return 0;
		}
	}

	return 1;
}



bool TraiterCommande(string cmd)
{
	istringstream iss(cmd);
	string mot;

	while (getline( iss, mot, ' ' ))
	{
	    parametres.push_back(mot);
	}

	//D�t�ction de la commande demand�e
	if (parametres[0] == C)
	{
		//cout << "cercle " << endl;

		//Pour que la commande soit valide, on doit avoir 5 arguments:
		//C Name X Y rayon (avec rayon>0)
		if (parametres.size()==5 && CmdEstCorrecte(parametres))
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

			if(params[4]>0)
			{
				CmdAjoutC * c = new CmdAjoutC(modele,parametres[1],params[2],params[3],params[4],true);
				cm.Ajouter(*c);
			}
			else
			{
				cout << "ERR" << endl << "#Parametres invalides (Rayon negatif)" << endl;
			}
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == R)
	{
		//cout << "rectangle" << endl;

		//Pour que la commande soit valide, on doit avoir 6 arguments:
		//R Name X1 Y1 X2 Y2
		if (parametres.size() == 6 && CmdEstCorrecte(parametres))
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

			CmdAjoutR * r = new CmdAjoutR(modele,parametres[1],params[2],params[3],params[4],params[5],true);
			cm.Ajouter(*r);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == L)
	{
		//cout << "ligne" << endl;

		//Pour que la commande soit valide, on doit avoir 6 arguments:
		//L Name X1 Y1 X2 Y2
		if (parametres.size() == 6 && CmdEstCorrecte(parametres))
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

			CmdAjoutL * l = new CmdAjoutL(modele,parametres[1],params[2],params[3],params[4],params[5],true);
			cm.Ajouter(*l);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == PL)
	{
		//cout << "polyligne" << endl;

		//Pour que la commande soit valide, on doit avoir un nombre pair d'arguments (au moins 4):
		//PL Name X1 Y1 X2 Y2 ... Xn Yn
		if (parametres.size() >=4 && parametres.size()%2 == 0 && CmdEstCorrecte(parametres))
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

			CmdAjoutPL * pl = new CmdAjoutPL(modele,parametres[1],params,true);
			cm.Ajouter(*pl);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
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

			CmdAjoutOA * oa = new CmdAjoutOA(modele,parametres[1],params,true);
			cm.Ajouter(*oa);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == DELETE)
	{
		//cout << "delete" << endl;

		//Pour que la commande soit valide, on doit avoir au moins 2 param�tres:
		//DELETE EG1 EG2 ... EGn
		if (parametres.size() >= 2 && CmdEstCorrecte(parametres, true))
		{
			//cout << "OK" << endl;

			vector<string> params;
			for(size_t i=1 ; i<parametres.size() ; i++)
			{
				params.push_back(parametres[i]);
			}

			CmdSuppression * suppr = new CmdSuppression(modele,params);
			cm.Ajouter(*suppr);

		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == MOVE)
	{
		//cout << "move" << endl;

		//Pour que la commande soit valide, on doit avoir 4 arguments:
		//MOVE Name X1 Y1
		if (parametres.size() == 4 && CmdEstCorrecte(parametres))
		{
			//cout << "OK" << endl;

			//La map params permet de r�cup�rer les param�tres qui sont des chiffres en int
			map<int,int> paramsMove;
			for(size_t i=2 ; i<parametres.size() ; i++)
			{
				int valeur;
				istringstream iss( parametres[i] );
				// convertir en un int
				iss >> valeur;
				paramsMove[i] = valeur;
			}


			CmdMove * move = new CmdMove(modele,parametres[1],paramsMove[2],paramsMove[3]);
			cm.Ajouter(*move);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == LIST)
	{
		//cout << "list" << endl;

		//Pour que la commande soit valide, on doit avoir un seul argument:
		//LIST
		if (parametres.size() == 1)
		{
			//cout << "OK" << endl;
			modele->AfficherElements();
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == UNDO)
	{
		//cout << "undo" << endl;

		//Pour que la commande soit valide, on doit avoir un seul argument:
		//UNDO
		if (parametres.size() == 1)
		{
			//cout << "OK" << endl;
			cm.Undo();
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == REDO)
	{
		//cout << "redo" << endl;

		//Pour que la commande soit valide, on doit avoir un seul argument:
		//REDO
		if (parametres.size() == 1)
		{
			//cout << "OK" << endl;
			cm.Redo();
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == LOAD)
	{
		//cout << "load" << endl;

		//Pour que la commande soit valide, on doit avoir 2 arguments:
		//LOAD Filename
		if (parametres.size() == 2)
		{
			//cout << "OK" << endl;

			CmdLoad * load = new CmdLoad(modele, parametres[1],true);
			cm.Ajouter(*load);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == SAVE)
	{
		//cout << "save" << endl;

		//Pour que la commande soit valide, on doit avoir 2 arguments:
		//SAVE Filename
		if (parametres.size() == 2)
		{
			//cout << "OK" << endl;

			CmdSave save(modele,parametres[1]);
			save.Executer();
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == CLEAR)
	{
		//cout << "clear" << endl;

		//Pour que la commande soit valide, on doit avoir un seul argument:
		//CLEAR
		if (parametres.size() == 1)
		{
			//cout << "OK" << endl;

			CmdClear * clear = new CmdClear(modele);
			cm.Ajouter(*clear);
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else if (parametres[0] == EXIT)
	{
		//cout << "exit" << endl;

		//Pour que la commande soit valide, on doit avoir un seul argument:
		//EXIT
		if (parametres.size() == 1)
		{
			exit = true;
		}
		else
		{
			cout << "ERR" << endl << "#Parametres invalides" << endl;
		}
	}
	else
	{
		cout << "ERR" << endl << "#Commande invalide" << endl;
	}

	return exit;
}


int main()
{
	modele=new Modele;

	while (!exit)
	{
		string cmd = "";
		parametres.clear();
		while (cmd == "")
		{
			getline(cin, cmd);
		}

		exit = TraiterCommande(cmd);

		//Si la derni�re commande effectu�e n'est est historisable, on vide le vecteur de commandes redo.
		if( parametres[0]!=UNDO && parametres[0]!=REDO && parametres[0]!=SAVE && parametres[0]!=LIST )
		{
			cm.ClearRedoCommandes();
		}
	}

	delete modele;
	return 0;
}
