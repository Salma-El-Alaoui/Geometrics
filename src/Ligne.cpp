/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE
using namespace std;
//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


const vector<Point> & Ligne:: GetPoints ( )const
// Algorithme :
{
	return poly->GetPoints();

}//----- Fin de Méthode

void Ligne::Deplacer ( long dx, long dy )
// Algorithme :il suffit de déplacer les points de la polyligne
{
	if(!deplace)
	{
	poly->Deplacer(dx,dy);
	string cmd=poly->GetLigneCmd();
	string temp;
	temp=cmd.substr(2);
	ligneCmd="L"+temp;

	}

} //----- Fin de Méthode

void Ligne::ResetDeplace()
{
	deplace = false;
}


//------------------------------------------------- Surcharge d'opérateurs
Ligne & Ligne:: operator=(const Ligne & uneLigne)
{
	if (&uneLigne != this)
	{
		EltGeo::operator =(uneLigne);
		delete poly;
		poly=new Polyligne(uneLigne.nom, uneLigne.poly->GetPoints());
		*poly = *uneLigne.poly;

	}
	return *this;


}

//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & uneLigne ):EltGeo(uneLigne)
// Algorithme : a revoir, je ne suis pas très sure
{
	 poly=new Polyligne(uneLigne.nom, uneLigne.poly->GetPoints());
	*poly = *uneLigne.poly;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif


} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne ( string unNom, long rx1, long ry1, long rx2, long ry2 ):EltGeo(unNom)
// Algorithme :
//
{

	vector<Point>points;
	points.push_back(Point(rx1,ry1));
	points.push_back(Point(rx2,ry2));

	poly=new Polyligne(unNom,points);
	string cmd=poly->GetLigneCmd();
	string temp;
	temp=cmd.substr(2);
	ligneCmd="L"+temp;




#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif


} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
	delete poly;
	poly=NULL;

#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées







