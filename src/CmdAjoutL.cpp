/*************************************************************************
                           CmdAjoutL  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CmdAjoutL> (fichier CmdAjoutL.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutL.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CmdAjoutL::Executer (  )
// Algorithme :
//
{
	EltGeo * ligne=new Ligne(nom,x1,y1,x2,y2);
	if(modele->Ajouter(*ligne))
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

void CmdAjoutL::Undo ()
// Algorithme :
//
{
	modele->Delete(nom);

} //----- Fin de Méthode

void CmdAjoutL::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'op�rateurs
CmdAjoutL & CmdAjoutL::operator = ( const CmdAjoutL & uneCmdAjoutL )
// Algorithme :
//
{
	if (& uneCmdAjoutL != this)
	{
			Commande::operator =(uneCmdAjoutL);
			nom=uneCmdAjoutL.nom;
			x1=uneCmdAjoutL.x1;
			y1=uneCmdAjoutL.y1;
			x2=uneCmdAjoutL.x2;
			y2=uneCmdAjoutL.y2;

	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjoutL::CmdAjoutL ( const CmdAjoutL & uneCmdAjoutL ):CommandeHis(uneCmdAjoutL),nom(uneCmdAjoutL.nom),x1(uneCmdAjoutL.x1),y1(uneCmdAjoutL.y1),x2(uneCmdAjoutL.x2),y2(uneCmdAjoutL.y2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjoutL>" << endl;
#endif
} //----- Fin de CmdAjoutL (constructeur de copie)


CmdAjoutL::CmdAjoutL ( Modele * leModele, string unNom, long unX1, long unY1, long unX2, long unY2, bool his ):CommandeHis(leModele,his),nom(unNom),x1(unX1),y1(unY1),x2(unX2),y2(unY2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutL>" << endl;
#endif
} //----- Fin de CmdAjoutL


CmdAjoutL::~CmdAjoutL ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutL>" << endl;
#endif
} //----- Fin de ~CmdAjoutL


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

