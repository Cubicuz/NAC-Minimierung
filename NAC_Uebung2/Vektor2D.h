#include "Vektor.h"
#ifdef VEKTOR2D_LOADED

#else
#define VEKTOR2D_LOADED
class Vektor2D :
	public Vektor
{
public:
	Vektor2D();
	Vektor2D(double a, double b);
	virtual ~Vektor2D();
	// Addiert ein Vektor2D zu diesem hinzu
	void addiere(Vektor2D v);
	// Kopiert this in Ziel
	void kopiereIn(Vektor2D* ziel) const;
	// Ueberschreibt die ausgabe() von Matrix
	void ausgabe()const;
	// Operator * mit einer Gleitkommazahl
	void operator*(double mult);
	// Operator + mit einem anderen Vektor2D
	void operator+(Vektor2D add);
};

void tauschen(Vektor2D* w, Vektor2D* z);
#endif
