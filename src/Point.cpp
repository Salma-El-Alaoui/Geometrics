/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) -------

//---------------------------------------------------------------- INCLUDE
using namespace std;
//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Point::Deplacer ( long dx, long dy )
{
	x += dx;
	y += dy;
}

const int Point ::GetX()const
{
	return x;
}

const int Point ::GetY()const
{
	return y;
}

//------------------------------------------------- Surcharge d'opérateurs

Point & Point :: operator=(const Point & unPoint)
{
	if(&unPoint !=this)//adresses mémoires différentes
	{
		x=unPoint.x;
		y=unPoint.y;
	}
	return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint ):x(unPoint.x),y(unPoint.y)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif

} //----- Fin de Point (constructeur de copie)


Point::Point ( long rx, long ry ):x(rx),y(ry)
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif


} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées



