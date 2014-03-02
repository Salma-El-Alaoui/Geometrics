/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : 13 janv. 2014
    copyright            : (C) 2014 par xrazanajat
*************************************************************************/

//---------- Réalisation de la classe <CmdSave> (fichier CmdSave.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "CmdSave.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool CmdSave::Executer (  )
// Algorithme :
//
{
	typedef map <string, EltGeo*> TMapModele;
	typedef TMapModele::const_iterator ItC;
	vector<string>temp=modele->GetNomsElts();

	for (size_t i=0;i<temp.size();i++)
	{
		ItC element = modele->GetEltsGeo().find(temp[i]);
		fichier << element->second->GetLigneCmd();
	}

	cout<< "OK" << endl;
	cout<< "#Fichier " << nomFichier << " cree." << endl;
	return true;
} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
CmdSave & CmdSave::operator = ( const CmdSave & uneCmdSave )
// Algorithme :
//
{
	if (& uneCmdSave != this)
	{
			Commande::operator =(uneCmdSave);
			//fichier=uneCmdSave.fichier;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdSave::CmdSave ( const CmdSave & uneCmdSave ):Commande(uneCmdSave)
// Algorithme :
//
{
	//fichier=uneCmdSave.fichier;
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdSave>" << endl;
#endif
} //----- Fin de CmdSave (constructeur de copie)


CmdSave::CmdSave ( Modele * leModele,string nomFic ):Commande(leModele),fichier(nomFic.c_str()),nomFichier(nomFic)
// Algorithme :
//
{
	if(fichier.fail())
	{
		cout<<"ERR"<<endl;
		cout<<"#Erreur sur l'ouverture en �criture de "<< nomFic <<"."<<endl;
	}

#ifdef MAP
    cout << "Appel au constructeur de <CmdSave>" << endl;
#endif
} //----- Fin de CmdSave


CmdSave::~CmdSave ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSave>" << endl;
#endif
} //----- Fin de ~CmdSave


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
