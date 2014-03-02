/*************************************************************************
                           CmdAjoutL  -  description
                             -------------------
    début                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CmdAjoutL> (fichier CmdAjoutL.h) ------
#if ! defined ( CMDAJOUTL_H_ )
#define CMDAJOUTL_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"
#include "Ligne.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjoutL>
//
//
//------------------------------------------------------------------------

class CmdAjoutL : public CommandeHis
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
    CmdAjoutL & operator = ( const CmdAjoutL & unCmdAjoutL );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjoutL ( const CmdAjoutL & unCmdAjoutL );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjoutL ( Modele * leModele, string unNom, long unX1, long unY1, long unX2, long unY2, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutL ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string nom;
    long x1;
    long y1;
    long x2;
    long y2;

};

//--------------------------- Autres définitions dépendantes de <CmdAjoutL>

#endif // CMDAJOUTL_H_
