/*************************************************************************
                           CmdAjoutC  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CmdAjoutC> (fichier CmdAjoutC.h) ------
#if ! defined ( CMDAJOUTC_H_ )
#define CMDAJOUTC_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"
#include "Cercle.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjoutC>
//
//
//------------------------------------------------------------------------

class CmdAjoutC : public CommandeHis
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    bool Executer ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Redo ();
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs
    CmdAjoutC & operator = ( const CmdAjoutC & unCmdAjoutC );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjoutC ( const CmdAjoutC & unCmdAjoutC );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjoutC ( Modele * leModele,string unNom, long unX, long unY, long unRayon, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutC ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

string nom;
long x;
long y;
long rayon;

};

//--------------------------- Autres définitions dépendantes de <CmdAjoutC>

#endif // CMDAJOUTC_H_
