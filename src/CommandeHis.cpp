/*************************************************************************
                           CommandeHis  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CommandeHis> (fichier CommandeHis.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeHis.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CommandeHis::Undo ( )
// Algorithme :
//
{
	// Méthode virtuelle pure, rien à mettre ici
} //----- Fin de Méthode

void CommandeHis::Redo ( )
// Algorithme :
//
{
	// Méthode virtuelle pure, rien à mettre ici
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CommandeHis & CommandeHis::operator = ( const CommandeHis & uneCommandeHis )
// Algorithme :
//
{
	if (& uneCommandeHis != this)
	{
			Commande::operator =(uneCommandeHis);
			historiser = uneCommandeHis.historiser;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandeHis::CommandeHis ( const CommandeHis & uneCommandeHis ):Commande(uneCommandeHis),historiser(uneCommandeHis.historiser)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandeHis>" << endl;
#endif
} //----- Fin de CommandeHis (constructeur de copie)


CommandeHis::CommandeHis ( Modele * leModele , bool his ):Commande(leModele),historiser(his)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeHis>" << endl;
#endif
} //----- Fin de CommandeHis


CommandeHis::~CommandeHis ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeHis>" << endl;
#endif
} //----- Fin de ~CommandeHis


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

