#ifndef funktion2d
#define funktion2d
#include "Vektor2D.h"
class Funktion2D
{
public:
	Funktion2D();
	virtual ~Funktion2D();
	double operator()(Vektor2D);
	static Vektor2D gradient2D(Funktion2D f, Vektor2D p);
	static Vektor2D minimieren2D(Funktion2D f, Vektor2D p, double step, double tol = 0.000002, double ftol = 0.000002);
};

#endif