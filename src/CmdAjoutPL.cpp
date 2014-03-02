/*************************************************************************
                           CmdAjoutPL  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CmdAjoutPL> (fichier CmdAjoutPL.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutPL.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CmdAjoutPL::Executer (  )
// Algorithme :
//
{
	EltGeo * polyligne=new Polyligne(nom,points);
	if(modele->Ajouter(*polyligne))
	{
		if(historiser)
		{
			cout<<"OK"<<endl;
			cout<<"#Element ajoute: " << nom << endl;
			historiser = false;
		}
		return true;
	}
	else
	{
		cout<<"ERR"<<endl;
		cout<<"#Un element geometrique nomme " << nom << " existe deja" <<endl;
		return false;
	}



} //----- Fin de Méthode

void CmdAjoutPL::Undo ()
// Algorithme :
//
{
	modele->Delete(nom);

} //----- Fin de Méthode

void CmdAjoutPL::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'op�rateurs
CmdAjoutPL & CmdAjoutPL::operator = ( const CmdAjoutPL & uneCmdAjoutPL )
// Algorithme :
//
{
	if (& uneCmdAjoutPL != this)
	{
			Commande::operator =(uneCmdAjoutPL);
			nom=uneCmdAjoutPL.nom;
			points=uneCmdAjoutPL.points;

	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjoutPL::CmdAjoutPL ( const CmdAjoutPL & uneCmdAjoutPL ):CommandeHis(uneCmdAjoutPL),nom(uneCmdAjoutPL.nom),points(uneCmdAjoutPL.points)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjoutPL>" << endl;
#endif
} //----- Fin de CmdAjoutPL (constructeur de copie)


CmdAjoutPL::CmdAjoutPL ( Modele * leModele, string unNom, vector<Point> desPoints, bool his ):CommandeHis(leModele,his),nom(unNom),points(desPoints)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutPL>" << endl;
#endif
} //----- Fin de CmdAjoutPL


CmdAjoutPL::~CmdAjoutPL ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutPL>" << endl;
#endif
} //----- Fin de ~CmdAjoutPL


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

