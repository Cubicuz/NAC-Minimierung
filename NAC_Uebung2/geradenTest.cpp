#include <iostream>
#include <math.h>
#include "Gerade2D.h"

static void falsch()
{
  std::cout << "falsch" << std::endl;
}

#define TEST(bedingung)                   \
  if(bedingung)                           \
    std::cout << "richtig" << std::endl;  \
  else                                    \
    falsch();

void geradenTest(const Gerade2D& g)
{
  Vektor2D v(6,0);
  TEST(g.aufGerade(v) == true);
  
  TEST(fabs(g.gerichteterAbstand(Vektor2D(9,4)) - (-5)) < 0.0001);
  
  TEST(fabs(g.normale().winkel(Vektor2D(1,-7)) - 45) < 0.0001);

  Gerade2D g2(Vektor2D(7,7));
  g2.normale()=g.normale();
  TEST(fabs(g2.normale().betrag() - 5) < 0.0001);
  
  TEST(g2.aufGerade(g.aufpunkt()) == false);
}
