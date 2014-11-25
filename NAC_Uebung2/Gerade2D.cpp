#include "Gerade2D.h"
#include <iostream>

Gerade2D::Gerade2D(Vektor2D normale,Vektor2D aufpunkt)
:m_Normale(normale), m_Aufpunkt(aufpunkt)
{

}


Gerade2D::~Gerade2D()
{

}

float Gerade2D::gerichteterAbstand(Vektor2D punkt) const {
	float n=m_Normale.betrag();
	punkt.subtrahiere(m_Aufpunkt);
	float n0 = m_Normale.get(0)/n;
	float n1 = m_Normale.get(1)/n;
	float p0 = punkt.get(0);
	float p1 = punkt.get(1);

	return (n0*p0 + n1*p1);
}

bool Gerade2D::aufGerade(Vektor2D punkt) const {
	return (gerichteterAbstand(punkt) == 0);
}

void Gerade2D::normale(Vektor2D n){
	n.kopiereIn(&m_Normale);
}

void Gerade2D::aufpunkt(Vektor2D a){
	a.kopiereIn(&m_Aufpunkt);
}

Vektor2D Gerade2D::normale() const {
	return m_Normale;
}

Vektor2D Gerade2D::aufpunkt() const {
	return m_Aufpunkt;
}