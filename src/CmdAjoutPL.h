/*************************************************************************
                           CmdAjoutPL  -  description
                             -------------------
    début                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CmdAjoutPL> (fichier CmdAjoutPL.h) ------
#if ! defined ( CMDAJOUTPL_H_ )
#define CMDAJOUTPL_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"
#include "Polyligne.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjoutPL>
//
//
//------------------------------------------------------------------------

class CmdAjoutPL : public CommandeHis
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
    CmdAjoutPL & operator = ( const CmdAjoutPL & unCmdAjoutPL );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjoutPL ( const CmdAjoutPL & unCmdAjoutPL );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjoutPL ( Modele * leModele, string unNom, vector<Point> desPoints, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutPL ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string nom;
    vector<Point> points;

};

//--------------------------- Autres définitions dépendantes de <CmdAjoutPL>

#endif // CMDAJOUTPL_H_
