/*************************************************************************
                           CmdAjoutR  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CmdAjoutR> (fichier CmdAjoutR.h) ------
#if ! defined ( CMDAJOUTR_H_ )
#define CMDAJOUTR_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "CommandeHis.h"
#include "Rectangle.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CmdAjoutR>
//
//
//------------------------------------------------------------------------

class CmdAjoutR : public CommandeHis
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
    CmdAjoutR & operator = ( const CmdAjoutR & unCmdAjoutR );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjoutR ( const CmdAjoutR & unCmdAjoutR );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjoutR ( Modele * leModele, string unNom, long unX1, long unY1, long unX2, long unY2, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutR ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

    string nom;
    long x1;
    long y1;
    long x2;
    long y2;

};

//--------------------------- Autres d�finitions d�pendantes de <CmdAjoutR>

#endif // CMDAJOUTR_H_
