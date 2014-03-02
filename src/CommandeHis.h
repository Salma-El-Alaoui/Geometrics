/*************************************************************************
                           CommandeHis  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <CommandeHis> (fichier CommandeHis.h) ------
#if ! defined ( COMMANDEHIS_H_ )
#define COMMANDEHIS_H_

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include <string>
#include "Commande.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CommandeHis>
//
//
//------------------------------------------------------------------------

class CommandeHis : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    virtual void Undo ( ) = 0;
    // Mode d'emploi :
    // Méthode virtuelle redéfinie selon le type de la commande
    // Contrat :
    //

    virtual void Redo ( ) = 0;
    // Mode d'emploi :
    // Méthode virtuelle redéfinie selon le type de la commande
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    CommandeHis & operator = ( const CommandeHis & unCommandeHis );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeHis ( const CommandeHis & unCommandeHis );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeHis ( Modele * modele, bool his );
    // Mode d'emploi :
    // Constructeur de la classe Commande qui récupère le modèle en cours
    // Contrat :
    //

    virtual ~CommandeHis ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    bool historiser;

};

//--------------------------- Autres définitions dépendantes de <CommandeHis>

#endif // COMMANDEHIS_H_
