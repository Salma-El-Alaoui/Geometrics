/*************************************************************************
                           CmdAjoutC  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CmdAjoutC> (fichier CmdAjoutC.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutC.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool CmdAjoutC::Executer (  )
// Algorithme :
//
{
	EltGeo * cercle=new Cercle(nom,x,y,rayon);
	if(modele->Ajouter(*cercle))
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

void CmdAjoutC::Undo ()
// Algorithme :
//
{
	modele->Delete(nom);

} //----- Fin de Méthode

void CmdAjoutC::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CmdAjoutC & CmdAjoutC::operator = ( const CmdAjoutC & uneCmdAjoutC )
// Algorithme :
//
{
	if (& uneCmdAjoutC != this)
	{
			Commande::operator =(uneCmdAjoutC);
			nom=uneCmdAjoutC.nom;
			x=uneCmdAjoutC.x;
			y=uneCmdAjoutC.y;
			rayon=uneCmdAjoutC.rayon;

	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjoutC::CmdAjoutC ( const CmdAjoutC & uneCmdAjoutC ):CommandeHis(uneCmdAjoutC),nom(uneCmdAjoutC.nom),x(uneCmdAjoutC.x),
																		y(uneCmdAjoutC.y),rayon(uneCmdAjoutC.rayon)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjoutC>" << endl;
#endif
} //*/

CmdAjoutC::CmdAjoutC ( Modele * leModele,string unNom, long unX, long unY, long unRayon, bool his ):CommandeHis(leModele,his),
																		nom(unNom),x(unX),y(unY),rayon(unRayon)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutC>" << endl;
#endif
} //----- Fin de CmdAjoutC


CmdAjoutC::~CmdAjoutC ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutC>" << endl;
#endif
} //----- Fin de ~CmdAjoutC


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées




