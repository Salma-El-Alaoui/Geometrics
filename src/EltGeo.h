/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Interface de la classe <EltGeo> (fichier EltGeo.h) ------
#if ! defined ( ELTGEO_H_ )
#define ELTGEO_H_

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <set>
using namespace std;



//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Cette classe est une classe abstraite qui concrétise les différents éléments géométriques
//
//
//------------------------------------------------------------------------

class EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    virtual void Deplacer ( long dx, long dy )=0;
    // Mode d'emploi :
    // Méthode virtuelle redéfinie selon le type de l'élément géométrique
    // Contrat :
    //

    virtual string GetLigneCmd()const;
    // Mode d'emploi :
     // Getter de la ligne de commande de chaque élément géométrique.
     // Contrat :
     //

    const string & GetNom()const;
    // Mode d'emploi :
    //Getter du nom de l'element

    void SetDeplace();
    // Mode d'emploi :
    //Met l'attribut deplace a vrai

    virtual void ResetDeplace()=0;
    // Mode d'emploi :
    //Remet l'attribut deplace a faux

    const bool GetDeplace()const;
    //Getter de deplace

    void SetPremier();
    // Mode d'emploi :
    //Met l'attribut premier a vrai

    void ResetPremier();
    // Mode d'emploi :
    //Remet l'attribut premier a faux




//------------------------------------------------- Surcharge d'opérateurs
    EltGeo &operator =(const EltGeo &);

//-------------------------------------------- Constructeurs - destructeur
    EltGeo ( const EltGeo & unEltGeo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EltGeo (string unNom );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EltGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    string Convert(long i);
//----------------------------------------------------- Attributs protégés

    string nom;
    bool deplace;
    bool premier;
    string ligneCmd;


};

//--------------------------- Autres définitions dépendantes de <EltGeo>

#endif // ELTGEO_H_
