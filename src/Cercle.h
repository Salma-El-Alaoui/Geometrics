/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include <string>
#include "Point.h"
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Cette classe permet de représenter un cercle à partir de son centre
//et de son rayon.
//
//------------------------------------------------------------------------

class Cercle : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


	const Point GetCentre ( )const;
    // Mode d'emploi :
    // Permet d'obtenir le centre
    // Contrat :
    //

	const long GetRayon ( )const;
    // Mode d'emploi :
    // Permet d'obtenir le rayon
    // Contrat :
    //

    virtual void Deplacer ( long rdx, long rdy );
    // Mode d'emploi :
    // Déplace le cercle de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    virtual void ResetDeplace();




//------------------------------------------------- Surcharge d'opérateurs
    Cercle & operator =(const Cercle & unCercle);

//-------------------------------------------- Constructeurs - destructeur
    Cercle ( const Cercle & unCercle );
    // Mode d'emploi (constructeur de copie) :
    // Crée un cercle à partir du cercle unCercle
    // Contrat :
    //

    Cercle ( string UnNom, long rx, long ry, long rrayon );
    // Mode d'emploi :
    // Crée un cercle avec les paramètres donnés
    // Contrat :
    //

    virtual ~Cercle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Point centre;
    long rayon;

};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_
