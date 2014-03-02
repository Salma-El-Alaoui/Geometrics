/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CmdSuppression> (fichier CmdSuppression.h) ------
#if ! defined ( CMDSUPPRESSION_H_ )
#define CMDSUPPRESSION_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"
#include "EltGeo.h"
#include "ObjAgr.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef map <string, EltGeo*> TMapModele;
typedef TMapModele ::iterator ItM;
typedef map<string,vector<string> > TMapComposantsOA;
typedef TMapComposantsOA ::iterator ItComp;


//------------------------------------------------------------------------
// Rôle de la classe <CmdSuppression>
//
//
//------------------------------------------------------------------------

class CmdSuppression : public CommandeHis
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual bool Executer ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Undo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Redo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    CmdSuppression & operator = ( const CmdSuppression & unCmdSuppression );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdSuppression ( const CmdSuppression & unCmdSuppression );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdSuppression ( Modele * leModele,vector<string> nomselts);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdSuppression ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//---------------------------------------------------------------- Attributs protégés
    vector<string> nomsElts;
    vector<EltGeo*> anciensElts;
    bool undo;
    vector<ObjAgr*> anciensObjAgr;

};

//--------------------------- Autres définitions dépendantes de <CmdSuppression>

#endif // CMDSUPPRESSION_H_
