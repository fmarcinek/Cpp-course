
#include "powerproduct.h"
#include "polynomial.h"
#include "bigint.h"
#include "rational.h"
#include <algorithm>
#include <vector>


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
   powerproduct v;

   N fact = 1;

   polynomial< N > result;
   for( unsigned int i = 0; i < n; ++ i )
   {
      result[v] += fact;
      v = v * powvar( "x" );
      fact = fact / (i+1);
   }

   return result;
}

template< typename N >
double valuation (polynomial< N > pol) {

    rational res = 0;

    for (auto p : pol.repr) {
        res += p.second;
    }

    return res.approximation();
}


int main( int argc, char* argv [] )
{

   std::cout << "hello\n";

   polynomial< rational > pol;

   int N = 50;

   pol[ { } ] = 1;
   pol[ { "x" } ] = rational( 1, N );


   polynomial< rational > res = 1;

   for( int i = 0; i < N; ++ i )
      res = res * pol;

   std::cout << "rsult = " << res << "\n\n";

   std::cout << " taylor expansion = " << exptaylor<rational>(20) << "\n";

   std::cout << "difference = " ;
   std::cout << res - exptaylor<rational> ( 40 ) << "\n";


   std::cout << valuation(res) << "\n";

  /*  powerproduct c{{"x", 5}, {"y", 7}, {"x", 6}};
    powerproduct d{{"z", 2}, {"y", -1}, {"z", 5}};
    std::cout << c << "\n";
    std::cout << d << "\n";
    std::cout << powerproduct::compare(c,d) << "\n";
    std::cout << (c * d) << "\n";
*/


   return 0;
}
