/*************************************************************************
                           CmdAjoutOA  -  description
                             -------------------
    d�but                : 16 janv. 2014
    copyright            : (C) 2014 par Xav
*************************************************************************/

//---------- R�alisation de la classe <CmdAjoutOA> (fichier CmdAjoutOA.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutOA.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CmdAjoutOA::Executer (  )
// Algorithme :
//
{
	ObjAgr * oa=new ObjAgr(nom, elements);
	bool elementInexistant = false;

	for (size_t i=0 ; i<elements.size() ; i++)
	{
		if(!modele->ElementExiste(elements[i]))
		{
			elementInexistant = true;
			delete oa;
			return 0;
		}
		else
		{
			oa->AjouterElement(*modele->GetElement(elements[i]));
		}
	}

	if(!elementInexistant)
	{
		if(modele->AjouterAgr(*oa))
		{
			if(historiser)
			{
				cout<<"OK"<<endl;
				cout<<"#Element ajoute: " << nom << endl;
				historiser = false;
			}
			return 1;
		}
		else
		{
			cout<<"ERR"<<endl;
			cout<<"#Un element geometrique nomme " << nom << " existe deja" <<endl;
			return 0;
		}
	}
	else
	{
		cout<<"ERR"<<endl;
		cout<<"#Un des elements geometriques n'existe pas" <<endl;
		return 0;
	}


} //----- Fin de Méthode

void CmdAjoutOA::Undo ()
// Algorithme :
//
{
	modele->Delete(nom);

} //----- Fin de Méthode

void CmdAjoutOA::Redo (  )
// Algorithme :
//
{
	Executer();

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'op�rateurs
CmdAjoutOA & CmdAjoutOA::operator = ( const CmdAjoutOA & uneCmdAjoutOA )
// Algorithme :
//
{
	if (& uneCmdAjoutOA != this)
	{
			Commande::operator =(uneCmdAjoutOA);
			nom=uneCmdAjoutOA.nom;
			elements=uneCmdAjoutOA.elements;

	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjoutOA::CmdAjoutOA ( const CmdAjoutOA & uneCmdAjoutOA ):CommandeHis(uneCmdAjoutOA),nom(uneCmdAjoutOA.nom),elements(uneCmdAjoutOA.elements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjoutOA>" << endl;
#endif
} //----- Fin de CmdAjoutOA (constructeur de copie)


CmdAjoutOA::CmdAjoutOA ( Modele * leModele, string unNom, vector<string> desElements, bool his ):CommandeHis(leModele,his),nom(unNom),elements(desElements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutOA>" << endl;
#endif
} //----- Fin de CmdAjoutOA


CmdAjoutOA::~CmdAjoutOA ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutOA>" << endl;
#endif
} //----- Fin de ~CmdAjoutOA


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

