#include "Vektor.h"
#include <math.h>
#include <iostream>

Vektor::Vektor(int n)
:Matrix(n, 1)
{

}


Vektor::~Vektor()
{
}


float Vektor::betrag() const 
{
	float summe = 0;

	for (int i = 0; i < m_Zeilen; i++){
		summe += (m_Element[i]*m_Element[i]);
	}
	float betrag = sqrt(summe);
	return betrag;
}


// Errechnet das Skalarprdoukt 2er Vektoren
double Vektor::skalarprodukt(Vektor v) const 
{
	int testSumme = this->m_Spalten * this->m_Zeilen;
	if (testSumme == (v.m_Spalten * v.m_Zeilen)){
		int summe = 0;
		summe = this->m_Element[0] * v.m_Element[0];
		summe += this->m_Element[1] * v.m_Element[1];
		return summe;
	}else{
		return NAN;
	}
}


// Errechnet den Winkel in Grad zu dem uebergebenen Vektor
double Vektor::winkel(Vektor v) const 
{
	double pi = 3.14159265359;
	int testSumme = this->m_Spalten * this->m_Zeilen;
	if (testSumme == (v.m_Spalten * v.m_Zeilen)){
		double skalar = 0.0;
		double betrag = 0.0;
		double winkel = 0.0;
		skalar = this->skalarprodukt(v);
		betrag = this->betrag() * v.betrag();
		winkel = skalar / betrag;
		winkel = acos(winkel);
		//Umrechnen da acos in radiant zurück gibt
		double winkelGrad = winkel * 180 / pi;
		return winkelGrad;
	}else{
		return NAN;
	}

}


// Subtrahiert einen Vektor von This
void Vektor::subtrahiere(Vektor sub){
	if (m_Zeilen != sub.m_Zeilen){
		return;
	}
	for (int i = 0; i < m_Zeilen; i++){
		m_Element[i] -= sub.m_Element[i];
	}
}

// Multipliziert einen Float auf This
void Vektor::multipliziere(float mult){
	for (int i = 0; i < m_Zeilen;i++){
		m_Element[i] *= mult;
	}
}

double Vektor::get(int i) const {
	return m_Element[i];
}