#include "Matrix.h"
#ifdef VEKTOR_LOADED
//Ist bereits geladen
#else
#define VEKTOR_LOADED
class Vektor :
	public Matrix
{
public:
	Vektor(int n);
	virtual ~Vektor();
	float betrag() const;
	// Errechnet das Skalarprdoukt 2er Vektoren
	double skalarprodukt(Vektor v) const;
	// Errechnet den Winkel in Grad zu dem uebergebenen Vektor
	double winkel(Vektor v) const ;
	// Subtrahiert einen Vektor von This
	void subtrahiere(Vektor sub);
	// Multipliziere einen Float zu This
	void multipliziere(float mult);
	// gebe Element an i-ter stelle zurück
	double get(int i) const;
};
#endif

