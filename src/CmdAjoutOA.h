/*************************************************************************
                           CmdAjoutOA  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CmdAjoutOA> (fichier CmdAjoutOA.h) ------
#if ! defined ( CMDAJOUTOA_H_ )
#define CMDAJOUTOA_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "CommandeHis.h"
#include "ObjAgr.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CmdAjoutOA>
//
//
//------------------------------------------------------------------------

class CmdAjoutOA : public CommandeHis
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques


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


//------------------------------------------------- Surcharge d'op�rateurs
    CmdAjoutOA & operator = ( const CmdAjoutOA & unCmdAjoutOA );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjoutOA ( const CmdAjoutOA & unCmdAjoutOA );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjoutOA ( Modele * leModele, string unNom, vector<string> desElements, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutOA ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    string nom;
    vector<string> elements;

};

//--------------------------- Autres d�finitions d�pendantes de <CmdAjoutOA>

#endif // CMDAJOUTOA_H_
