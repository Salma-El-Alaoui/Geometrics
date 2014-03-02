/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CmdClear> (fichier CmdClear.h) ------
#if ! defined ( CMDCLEAR_H_ )
#define CMDCLEAR_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"
#include "EltGeo.h"
#include "ObjAgr.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map <string, EltGeo*> TMapModele;
typedef map<string, ObjAgr*> TMapAgr;
typedef TMapModele::const_iterator ItC;
typedef TMapAgr::const_iterator ItaC;


//------------------------------------------------------------------------
// Rôle de la classe <CmdClear>
//
//
//------------------------------------------------------------------------

class CmdClear : public CommandeHis
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
    CmdClear & operator = ( const CmdClear & unCmdClear );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdClear ( const CmdClear & unCmdClear );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdClear ( Modele * leModele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ CmdClear ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    vector<EltGeo*> anciensElts;
    vector<ObjAgr *> anciensObjAgr;
    bool undo;

};

//--------------------------- Autres définitions dépendantes de <CmdSuppression>

#endif // CMDCLEAR_H_
