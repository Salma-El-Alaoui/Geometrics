/*************************************************************************
                           ObjAgr  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <ObjAgr> (fichier ObjAgr.h) ------
#if ! defined ( OBJAGR_H_ )
#define OBJAGR_H_

//--------------------------------------------------- Interfaces utilisées

using namespace std;

#include <string>
#include <vector>
#include <map>
#include <set>
#include "Point.h"
#include "EltGeo.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef map <string, EltGeo*> TMapObjAgr;
typedef TMapObjAgr ::iterator It;


//------------------------------------------------------------------------
// Cette classe permet de représenter un ensemble de formes géométriques.
//------------------------------------------------------------------------

class ObjAgr : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    // Déplace l'objet aggrégé de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :.
    //

    void AjouterElement(EltGeo & element);
    // Mode d'emploi :
    //Cette méthode nous permet d'ajouter un element géométrique qui existe dans notre map objets
    // Contrat :
    //

    void SupprimerElement (string nomElement);
    // Mode d'emploi :
    //Cette méthode nous permet de supprimer un element géométrique de notre objet agrégé
   // Contrat :
   //

    void ResetDeplace();
    // Mode d'emploi :
    //A completer
    // Contrat :
    //

   TMapObjAgr & GetElements();
    // Mode d'emploi :
    // Getter de la map d'éléments géométriques que contient l'objet agrégé
    // Contrat :

   void AfficherElements();
   // Mode d'emploi :
   // Affiche les elements de notre objet agregé
   // Contrat :


//------------------------------------------------- Surcharge d'opérateurs

    ObjAgr & operator =(ObjAgr & ObjAgr );

//-------------------------------------------- Constructeurs - destructeur
    ObjAgr ( ObjAgr & unObjAgr );
    // Mode d'emploi (constructeur de copie) :
    // Crée un objet aggrégé à partir de l'objet aggrégé unObjAgr
    // Contrat :
    //

    ObjAgr ( string unNom, vector<string> desElements );
    // Mode d'emploi :
    // Crée un objet aggrégé dont le nom est unNom
    // Contrat :
    //

    virtual ~ObjAgr ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés

    vector<string> elements;
    TMapObjAgr objets;
    //le string représente le nom de chaque element géométrique, et le second est un pointeur vers cet element
    //géometrique

};

//--------------------------- Autres définitions dépendantes de <ObjAgr>

#endif // OBJAGR_H_
