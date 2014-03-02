/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CmdSave> (fichier CmdSave.h) ------
#if ! defined ( CMDSAVE_H_ )
#define CMDSAVE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "Modele.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdSave>
//Cette classe implémente la commande save qui permet d'enregistrer
//les descriptions des éléments géométriques de notre modèle dans un fichier
//
//------------------------------------------------------------------------

class CmdSave : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	  bool Executer ();
	   // Mode d'emploi :
	   //Execute la commande save
	   // Contrat :
	   //


//------------------------------------------------- Surcharge d'opérateurs
    CmdSave & operator = ( const CmdSave & unCmdSave );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdSave ( const CmdSave & unCmdSave );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdSave ( Modele * leModele, string nomFic );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdSave ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

ofstream fichier;
string nomFichier;

};

//--------------------------- Autres définitions dépendantes de <CmdSave>

#endif // CMDSAVE_H_
