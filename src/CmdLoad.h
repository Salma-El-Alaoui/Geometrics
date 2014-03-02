/*************************************************************************
                           CmdLoad  -  description
                             -------------------
    d�but                : 15 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- Interface de la classe <CmdLoad> (fichier CmdLoad.h) ------
#if ! defined ( CMDLOAD_H_ )
#define CMDLOAD_H_

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include "Commande.h"
#include "CommandeHis.h"
#include "Point.h"
#include "EltGeo.h"
#include "Modele.h"
#include "CmdAjoutC.h"
#include "CmdAjoutR.h"
#include "CmdAjoutL.h"
#include "CmdAjoutPL.h"
#include "CmdAjoutOA.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <ctype.h>
#include <cstring>

//------------------------------------------------------------- Constantes
const string C = "C";
const string R = "R";
const string L = "L";
const string PL = "PL";
const string OA = "OA";
const string DELETE = "DELETE";
const string MOVE = "MOVE";
const string LIST = "LIST";
const string UNDO = "UNDO";
const string REDO = "REDO";
const string LOAD = "LOAD";
const string SAVE = "SAVE";
const string CLEAR = "CLEAR";
const string EXIT = "EXIT";

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CmdLoad>
//
//
//------------------------------------------------------------------------

class CmdLoad : public CommandeHis
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
    CmdLoad & operator = ( const CmdLoad & unCmdLoad );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdLoad ( const CmdLoad & unCmdLoad );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdLoad ( Modele * leModele, string nomFichier, bool his );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdLoad ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es
bool NomEstCorrect(string nom);
bool ParamEstCorrect(string param);
bool TypeEstCorrect(string type);
bool CmdEstCorrecte(vector<string> commande, bool estUnOA);
bool TraiterCommande(string cmd);


//----------------------------------------------------- Attributs prot�g�s
ifstream fichier;
vector<vector<string> > commandesChargees;
vector<string> commandesEnCours;
bool ok;

};

//--------------------------- Autres d�finitions d�pendantes de <CmdLoad>

#endif // CMDLOAD_H_
