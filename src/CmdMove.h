/*************************************************************************
                           CmdMove  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CmdMove> (fichier CmdMove.h) ------
#if ! defined ( CMDMOVE_H_ )
#define CMDMOVE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeHis.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdMove>
//
//
//------------------------------------------------------------------------

class CmdMove : public CommandeHis
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
    CmdMove & operator = ( const CmdMove & unCmdMove );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdMove ( const CmdMove & unCmdMove );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdMove ( Modele * leModele, string nomObjet,long unX, long unY);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdMove ( );
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
//EltGeo * ancienElement;

};

//--------------------------- Autres définitions dépendantes de <CmdMove>

#endif // CMDMOVE_H_
