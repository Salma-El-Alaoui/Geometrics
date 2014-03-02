/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CmdSuppression> (fichier CmdSuppression.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSuppression.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


bool CmdSuppression::Executer (  )
// Algorithme :
//
{
	//on vide les anciensElts, ce n'est pas un leak parce que si on réexecute ça veut dire que modele pointe dessus
	anciensElts.clear();
	anciensObjAgr.clear();
	//on vérifie si tous les éléments sont bons
	for(size_t i=0;i<nomsElts.size();i++)
	{
			if(!modele->ElementExiste(nomsElts[i]))
			{
				cout<<"ERR"<<endl;
				cout<< "#L'element geometrique nomme "<<nomsElts[i]<<" n'existe pas."<<endl;
				return false;
			}
	}
	//si tous les �l�ments sont bons, on fait la suppression
	for(size_t i=0;i<nomsElts.size();i++)
	{
		if(modele->ElementExiste(nomsElts[i]))
		{
			if(modele->ObjAgrExiste(nomsElts[i]))//si c'est un objet agr�g�
			{
				//je le get puis je le supprime
				anciensObjAgr.push_back(modele->GetObjAgr(nomsElts[i]));
				modele->Supprimer(nomsElts[i]);
				if (historiser)
				{
					cout<<"#Element "<< nomsElts[i]<< " supprime"<<endl;
				}
			}
			else//si c'est un elt normal
			{
				anciensElts.push_back(modele->GetElement(nomsElts[i]));
				modele->Supprimer(nomsElts[i]);
				if (historiser)
				{
					cout<<"#Element "<< nomsElts[i]<< " supprime"<<endl;
				}
			}
		}
	}

	if (historiser)
	{
		cout<<"OK"<<endl;
		historiser = false;
	}

	undo=false;
	return true;


} //----- Fin de Méthode

void CmdSuppression::Undo (  )
// Algorithme :
//
{
	for (size_t i=0;i<anciensElts.size();i++)
	{
		modele->Ajouter(*anciensElts[i]);

		ItComp j=modele->GetCompOA().find(anciensElts[i]->GetNom());
		if(j!=modele->GetCompOA().end())
		{
			for(size_t k=0;k<j->second.size();k++)
			{
				//cout<<modele->GetObjAgr(j->second[k])->GetNom()<<endl;
				modele->GetObjAgr(j->second[k])->AjouterElement(*anciensElts[i]);
			}
		}

	}

	for(size_t i=0; i<anciensObjAgr.size();i++)
	{
		modele->AjouterAgr(*anciensObjAgr[i]);
	}


	undo=true;



} //----- Fin de Méthode

void CmdSuppression::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
CmdSuppression & CmdSuppression::operator = ( const CmdSuppression & uneCmdSuppression )
// Algorithme :
//
{
	if (& uneCmdSuppression != this)
	{
			Commande::operator =(uneCmdSuppression);
			nomsElts=uneCmdSuppression.nomsElts;
			undo=uneCmdSuppression.undo;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression ( const CmdSuppression & uneCmdSuppression ):CommandeHis(uneCmdSuppression),
																			nomsElts(uneCmdSuppression.nomsElts),undo(uneCmdSuppression.undo)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression (constructeur de copie)


CmdSuppression::CmdSuppression ( Modele * leModele,vector<string> noms ):CommandeHis(leModele,true),nomsElts(noms)
// Algorithme :
//
{
	undo=false;
#ifdef MAP
    cout << "Appel au constructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression


CmdSuppression::~CmdSuppression ( )
// Algorithme :
//
{
	if(undo)//si le undo est la dernière chose à avoir été faite,il ne faut pas faire de delete, modèle va s'en occuper
	{

	}
	else
	{
		for(size_t j=0;j<anciensElts.size();j++)
		{
			delete anciensElts[j];
		}
		//cout<<"OK"<<endl;
		anciensElts.clear();

		for(size_t j=0;j<anciensObjAgr.size();j++)
		{
			delete anciensObjAgr[j];
		}
		anciensObjAgr.clear();
	}


#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
