#ifndef Gerade2D_Loaded
#include "Vektor2D.h"
#define Gerade2D_Loaded
class Gerade2D
{
public:
	Gerade2D(Vektor2D, Vektor2D = Vektor2D(0, 0));
	~Gerade2D();
	float gerichteterAbstand(Vektor2D) const;
	bool aufGerade(Vektor2D) const;
	Vektor2D normale() const;
	Vektor2D aufpunkt() const;
	void normale(Vektor2D);
	void aufpunkt(Vektor2D);
private:
	Vektor2D m_Normale;
	Vektor2D m_Aufpunkt;
};
#endif
