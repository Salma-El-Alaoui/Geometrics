/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) -------

//---------------------------------------------------------------- INCLUDE
using namespace std;
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Point> & Polyligne::GetPoints (  )const
// Algorithme: avec une référence il ne faut pas retourner de null,donc il faut
//gérer l'utilisation après.

{
			return *pointsPolyligne;


} //----- Fin de Méthode


void Polyligne::Deplacer ( long dx, long dy )
// Algorithme :on déplace chaque point de la polyligne.
{
	if(!deplace)
	{
		if(pointsPolyligne)//on ne déplace que s'il n'est pas NULL
		{
				for(size_t i=0;i<pointsPolyligne->size();i++)
				{
					pointsPolyligne->at(i).Deplacer(dx,dy);
				}
		}
		ostringstream convert;
		convert <<"PL"<<" "<<nom;
		for (size_t i =0; i<pointsPolyligne->size(); i++)
		{
			convert<<" "<<pointsPolyligne->at(i).GetX()<<" "<<pointsPolyligne->at(i).GetY();

		}
		convert<<endl;
		ligneCmd=convert.str();
	}

} //----- Fin de Méthode

void Polyligne::ResetDeplace()
{
	deplace = false;
}

//------------------------------------------------- Surcharge d'opérateurs

Polyligne & Polyligne :: operator =(const Polyligne & unePolyligne)
{
	if (& unePolyligne != this)
	{
		EltGeo::operator =(unePolyligne);

		if(pointsPolyligne)
		{
			delete pointsPolyligne;

		}
		pointsPolyligne = new TCollPoint;
		for(size_t i=0; i<unePolyligne.pointsPolyligne->size();i++)
		{
			pointsPolyligne->push_back(unePolyligne.pointsPolyligne->at(i));
		}

	}
	return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unePolyligne ):EltGeo(unePolyligne)
// Algorithme :
{
	if(unePolyligne.pointsPolyligne)//s'il n'est pas null
	{
		pointsPolyligne=new TCollPoint;
		for (size_t i =0; i<unePolyligne.pointsPolyligne->size(); i++)
		{
			pointsPolyligne->push_back(unePolyligne.pointsPolyligne->at(i));
		}
	}

#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif

} //----- Fin de Polyligne (constructeur de copie)


Polyligne::Polyligne ( string unNom, vector <Point> & points ):EltGeo(unNom)
// Algorithme :
//
{
	pointsPolyligne=NULL;
	SetPolyligne(points);

	ostringstream convert;
	convert <<"PL"<<" "<<nom;
	for (size_t i =0; i<pointsPolyligne->size(); i++)
	{
		convert<<" "<<pointsPolyligne->at(i).GetX()<<" "<<pointsPolyligne->at(i).GetY();

	}
	convert << endl;
	ligneCmd=convert.str();


#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif

} //----- Fin de Polyligne


Polyligne::~Polyligne ( )
// Algorithme :
//
{
	if(pointsPolyligne)
	{
		delete pointsPolyligne;
		pointsPolyligne=NULL;
	}

#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
} //----- Fin de ~Polyligne


//------------------------------------------------------------------ PRIVE

void Polyligne::SetPolyligne(vector<Point> & points)
//Algorithme
{
	if(!pointsPolyligne)//il doit être null pour qu'on puisse le modifier
	{
		pointsPolyligne=new TCollPoint;
		for(size_t i=0;i<points.size();i++)
		{
			pointsPolyligne->push_back(points.at(i));
		}
	}

}//----- Fin de Méthode

//----------------------------------------------------- Méthodes protégées

