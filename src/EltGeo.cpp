/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <EltGeo> (fichier EltGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE
using namespace std;
//-------------------------------------------------------- Include système
#include <iostream>
#include<sstream>
//------------------------------------------------------ Include personnel
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void EltGeo::Deplacer ( long dx, long dy )
{
	// Méthode virtuelle pure, rien à mettre ici
}

const string & EltGeo:: GetNom()const
{
	return nom;
}

void EltGeo::SetDeplace()
{
	deplace=true;
	//cout<<deplace<<" "<< nom<<endl;
}

void EltGeo::ResetDeplace()
{
	// Méthode virtuelle pure, rien à mettre ici
}

const bool EltGeo::GetDeplace()const
{
	return deplace;
}

string EltGeo::GetLigneCmd()const
{
	return ligneCmd;
}

void EltGeo::SetPremier()
{
	premier=true;
	//cout<<deplace<<" "<< nom<<endl;
}

void EltGeo::ResetPremier()
{
	premier = false;
}


//------------------------------------------------- Surcharge d'opérateurs
EltGeo & EltGeo::operator=(const EltGeo & unEltGeo)
{
	if(& unEltGeo !=this)
	{
		nom=unEltGeo.nom;
		deplace=unEltGeo.deplace;
		ligneCmd=unEltGeo.ligneCmd;
	}
	return *this;
}

//-------------------------------------------- Constructeurs - destructeur
EltGeo::EltGeo ( const EltGeo & unEltGeo )
// Algorithme :
//
{
	nom=unEltGeo.nom;
	deplace=unEltGeo.deplace;
	ligneCmd=unEltGeo.ligneCmd;

#ifdef MAP
    cout << "Appel au constructeur de copie de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo (constructeur de copie)


EltGeo::EltGeo (string unNom ):nom(unNom)
// Algorithme :
{
	deplace= false;
	premier=false;
	ligneCmd="";


#ifdef MAP
    cout << "Appel au constructeur de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo


EltGeo::~EltGeo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EltGeo>" << endl;
#endif
} //----- Fin de ~EltGeo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

string EltGeo::Convert(long i)
{
	string result;
	ostringstream convert;
	convert <<i;
	result = convert.str();
	return result;

}

