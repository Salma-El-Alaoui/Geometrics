/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 23 déc. 2013
    copyright            : (C) 2013 par Xav
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Modele.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Modele :: Ajouter(EltGeo & eg)
// Algorithme :
//
{
	string nomObjet=eg.GetNom();
	ItM element = eltsGeo.find(nomObjet);
	if (element== eltsGeo.end())//si il n'y a pas un élément géometrique du même nom
	{
		eltsGeo[nomObjet]= &eg;
		nomsElts.push_back(nomObjet);
		return true;
	}
	else
	{
		return false;
	}


}//----- Fin de Méthode

bool Modele :: AjouterAgr(ObjAgr & eg)
// Algorithme :pour ajouter un objet agregé, on l'ajoute dans la map d'objet agrégés et dans la
//map d'éléments géométriques.
{
	string nomObjet=eg.GetNom();
	if (Ajouter(eg)) //si il n'y a pas un élément géometrique du même nom
	{
		objetsAgr[nomObjet]=&eg;
		return true;
	}
	else
	{
		return false;
	}


}//----- Fin de Méthode


EltGeo * Modele::GetElement(string nom)
//Algorithme
{
	ItM element = eltsGeo.find(nom);
	if (element != eltsGeo.end())
	{
		return element->second;
	}

}//----- Fin de Méthode

ObjAgr * Modele::GetObjAgr(string nom)
//Algorithme
{
	ItA element = objetsAgr.find(nom);
	if (element != objetsAgr.end())
	{
		return element->second;
	}

}//----- Fin de Méthode

vector<string> & Modele::GetNomsElts()
//Algorithme
{

	return nomsElts;

}//----- Fin de Méthode

