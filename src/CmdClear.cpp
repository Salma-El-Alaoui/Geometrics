/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CmdClear> (fichier CmdClear.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdClear.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


bool CmdClear::Executer (  )
// Algorithme :
//
{
	//on vide les anciensElts
	anciensElts.clear();
	anciensObjAgr.clear();

	for(ItaC j=modele->GetObjetsAgr().begin();j!=modele->GetObjetsAgr().end();j++)
	{
		anciensObjAgr.push_back(j->second);
		modele->Supprimer(j->first);
	}

	for (ItC i=modele->GetEltsGeo().begin(); i!=modele->GetEltsGeo().end();i++)
	{
		if(!modele->ObjAgrExiste(i->first))//si ce n'est pas un objet agrégé
		{
			anciensElts.push_back(i->second);
			modele->Supprimer(i->first);
		}

	}

	if(historiser)
	{
		cout<<"OK"<<endl;
		cout<<"#Modele cleared"<<endl;
		historiser = false;
	}

	undo=false;
	return true;



} //----- Fin de Méthode

void CmdClear::Undo (  )
// Algorithme :
//
{
	for (size_t i=0;i<anciensElts.size();i++)
	{
		modele->Ajouter(*anciensElts[i]);
	}

	for (size_t i=0;i<anciensObjAgr.size();i++)
	{
			modele->AjouterAgr(*anciensObjAgr[i]);
	}
	undo=true;




} //----- Fin de Méthode

void CmdClear::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
CmdClear & CmdClear::operator = ( const CmdClear & uneCmdClear )
// Algorithme :
//
{
	if (& uneCmdClear != this)
	{
			Commande::operator =(uneCmdClear);
			undo=uneCmdClear.undo;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdClear::CmdClear ( const CmdClear & uneCmdClear):CommandeHis(uneCmdClear),undo(uneCmdClear.undo)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdClear>" << endl;
#endif
} //----- Fin de CmdClear (constructeur de copie)


CmdClear::CmdClear ( Modele * leModele):CommandeHis(leModele,true)
// Algorithme :
//
{
	undo=false;

#ifdef MAP
    cout << "Appel au constructeur de <CmdClear>" << endl;
#endif
} //----- Fin de CmdClear


CmdClear::~CmdClear( )
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

		anciensElts.clear();
		for(size_t j=0;j<anciensObjAgr.size();j++)
		{
			delete anciensObjAgr[j];
		}
		anciensObjAgr.clear();

	}
	//il faut compléter!
#ifdef MAP
    cout << "Appel au destructeur de <CmdClear>" << endl;
#endif
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

