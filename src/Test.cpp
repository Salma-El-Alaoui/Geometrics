using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include "EltGeo.h"
#include "Point.h"
#include "Rectangle.h"
#include "Polyligne.h"
#include "ObjAgr.h"
#include "Cercle.h"
#include "Modele.h"
#include "Commande.h"
#include "CmdAjoutC.h"
#include "CommandeHis.h"
#include "CmdSuppression.h"
#include "CmdSave.h"
#include "CmdLoad.h"

void afficherVecteur(const vector<Point> & p)
//à utiliser seulement dans le cas ou il n'est pas NULL
{
	for(size_t i=0;i<p.size();i++)
	{
		cout<<p.at(i).GetX()<<" , "<<p.at(i).GetY()<<endl;
	}
}

int main2(int argc,char**argv)
{

	//Modele * modele=new Modele;

	/*



	// par exemple les points qu'on lit en ligne de commabde
	Point p1(1,2);
	Point p2(3,4);
	vector<Point> *points = new vector<Point> ;
	points->push_back(p1);
	points->push_back(p2);



	//création d'une polyligne normale
	Polyligne poly ("poly");
	string nom=poly.GetNom();
	cout <<nom<<endl;
	poly.SetPolyligne(*points);
	//je supprime points pour voir si le vecteur de la polyligen va rester correct
	delete points;
	afficherVecteur(poly.GetPoints());

	//test de l'opérateur =
	Polyligne poly1("poly1");
	poly1=poly;
	afficherVecteur(poly1.GetPoints());

	//test du constructeur de copie
	Polyligne poly2("poly2");
	poly2.GetPoints();

	Rectangle* r1 = new Rectangle("r1",1,1,2,2);
	cout<< "r1 "<<  r1->GetPoint1().GetX()<<endl;
	Rectangle* r2 =new Rectangle("r2",3,3,4,4);

    ObjAgr * o1 = new ObjAgr("o1");
	ObjAgr * o2=new ObjAgr("o2");
	ObjAgr*  o3= new  ObjAgr("o3");

	o1->AjouterElement(*r1);
	o1->AjouterElement(*r2);


	o2->AjouterElement(*r1);
	o2->AjouterElement(*r2);



	o3->AjouterElement(*o1);
	o3->AjouterElement(*o2);

	o3->premier=true;
	o3->Deplacer(1,1);
	o3->premier=false;
	cout<< "r1 "<< r1->GetPoint1().GetX()<<endl<<endl<<endl;

	o2->premier=true;
	o2->Deplacer(1,1);
	o2->premier=false;

	cout<< "r1 "<< r1->GetPoint1().GetX()<<endl;



	Rectangle* r3 = new Rectangle("r3",1,1,2,2);
	ObjAgr* o4= new  ObjAgr("o4");
	o4->AjouterElement(*r3);
	o4->Deplacer(1,1);
	cout<< "r3 "<< r3->GetPoint1().GetX()<<endl;
	*/

	//Test de suppression

	/*
	Modele modele;
	Rectangle* r1 = new Rectangle("r1",1,1,2,2);
	Rectangle* r2 =new Rectangle("r2",3,3,4,4);
	ObjAgr * o1 = new ObjAgr("o1");
	o1->AjouterElement(*r1);
	o1->AjouterElement(*r2);

	modele.Ajouter(*r1);
	modele.Ajouter(*r2);
	modele.AjouterAgr(*o1);
	//o1->SupprimerElement("r1");
	o1->SupprimerElement("r1");
	o1->AfficherElements();
	modele.AfficherElements();
	modele.AfficherObjetsAgr();
	//o1->AfficherElements();

*/
	/*
	// test modele
	Modele modele;
	Rectangle* r1 = new Rectangle("r1",1,1,2,2);
	Rectangle* r2 =new Rectangle("r2",2,2,4,4);
	Rectangle* r3 = new Rectangle("r3",3,1,2,2);
	Rectangle* r4 =new Rectangle("r4",4,3,4,4);

	ObjAgr * o1 = new ObjAgr("o1");
	ObjAgr * o2 = new ObjAgr("o2");
	ObjAgr * o3 = new ObjAgr("o3");
	ObjAgr * o4 = new ObjAgr("o4");

	o1->AjouterElement(*r1);
	o1->AjouterElement(*r2);

	o2->AjouterElement(*r3);
	o2->AjouterElement(*r4);
	o2->AjouterElement(*r2);

	o3->AjouterElement(*r2);
	o3->AjouterElement(*r3);

	o4->AjouterElement(*o1);
	o4->AjouterElement(*o2);
	o4->AjouterElement(*o3);

	modele.Ajouter(*r1);
	modele.Ajouter(*r2);
	modele.Ajouter(*r3);
	modele.Ajouter(*r4);

	modele.AjouterAgr(*o1);
	modele.AjouterAgr(*o2);
	modele.AjouterAgr(*o3);
	modele.AjouterAgr(*o4);

	modele.Deplacer("o4",1,1);
	cout<< "r1 "<< r1->GetPoint1().GetX()<<endl;
	cout<< "r2 "<< r2->GetPoint1().GetX()<<endl;
	cout<< "r3 "<< r3->GetPoint1().GetX()<<endl;
	cout<< "r4 "<< r4->GetPoint1().GetX()<<endl;

	//ObjAgr o5(*o1);

	//o5.AfficherElements();
	//o1->SupprimerElement("r3");

	*/



	//test de l'ajout
	/*
	CmdAjoutC Ca(modele,"cercle1",1,1,1);
	Ca.Executer();
	modele->AfficherElements();
	Ca.Undo();
	modele->AfficherElements();
	Ca.Redo();
	modele->AfficherElements();
	 */

	//test de la suppression
	/*CmdAjoutC Ca(modele,"cercle1",1,1,1);
	Ca.Executer();
	modele->AfficherElements();*/
	/*CmdSuppression Cs(modele,"cercle1");
	Cs.Executer();
	modele->AfficherElements();
	Cs.Undo();
	modele->AfficherElements();
	modele->Deplacer("cercle1",1,1);
	*/
	//CmdAjoutC Cb(modele,"cercle1",1,2,4);
	//Cb.Executer();
	//modele->AfficherElements();

	//test du save
	/*CmdAjoutC Ca(modele,"cercle1",1,1,1);
	Ca.Executer();
	modele->AfficherElements();
	CmdAjoutC Cb(modele,"cercle2",2,2,2);
	Cb.Executer();
	CmdAjoutC Cc(modele,"cercle3",3,3,3);
	Cc.Executer();
	modele->AfficherElements();
	CmdSave s(modele,"testtttt");
	s.Executer();*/

	//test du load
	/*CmdLoad load(modele, "testtttt");
	load.Executer();*/


	/*Rectangle* r1 = new Rectangle("r1",1,1,2,2);
	Rectangle* r2 =new Rectangle("r2",2,2,4,4);
	Rectangle* r3 = new Rectangle("r3",3,1,2,2);
	Rectangle* r4 =new Rectangle("r4",4,3,4,4);

    ObjAgr * o1 = new ObjAgr("o1");
	ObjAgr * o2=new ObjAgr("o2");
	ObjAgr*  o3= new  ObjAgr("o3");

	o1->AjouterElement(*r1);
	o1->AjouterElement(*r2);*/


	return 0;



}