bool Modele::ElementExiste(string nom)
//Algorithme
{
	ItM element = eltsGeo.find(nom);
	if (element != eltsGeo.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}//----- Fin de Méthode

bool Modele::ObjAgrExiste(string nom)
//Algorithme
{
	ItA element1 = objetsAgr.find(nom);
	if (element1!= objetsAgr.end())// si c'est un objet agrégé, on n'oublie pas de le supprimer de la 2ème map
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Modele ::Delete(string nomEg)
// Algorithme :
//on cherche l'éléments géométrique dans la map d'éléments géométriques.On parcourt notre map d'objets agrégés, et pour chaque
//objet, on vérifie si l'eg qu'on veut supprimer lui appartient. Si oui, on le supprime dans cet objet agrégé.Ensuite on supprime
//notre eg de la map d'éléments géométriques et de la map d'objets agrégés(si c'est un objet agrégé).
{
		ItM element = eltsGeo.find(nomEg);
		if (element!= eltsGeo.end())
		{
			//je supprime la mémoire allouée à cet élément et je le supprime de la map d'éléments géométrique

			delete element->second;
			element->second=NULL;
			eltsGeo.erase(element);
			size_t c=0;
			while(c!=nomsElts.size()&& nomsElts[c]!=nomEg )
			{
				c++;
			}

			nomsElts.erase(nomsElts.begin()+c);

			for(ItA i = objetsAgr.begin();i!=objetsAgr.end();i++)
			{
				ObjAgr * objetA=i->second;
				ItM j=objetA->GetElements().find(nomEg);
				if(j!=objetA->GetElements().end())//si l'�l�ment g�om�trique appartient à un objet agreg�
				{
					objetA->SupprimerElement(nomEg);
				}
			}
		}

		ItA element1 = objetsAgr.find(nomEg);
		if (element1!= objetsAgr.end())// si c'est un objet agr�g�, on n'oublie pas de le supprimer de la 2ème map
		{
			objetsAgr.erase(element1);
		}

}//----- Fin de Méthode

void Modele ::Supprimer(string nomEg)
// Algorithme :
//similaire � la m�thode delete mais sans delete du pointeur
{
		ItM element = eltsGeo.find(nomEg);
		if (element!= eltsGeo.end())
		{
			//je le supprime de la map d'�l�ments g�om�triques

			eltsGeo.erase(element);
			size_t c=0;
			while(c!=nomsElts.size()&& nomsElts[c]!=nomEg )
			{
				c++;
			}

			nomsElts.erase(nomsElts.begin()+c);

			vector<string> elts;
			for(ItA i = objetsAgr.begin();i!=objetsAgr.end();i++)
			{
				ObjAgr * objetA=i->second;
				ItM j=objetA->GetElements().find(nomEg);
				if(j!=objetA->GetElements().end())//si l'�l�ment g�om�trique appartient à un objet agregé
				{
					elts.push_back(objetA->GetNom());
					objetA->SupprimerElement(nomEg);
				}
			}
			composantsOA[nomEg] = elts;
		}

		ItA element1 = objetsAgr.find(nomEg);
		if (element1!= objetsAgr.end())// si c'est un objet agrégé, on n'oublie pas de le supprimer de la 2ème map
		{
			objetsAgr.erase(element1);
		}

}//----- Fin de Méthode

void Modele::Deplacer( string nomEg, long dx, long dy )
{
	ItM element = eltsGeo.find(nomEg);
	if (element!= eltsGeo.end())
	{
		element->second->Deplacer(dx,dy);
	}

}//----- Fin de Méthode

const map<string,EltGeo*> & Modele:: GetEltsGeo ( )const
{
	return eltsGeo;

}//----- Fin de Méthode

const map<string,ObjAgr *> & Modele:: GetObjetsAgr ( )const
{
	return objetsAgr;

}//----- Fin de Méthode

void Modele::AfficherElements()
{
	//cout<<"Les eg de modele"<<endl;
	for (ItM i=eltsGeo.begin(); i!=eltsGeo.end();i++)
	{
		//cout<<i->first<<endl;
		cout<<i->second->GetLigneCmd();
	}
}//----- Fin de Méthode

void Modele::AfficherObjetsAgr()
{
	cout<<"Les oa de modele"<<endl;
	for (ItA i=objetsAgr.begin(); i!=objetsAgr.end();i++)
	{
			cout<<i->first<<endl;
	}
}//----- Fin de Méthode

TMapComposantsOA & Modele::GetCompOA()
{
	return composantsOA;
}

//------------------------------------------------- Surcharge d'opérateurs
Modele & Modele::operator=(const Modele & unModele)
{
	if (& unModele != this)
	{
		eltsGeo.clear();
		objetsAgr.clear();

		for (ItC i=unModele.eltsGeo.begin(); i!=unModele.eltsGeo.end();i++)
		{
					eltsGeo[i->first]=i->second;
		}

		for (ItaC i=unModele.objetsAgr.begin(); i!=unModele.objetsAgr.end();i++)
		{
					objetsAgr[i->first]=i->second;
		}
	}
	return *this;

}

//-------------------------------------------- Constructeurs - destructeur
Modele::Modele (const Modele & unModele )
// Algorithme :
//
{

	for (ItC i=unModele.eltsGeo.begin(); i!=unModele.eltsGeo.end();i++)
	{
		eltsGeo[i->first]=i->second;
	}


	for (ItaC i=unModele.objetsAgr.begin(); i!=unModele.objetsAgr.end();i++)
	{
		objetsAgr[i->first]=i->second;
	}


#ifdef MAP
    cout << "Appel au constructeur de copie de <Modele>" << endl;
#endif
} //----- Fin de Modele (constructeur de copie)


Modele::Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//
{
	//on commence par supprimer la mémoire allouée à chaque élement géométrique
	for (ItM i=eltsGeo.begin(); i!=eltsGeo.end();i++)
	{
			delete i->second;
			i->second=NULL;
	}
	//on supprime les éléments des 2 maps
	eltsGeo.clear();
	objetsAgr.clear();

#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
