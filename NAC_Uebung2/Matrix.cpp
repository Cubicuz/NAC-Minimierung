#include "Matrix.h"
#include <iostream>
int Matrix::counter(0);
Matrix::Matrix(int m, int n)
{
	m_Element = new double[m*n];
	this->m_Zeilen  = m;
	this->m_Spalten   = n;
	
	counter++;
}

void Matrix::operator=(Matrix const & alteMatrix){
	if (this != &alteMatrix){
		delete[] m_Element;
		this->m_Spalten = alteMatrix.m_Spalten;
		this->m_Zeilen = alteMatrix.m_Zeilen;
		m_Element = new double[m_Spalten * m_Zeilen];
		for (int i = 0; i < (m_Spalten * m_Zeilen); i++){
			m_Element[i] = alteMatrix.m_Element[i];
		}
	}
}

double Matrix::operator()(int i, int j) const{
	if (i < m_Zeilen || j < m_Spalten) {
		throw std::numeric_limits<float>::quiet_NaN();
	}
	return m_Element[i*j];
}

Matrix::~Matrix()
{
	counter--;
//	delete [] m_Element;
}

// Gibt alle Element der Matrix aus
void Matrix::ausgabe() const 
{
	int counter = 0;
	while (counter < (m_Spalten * m_Zeilen)){
		std::cout << m_Element[counter] << "\n";
		counter++;
	}
}


int Matrix::getCounter()
{
	return counter;
}
