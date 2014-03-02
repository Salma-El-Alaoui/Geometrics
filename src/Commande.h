/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H_ )
#define COMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
// Cette classe est une classe abstraite qui concrétise les différentes commandes
//
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Executer ( ) =0;
    // Mode d'emploi :
    // Méthode virtuelle redéfinie selon le type de la commande historisable
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Commande ( Modele * modele );
    // Mode d'emploi :
    // Constructeur de la classe Commande qui récupère le modèle en cours
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

Modele* modele;


};

//--------------------------- Autres définitions dépendantes de <Commande>

#endif // COMMANDE_H_
