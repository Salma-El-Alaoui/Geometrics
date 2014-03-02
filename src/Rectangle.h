/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_

//--------------------------------------------------- Interfaces utilisées

#include <string>

#include "Point.h"
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Cette Classe représente un Rectangle à partir de deux sommets opposés par
// rapport à la diagonale
//------------------------------------------------------------------------

class Rectangle : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	const Point GetPoint1 ( )const;
    // Mode d'emploi :
    // Permet d'obtenir le point1
    // Contrat :
    //

	const Point GetPoint2 ( )const;
    // Mode d'emploi :
    // Permet d'obtenir le point2
    // Contrat :
    //

    virtual void Deplacer ( long rdx, long rdy );
    // Mode d'emploi :
    // Déplace le rectangle de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    virtual void ResetDeplace();

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & operator=(const Rectangle & unRectangle);

//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    // Crée un rectangle à partir du rectangle unRectangle
    // Contrat :
    //

    Rectangle ( string unNom, long rx1, long ry1, long rx2, long ry2 );
    // Mode d'emploi :
    // Crée un rectangle avec les paramètres donnés
    // Contrat :
    //

    virtual ~Rectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    Point point1;//point représentant un sommet du rectangle
    Point point2;//point représentant l'opposé du point1 par rapport
    			 // à la diagonale du rectangle.



};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // RECTANGLE_H_
