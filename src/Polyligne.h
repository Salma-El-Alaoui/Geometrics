/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) ------
#if ! defined ( POLYLIGNE_H_ )
#define POLYLIGNE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>

#include "Point.h"
#include "EltGeo.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef vector<Point> TCollPoint;
//------------------------------------------------------------------------
// Cette Classe permet de représenter une polyligne à partir d'un ensemble
// de points. Une polyligne peut n'avoir aucun point.
//
//------------------------------------------------------------------------

class Polyligne : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



	 vector<Point> & GetPoints ( )const;
    // Mode d'emploi :
    // Permet d'obtenir la liste des points qui composent la polyligne s'ils existent
    // Contrat :
    //

    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    // Déplace la polyligne de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    virtual void ResetDeplace();


//------------------------------------------------- Surcharge d'opérateurs
    Polyligne & operator =(const Polyligne & unePolyligne );

//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( const Polyligne & unePolyligne );
    // Mode d'emploi (constructeur de copie) :
    // Crée une polyligne à partir de la polyligne unePolyligne
    // Contrat :
    //

    Polyligne ( string unNom, vector <Point> &);
    // Mode d'emploi :
    // Crée une polyligne dont le nom est rnom
    // Contrat :
    //

    virtual ~Polyligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void SetPolyligne(vector <Point> & points);
    // Mode d'emploi : Methode qu'on appelle dans
    // Remplit le vecteur de points de la polyligne à partir
    //d'un vecteur de points qu'il récupère en paramètre du constructeur
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés


    TCollPoint * pointsPolyligne;

};

//--------------------------- Autres définitions dépendantes de <Polyligne>

#endif // POLYLIGNE_H_
