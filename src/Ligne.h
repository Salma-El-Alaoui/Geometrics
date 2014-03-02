/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( LIGNE_H_ )
#define LIGNE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Point.h"
#include "EltGeo.h"
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------

class Ligne : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


	const vector<Point> & GetPoints ( )const;
    // Mode d'emploi :
    // Permet d'obtenir les 2 points de la ligne
    // Contrat :
    //

    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    // Déplace la ligne de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    virtual void ResetDeplace();

//------------------------------------------------- Surcharge d'opérateurs

    Ligne & operator=(const Ligne & uneLigne);

//-------------------------------------------- Constructeurs - destructeur


    Ligne ( const Ligne & uneLigne );
    // Mode d'emploi (constructeur de copie) :
    // Crée une ligne à partir de la ligne uneLigne
    // Contrat :
    //

    Ligne ( string unNom, long rx1, long ry1, long rx2, long ry2 );
    // Mode d'emploi :
    // Crée une ligne avec les paramètres donnés
    // Contrat :
    //

    virtual ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Polyligne * poly;

};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H_
