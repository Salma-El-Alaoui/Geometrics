/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <Commande> (fichier Commande.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Commande.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Commande::Executer ( )
// Algorithme :
//
{
	// Méthode virtuelle pure, rien à mettre ici
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Commande & Commande::operator = ( const Commande & uneCommande )
// Algorithme :
//
{
	if(& uneCommande !=this)
	{
		if(modele)
		{
			delete modele;
		}

		modele = new Modele;
		*modele=*uneCommande.modele;
	}
	return *this;

} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Commande::Commande ( const Commande & uneCommande )
// Algorithme :
//
{
	if(uneCommande.modele)//s'il n'est pas null
	{
			modele=new Modele;
			*modele=*uneCommande.modele;
	}

#ifdef MAP
    cout << "Appel au constructeur de copie de <Commande>" << endl;
#endif
} //----- Fin de Commande (constructeur de copie)


Commande::Commande ( Modele * leModele ):modele(leModele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
} //----- Fin de Commande


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
