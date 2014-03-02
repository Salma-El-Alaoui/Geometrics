/*************************************************************************
                           CommandesManager  -  description
                             -------------------
    d�but                : 17 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CommandesManager> (fichier CommandesManager.h) ------
#if ! defined ( COMMANDESMANAGER_H_ )
#define COMMANDESMANAGER_H_
using namespace std;
//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "CommandeHis.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"
#include <vector>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CommandesManager>
//
//
//------------------------------------------------------------------------

class CommandesManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques


    void Ajouter (CommandeHis & laCommande);
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

    void ClearRedoCommandes();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    CommandesManager & operator = ( const CommandesManager & unCommandesManager );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandesManager ( const CommandesManager & unCommandesManager );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es


//----------------------------------------------------- Attributs prot�g�s

    vector<CommandeHis*> undoCommandes;
    vector<CommandeHis*> redoCommandes;

};

//--------------------------- Autres d�finitions d�pendantes de <CommandesManager>

#endif // COMMANDESMANAGER_H_
