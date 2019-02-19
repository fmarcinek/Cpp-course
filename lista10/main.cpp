
#include <iostream>

#include "units.h"

// Useful if you want to compute the yield of an atomic bomb:


quantity::energy mc2( quantity::mass m )
{
   auto C = 299792458.0_mps;
   return m * C * C;
}


int main( int argc, char* argv [ ] )
{
   std::cout << 9.81 * 1.0_m / ( 1.0_sec * 1.0_sec ) << "\n";
      // Acceleration on earth.

   std::cout << 1.0_m << "\n";
   std::cout << 2.0_hr << "\n";

   std::cout << 1000.0_watt << "\n\n\n";


   std::cout << "ZADANIE 5." << "\n\n";
   auto I = 0.8_A*1.0_hr;
   auto V = 1.2_V;
   std::cout << I << "    " << V << "\n\n";

   std::cout << I*V << "\n\n\n";


   std::cout << "ZADANIE 6." << "\n\n";
   auto v1 = 100.0_kmh;
   auto v2_rel = 30.0_kmh;
   auto m2 = 1200.0_kg;
   auto v2 = v1 + v2_rel;
   std::cout << "Velocity of car B: " << v2 << "\n";

   auto kin_energy = (m2 * v2 * v2) / 2;
   std::cout << "Kinetic energy of car B: " << kin_energy << "\n";

   const auto c = 299792458.0_mps;
   auto u = (v1 + v2) / (1 + v1*v2/(c*c));
   std::cout << "Relative effect: " << u << "\n\n\n";


   std::cout << "ZADANIE 7." << "\n\n";
   const auto tnt_const = 4184.0_joule/0.001_kg;
   auto mass = 2.3_kg;
   auto energy = mc2(mass);
   std::cout << "Tsar Bomba energy: " << energy << "\n";
  //  std::cout << energy.val << "\n";
   std::cout << "TNT-equivalent: " << (energy / tnt_const)/1.0_kg << "\n";

   return 0;

}
