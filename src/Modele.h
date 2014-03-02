/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <Modele> (fichier Modele.h) ------
#if ! defined ( MODELE_H_ )
#define MODELE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include "EltGeo.h"
#include "ObjAgr.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map <string, EltGeo*> TMapModele;
typedef map<string, ObjAgr*> TMapAgr;
typedef map<string,vector<string> > TMapComposantsOA;
typedef TMapModele ::iterator ItM;
typedef TMapModele::const_iterator ItC;
typedef TMapAgr::iterator ItA;
typedef TMapAgr::const_iterator ItaC;




//------------------------------------------------------------------------
// Rôle de la classe <Modele>
//Cette classe permet de gérer les éléments géométriques de notre modèle(figure)

//------------------------------------------------------------------------

class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	const map<string,EltGeo*> & GetEltsGeo ( )const;
    // Mode d'emploi :
    // Permet d'obtenir la liste des éléments géométriques qui composent le modèle
    // Contrat :
    //

	const map<string,ObjAgr *> & GetObjetsAgr()const;
	 // Mode d'emploi :
	 // Permet d'obtenir la liste des objets agrégés qui composent le modèle
	 // Contrat :
	  //

	vector<string> & GetNomsElts ( );
    // Mode d'emploi :
    // Permet d'obtenir la liste des noms des éléments géométriques qui composent le modèle
    // Contrat :
    //

    bool Ajouter (EltGeo & eg );
    // Mode d'emploi :
    // Ajoute l'élément géométrique eg à la map
    // Contrat :
    //

    bool AjouterAgr (ObjAgr & eg );
    // Mode d'emploi :
    // Ajoute l'objet agrégé à la map d'objets agrégé et à la map d'éléments géométriques.
    // Contrat :
    //

    void Supprimer (string nomEg );
    // Mode d'emploi :
    // Supprime l'élément géométrique eg des 2 map map(sans faire de delete de l'element)
    // Contrat :
    //

    void Delete(string nomEg);
    // Mode d'emploi :
    // Supprime l'élément géométrique eg des 2 map(en faisant un delete de l'element)
    // Contrat :
    //

    void Deplacer ( string nomEg, long dx, long dy );
    // Mode d'emploi :
    // Déplace l'élément géométrique de dx sur l'axe des abcisses et de dy sur l'axe des ordonnées
    // Contrat :
    //

    EltGeo *GetElement(string nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    ObjAgr * GetObjAgr(string nom);
    //Cette méthode est un getter d'un objet agrégé de notre modèle à partir de son nom.


    bool ElementExiste(string nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool ObjAgrExiste(string nom);

    void AfficherElements();
    // Mode d'emploi :
    // permet d'afficher les elements géométrique de notre modele.

    void AfficherObjetsAgr();
    // Mode d'emploi :
    // permet d'afficher les objets agregés de notre modèle.

    TMapComposantsOA & GetCompOA();
    // Mode d'emploi :
    //



//------------------------------------------------- Surcharge d'opérateurs
    Modele & operator =(const Modele & unModele);

//-------------------------------------------- Constructeurs - destructeur

    Modele (const Modele & unModele );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TMapModele eltsGeo;
    TMapAgr objetsAgr;
    vector<string> nomsElts;	// Pour conserver l'ordre chrolonogique de cr�ation des �l�ments
    TMapComposantsOA composantsOA;

};

//--------------------------- Autres définitions dépendantes de <Modele>

#endif // MODELE_H_
