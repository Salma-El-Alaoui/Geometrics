/*************************************************************************
                           CmdMove  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CmdMove> (fichier CmdMove.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdMove.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

 bool CmdMove::Executer()
 {
	 if (modele->ElementExiste(nom))
	 {
		 //ancienElement=modele->GetElement(nom);
		 modele->GetElement(nom)->SetPremier();
		 modele->Deplacer(nom,x,y);
		 modele->GetElement(nom)->ResetPremier();

		 if (historiser)
		 {
			 cout << "OK" << endl;
			 cout << "#" << nom << " deplace" << endl;
			 historiser = false;
		 }
		 return 1;
	 }
	 else
	 {
		 cout<<"ERR"<<endl;
		 cout<<"#L'element "<< nom<< " n'existe pas "<<endl;
		 return 0;
	 }



 } //----- Fin de Méthode

 void CmdMove::Undo()
 {
	 if (modele->ElementExiste(nom))
	 {
		 long negativeX=-1*x;
		 long negativeY=-1*y;
		 modele->GetElement(nom)->SetPremier();
		 modele->Deplacer(nom,negativeX,negativeY);
		 modele->GetElement(nom)->ResetPremier();
	 }
	 else
	 {
		 cout<<"ERR"<<endl;
		 cout<<"#L'element "<< nom<< "n'existe pas "<<endl;
		 return;
	 }

 }//----- Fin de Méthode

 void CmdMove::Redo()
 {

	 Executer();

 }//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
CmdMove & CmdMove::operator = ( const CmdMove & uneCmdMove )
// Algorithme :
//
{
	if (& uneCmdMove != this)
	{
			Commande::operator =(uneCmdMove);
			nom=uneCmdMove.nom;
			x=uneCmdMove.x;
			y=uneCmdMove.y;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdMove::CmdMove ( const CmdMove & uneCmdMove ):CommandeHis(uneCmdMove),nom(uneCmdMove.nom),x(uneCmdMove.x),y(uneCmdMove.y)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdMove>" << endl;
#endif
} //----- Fin de CmdMove (constructeur de copie)


CmdMove::CmdMove ( Modele * leModele ,string nomObjet,long unX, long unY):CommandeHis(leModele,true),nom(nomObjet),x(unX),y(unY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdMove>" << endl;
#endif
} //----- Fin de CmdMove


CmdMove::~CmdMove ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdMove>" << endl;
#endif
} //----- Fin de ~CmdMove


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

