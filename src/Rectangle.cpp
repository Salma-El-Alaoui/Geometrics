/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE
using namespace std;
//-------------------------------------------------------- Include système
#include <iostream>
#include<sstream>
//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const Point Rectangle::GetPoint1 ( )const
{
	return point1;

} //----- Fin de Méthode

const Point Rectangle::GetPoint2 ( )const
{
	return point2;

} //----- Fin de Méthode

void Rectangle::Deplacer ( long rdx, long rdy )
{
	if (!deplace)
	{
		point1.Deplacer( rdx, rdy );
		point2.Deplacer( rdx, rdy );
		ostringstream convert;
		convert <<"R"<<" "<<nom<<" "<<point1.GetX()<<" "<<point1.GetY()<<" "<<point2.GetX()<<" "<<point1.GetY()<<endl;
		ligneCmd=convert.str();


	}

} //----- Fin de Méthode

void Rectangle::ResetDeplace()
{
	deplace = false;
}

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & Rectangle:: operator =(const Rectangle & unRectangle)
{
	if (& unRectangle !=this)
	{
		EltGeo::operator=(unRectangle);//appel de la surcharge de l'ancêtre
	}
	return *this;

}

//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ): EltGeo(unRectangle),
						point1(unRectangle.point1),point2(unRectangle.point2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif


} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( string unNom, long rx1, long ry1, long rx2, long ry2 ):EltGeo(unNom),
						point1(Point(rx1,ry1)),point2(Point(rx2,ry2))
// Algorithme :
//
{

		ostringstream convert;
		convert <<"R"<<" "<<nom<<" "<<point1.GetX()<<" "<<point1.GetY()<<" "<<point2.GetX()<<" "<<point1.GetY()<<endl;
		ligneCmd=convert.str();


#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif


} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées



