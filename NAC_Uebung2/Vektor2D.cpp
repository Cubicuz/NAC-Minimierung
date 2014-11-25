#include "Vektor2D.h"
#include <iostream>

Vektor2D::Vektor2D()
: Vektor(2)
{
}

Vektor2D::Vektor2D(double a, double b)
: Vektor(2)
{
	Matrix::m_Element[0] = a;
	Matrix::m_Element[1] = b;
}


Vektor2D::~Vektor2D()
{
}


// Addiert ein Vektor2D zu diesem hinzu
void Vektor2D::addiere(Vektor2D v)
{
	m_Element[0] += v.m_Element[0];
	m_Element[1] += v.m_Element[1];
}


void Vektor2D::kopiereIn(Vektor2D* ziel) const
{
	ziel->m_Element[0] = m_Element[0];
	ziel->m_Element[1] = m_Element[1];
}

void tauschen(Vektor2D* w, Vektor2D* z){
	Vektor2D temp;
	temp.kopiereIn(z);
	z->kopiereIn(w);
	w->kopiereIn(&temp);
	}


// Ueberschreibt die ausgabe() von Matrix
void Vektor2D::ausgabe() const
{
	std::cout << "Vektor2D: " << std::endl;
	Vektor::ausgabe();
}

void Vektor2D::operator*(double mult){
	m_Element[0] *= mult;
	m_Element[1] *= mult;
}

void Vektor2D::operator+(Vektor2D add){
	m_Element[0] += add.m_Element[0];
	m_Element[1] += add.m_Element[1];
}