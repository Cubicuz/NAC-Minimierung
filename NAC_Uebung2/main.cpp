#include "Matrix.h"
#include "Vektor.h"
#include "Vektor2D.h"
#include <iostream>
#include "Gerade2D.h"
#include "Funktion2D.h"
#include <iomanip>

int main(int argc, char * args[]){
	{
		//Anlegen der Vektoren a,b,c
		Vektor2D a(3, 1), b(1, 2), c;
		//Anlegen der Vektoren z,w auf dem Heap
		Vektor2D* z = new Vektor2D(-3, 1);
		Vektor2D* w = new Vektor2D;

		//Übung2
		c.addiere(a);
		b.addiere(c);
		//Übung3
		a.addiere(*z);
		w->addiere(*z);
		w->ausgabe();
		w->addiere(b);
		w->ausgabe();

		Vektor2D u(1, 2);
		w->kopiereIn(&u);
		z->kopiereIn(&u);
		w->ausgabe();
		z->ausgabe();
		std::cout << "A vor dem Tausch";
		a.ausgabe();
		std::cout << "\n" << "Z vor dem Tausch";
		z->ausgabe();

		tauschen(z, &a);
		std::cout << "\n" << "Z und A wurden getauscht" << "\n";
		z->ausgabe();
		a.ausgabe();

	}
	std::cout<<Matrix::getCounter();
	Vektor2D k(1, 1),l(-5,0);
	std::cout << "Winkel Wert " << k.winkel(l) << std::endl;

	//Übung 5
	Vektor2D* arr  = new Vektor2D[2];
	Vektor2D eins = Vektor2D(2, 3);
	Vektor2D zwei = Vektor2D(-2, 1);
	arr[0] = eins;
	arr[1] = zwei;
	arr[0].addiere(arr[1]);
	arr[0].ausgabe();
	delete[] arr;


	std::cout << std::endl << std::endl;


	Vektor2D normale(-3, -4);
	normale.ausgabe();
	Gerade2D normaleGerade(normale);
	float abstand = normaleGerade.gerichteterAbstand(Vektor2D(4, 3));
	std::cout << abstand << std::endl;

	//Übung 6
	std::cout << std::endl << "Übung 6" << std::endl;
	std::cout << Gerade2D(Vektor2D(-3, -4)).aufGerade(Vektor2D(4, -3));

	//Testatübung 7
	std::cout << std::endl << std::endl << "Testat" << std::endl;
	Funktion2D f;
	
	Vektor2D minima1 = Funktion2D::minimieren2D(f,Vektor2D(4,0),1,0.0000001,0.0000001);
	minima1 = Funktion2D::gradient2D(f, Vektor2D(4, 0));
	minima1.ausgabe();
	Funktion2D::gradient2D(f, minima1).ausgabe();
	std::cout << f(minima1) << std::endl;
	return 0;
}
