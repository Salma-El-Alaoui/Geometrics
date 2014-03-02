/*************************************************************************
                           ObjAgr  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <ObjAgr> (fichier ObjAgr.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

#include <string>

//------------------------------------------------------ Include personnel
#include "ObjAgr.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void ObjAgr::Deplacer ( long dx, long dy )
// Algorithme :
{

	for (It i= objets.begin(); i!=objets.end();i++)
	{

		if(!(i->second->GetDeplace()))
		{
			//cout<<i->second->GetDeplace()<<" " <<i->second->GetNom()<<endl;
			i->second->Deplacer(dx,dy);
			i->second->SetDeplace();
		}

	}

	if(premier)
	{
		for (It i= objets.begin(); i!=objets.end();i++)
		{
			i->second->ResetDeplace();
		}
	}

}//----- Fin de Méthode

void ObjAgr::AjouterElement(EltGeo & element)
// Algorithme
{
	string nomObjet=element.GetNom();
	objets[nomObjet]= &element;
	ostringstream convert;

		convert <<"OA"<<" "<<nom;
		//ligneCmd=convert.str();
		for (It i= objets.begin(); i!=objets.end();i++)
	   	{
		   //ligneCmd = ligneCmd + " " + i->first;
			convert << " " << i->first;
	   	}
		convert << endl;
		ligneCmd=convert.str();


}//----- Fin de Méthode

void ObjAgr :: SupprimerElement(string nomElement)
// Algorithme
{
   It element = objets.find(nomElement);
   if (element!= objets.end())
   {
	   objets.erase(element);
	}

	ostringstream convert;
	convert <<"OA"<<" "<<nom;
	//ligneCmd=convert.str();
	for (It i= objets.begin(); i!=objets.end();i++)
   	{
	   //ligneCmd = ligneCmd + " " + i->first;
		convert << " " << i->first;
   	}
	convert << endl;
	ligneCmd=convert.str();


}//----- Fin de Méthode


void ObjAgr::ResetDeplace()
{
	for (It i= objets.begin(); i!=objets.end();i++)
	{
		i->second->ResetDeplace();
	}
	deplace = false;

}//----- Fin de Méthode

TMapObjAgr & ObjAgr::GetElements()
{
	return objets;
}

void ObjAgr :: AfficherElements()
{
	cout<<"elements de l'oa"<<endl;
	for (It i=objets.begin(); i!=objets.end();i++)
	{
		cout<<i->first<<endl;
	}
}


//------------------------------------------------- Surcharge d'opérateurs

ObjAgr & ObjAgr :: operator =(ObjAgr & unObjAgr )
{
	if (& unObjAgr != this)
		{
			EltGeo::operator =(unObjAgr);
			for (It i =unObjAgr.objets.begin(); i != unObjAgr.objets.end();i++)
			//pourquoi cette erreur?
			{
					string first=i->first;
					EltGeo * second=i->second;
					objets.insert(make_pair(first,second));
			}

		}
	return *this;
}


//-------------------------------------------- Constructeurs - destructeur
ObjAgr::ObjAgr (ObjAgr & unObjAgr ):EltGeo(unObjAgr)
// Algorithme :
{
	for (It i =unObjAgr.objets.begin(); i != unObjAgr.objets.end();i++)
	//pourquoi cette erreur?
	{
		string first=i->first;
		EltGeo * second=i->second;
		objets.insert(make_pair(first,second));
	}

#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjAgr>" << endl;
#endif

} //----- Fin de ObjAgr (constructeur de copie)


ObjAgr::ObjAgr ( string unNom, vector<string> desElements ):EltGeo(unNom),elements(desElements)
// Algorithme :
{
	ostringstream convert;
	convert <<"OA"<<" "<<nom;
	for( size_t i=0 ; i<elements.size() ; i++)
	{
		convert << " " << elements[i];
	}
	convert << endl;
	ligneCmd=convert.str();

#ifdef MAP
    cout << "Appel au constructeur de <ObjAgr>" << endl;
#endif

} //----- Fin de ObjAgr


ObjAgr::~ObjAgr ( )
// Algorithme :

{
	objets.clear();

#ifdef MAP
    cout << "Appel au destructeur de <ObjAgr>" << endl;
#endif
} //----- Fin de ~ObjAgr


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
