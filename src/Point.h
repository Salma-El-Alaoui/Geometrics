/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//--------------------------------------------------- Interfaces utilisées

#include <string>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    // Déplace le point de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    const int GetX()const;
    // getter pour l'abcisse du point.

    const int GetY()const;
    //getter pour l'ordonnée du point.


//------------------------------------------------- Surcharge d'opérateurs
    Point & operator =(const Point & unPoint);


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point& unPoint );
    // Mode d'emploi (constructeur de copie) :
    // Crée un point de mêmes coordonnées que le point unPoint;
    // Contrat :
    //

    Point ( long rx, long ry );
    // Mode d'emploi :
    // Crée un point ayant pour coordonnées (rx,ry)
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    long x;
    long y;

};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_
