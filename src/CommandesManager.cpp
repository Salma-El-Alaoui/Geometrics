/*************************************************************************
                           CommandesManager  -  description
                             -------------------
    d�but                : 17 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CommandesManager> (fichier CommandesManager.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <string>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandesManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void CommandesManager::Ajouter (CommandeHis & laCommande)
{
	if(laCommande.Executer())
	{
		undoCommandes.push_back(&laCommande);
	}
}

void CommandesManager::Undo ()
{
	if(undoCommandes.size()!=0)
	{
		int indexDernierElement = undoCommandes.size()-1;
		undoCommandes[indexDernierElement]->Undo();
		redoCommandes.push_back(undoCommandes[indexDernierElement]);
		undoCommandes.pop_back();
		cout << "OK" << endl;
		cout << "#Undone" << endl;
	}
	else
	{
		cout << "ERR" << endl;
		cout << "#Aucune commande a annuler" << endl;
	}
}

void CommandesManager::Redo ()
{
	if(redoCommandes.size()!=0)
	{
		int indexDernierElement = redoCommandes.size()-1;
		redoCommandes[indexDernierElement]->Redo();
		undoCommandes.push_back(redoCommandes[indexDernierElement]);
		redoCommandes.pop_back();
		cout << "OK" << endl;
		cout << "#Redone" << endl;
	}
	else
	{
		cout << "ERR" << endl;
		cout << "#Aucune commande a refaire" << endl;
	}
}

void CommandesManager::ClearRedoCommandes()
{
	for(size_t i=0; i<redoCommandes.size();i++)
	{
		delete redoCommandes[i];
	}
	redoCommandes.clear();
}


//------------------------------------------------- Surcharge d'op�rateurs
CommandesManager & CommandesManager::operator = ( const CommandesManager & unCommandesManager )
// Algorithme :
//
{
	if(& unCommandesManager !=this)
	{
		undoCommandes=unCommandesManager.undoCommandes;
		redoCommandes=unCommandesManager.redoCommandes;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandesManager::CommandesManager ( const CommandesManager & unCommandesManager ):undoCommandes(unCommandesManager.undoCommandes),redoCommandes(unCommandesManager.redoCommandes)
// Algorithme :
//
{


#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandesManager>" << endl;
#endif
} //----- Fin de CommandesManager (constructeur de copie)


CommandesManager::CommandesManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandesManager>" << endl;
#endif
} //----- Fin de CommandesManager


CommandesManager::~CommandesManager ( )
// Algorithme :
//
{
	for(size_t i=0; i<redoCommandes.size();i++)
		{
			delete redoCommandes[i];
		}
		redoCommandes.clear();

	for(size_t i=0; i<undoCommandes.size();i++)
	{
		delete undoCommandes[i];
	}
	redoCommandes.clear();


#ifdef MAP
    cout << "Appel au destructeur de <CommandesManager>" << endl;
#endif
} //----- Fin de ~CommandesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
