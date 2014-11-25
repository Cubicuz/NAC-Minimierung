#include "Funktion2D.h"
#include <math.h>
#include <iostream>

Funktion2D::Funktion2D()
{
}

double Funktion2D::operator()(Vektor2D inVektor){
	inVektor + Vektor2D(1, 0);
	return -(sin(inVektor.betrag()) / inVektor.betrag());
}

Funktion2D::~Funktion2D()
{
}

Vektor2D Funktion2D::gradient2D(Funktion2D f, Vektor2D p){
	double h = 0.000001;
	Vektor2D gradient(
		(f(Vektor2D((p.get(0) + h), p.get(1))) - f(Vektor2D(p.get(0), p.get(1)))) / h,
		(f(Vektor2D((p.get(0)), p.get(1) + h)) - f(Vektor2D(p.get(0), p.get(1)))) / h
	);
	return gradient;
}

Vektor2D Funktion2D::minimieren2D(Funktion2D f, Vektor2D p, double step, double tol, double ftol){
	Vektor2D verschiebung(1,1); //Initialisierung für die whileschleifenbedingung
	Vektor2D gradient = gradient2D(f,p);
	int iterationCounter(0);
	while ((gradient.betrag() > tol) && (verschiebung.betrag() > ftol) && (iterationCounter<5000)){
		iterationCounter++;
		gradient.kopiereIn(&verschiebung);
		verschiebung.multipliziere(-step);
		// p = p + verschiebung
		p.addiere(verschiebung);
		// Gradient aktualisieren
		gradient2D(f, p).kopiereIn(&gradient);
	}
	std::cout << "Anzahl der Iterationen " << iterationCounter << std::endl;
	return p;
}
