/*************************************************************************
                           CmdAjoutR  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CmdAjoutR> (fichier CmdAjoutR.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutR.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CmdAjoutR::Executer (  )
// Algorithme :
//
{
	EltGeo * rectangle=new Rectangle(nom,x1,y1,x2,y2);
	if(modele->Ajouter(*rectangle))
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

void CmdAjoutR::Undo ()
// Algorithme :
//
{
	modele->Delete(nom);

} //----- Fin de Méthode

void CmdAjoutR::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'op�rateurs
CmdAjoutR & CmdAjoutR::operator = ( const CmdAjoutR & uneCmdAjoutR )
// Algorithme :
//
{
	if (& uneCmdAjoutR != this)
	{
			Commande::operator =(uneCmdAjoutR);
			nom=uneCmdAjoutR.nom;
			x1=uneCmdAjoutR.x1;
			y1=uneCmdAjoutR.y1;
			x2=uneCmdAjoutR.x2;
			y2=uneCmdAjoutR.y2;

	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjoutR::CmdAjoutR ( const CmdAjoutR & uneCmdAjoutR ):CommandeHis(uneCmdAjoutR),nom(uneCmdAjoutR.nom),x1(uneCmdAjoutR.x1),y1(uneCmdAjoutR.y1),x2(uneCmdAjoutR.x2),y2(uneCmdAjoutR.y2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjoutR>" << endl;
#endif
} //----- Fin de CmdAjoutR (constructeur de copie)


CmdAjoutR::CmdAjoutR ( Modele * leModele, string unNom, long unX1, long unY1, long unX2, long unY2, bool his ):CommandeHis(leModele,his),nom(unNom),x1(unX1),y1(unY1),x2(unX2),y2(unY2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutR>" << endl;
#endif
} //----- Fin de CmdAjoutR


CmdAjoutR::~CmdAjoutR ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutR>" << endl;
#endif
} //----- Fin de ~CmdAjoutR


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

