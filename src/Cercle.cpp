/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Cercle> (fichier Cercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>
#include <string>
#include<sstream>

//------------------------------------------------------ Include personnel
#include "Cercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const Point Cercle::GetCentre ( )const
{
	return centre;
} //----- Fin de Méthode

const long Cercle::GetRayon ( )const
{
	return rayon;
} //----- Fin de Méthode

void Cercle::Deplacer ( long rdx, long rdy )
{
	if(!deplace)
	{
	centre.Deplacer( rdx, rdy );
	ostringstream convert;
	convert <<"C"<<" "<<nom<<" "<<centre.GetX()<< " "<<centre.GetY()<<" "<<rayon<<endl;
	ligneCmd=convert.str();

	}

} //----- Fin de Méthode

void Cercle::ResetDeplace()
{
	deplace = false;
}



//------------------------------------------------- Surcharge d'opérateurs

Cercle & Cercle::operator =(const Cercle & unCercle)
{
	if (& unCercle != this)
	{
			EltGeo::operator =(unCercle);
			centre=unCercle.centre;
			rayon=unCercle.rayon;
	}
	return *this;
}


//-------------------------------------------- Constructeurs - destructeur

Cercle::Cercle ( const Cercle & unCercle ):EltGeo(unCercle),centre(unCercle.centre),rayon(unCercle.rayon)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif


} //----- Fin de Cercle (constructeur de copie


Cercle::Cercle ( string unNom, long rx, long ry, long rrayon ):EltGeo(unNom),centre(Point(rx,ry)),rayon(rrayon)
{

	ostringstream convert;
	convert <<"C"<<" "<<nom<<" "<<centre.GetX()<< " "<<centre.GetY()<<" "<<rayon<<endl;
	ligneCmd=convert.str();


#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif

} //----- Fin de Cercle


Cercle::~Cercle ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cercle>" << endl;
#endif
} //----- Fin de ~Cercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées





