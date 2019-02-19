#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

std::list<std::string> vectorsToList(std::vector<std::string>& v);

std::list<std::string> vectorsToList(std::vector<std::string>& v)
{
    std::list<std::string> list;
    for (auto var : v)
        list.push_back(var);
    return list;
}


int main( int argc, char* argv [] )
{

   std::vector< std::string > vect;
   vect = vectortest::randomstrings(19999, 50);
//   std::cout << vect << "\n";

   std::cout << "VECTORS" << "\n";
   // Or use timer:

   auto t1 = std::chrono::high_resolution_clock::now( );
   vectortest::sort_move( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );
//   std::cout << vect << "\n";

   std::cout << "sort_move took " << d. count( ) << " seconds\n";

   { timer t( "sort_assign", std::cout);
     vectortest::sort_assign( vect );
   };

   { timer t( "sort_std", std::cout);
     vectortest::sort_std( vect );
   };

   std::ifstream plik{ "test2.txt" };
   vect = vectortest::readfile(plik);
//   std::cout << vect << "\n";

   { timer t( "read sort_std", std::cout);
     vectortest::sort_std( vect );
   };

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "LISTS" << "\n";

              std::list< std::string > list;
              list = listtest::randomstrings(19999, 50);

              auto t3 = std::chrono::high_resolution_clock::now( );
              listtest::sort_move( list );
              auto t4 = std::chrono::high_resolution_clock::now( );

              std::chrono::duration< double > d2 = ( t4 - t3 );
           //   std::cout << list << "\n";

              std::cout << "sort_move took " << d2. count( ) << " seconds\n";
              { timer t( "sort_assign", std::cout);
                listtest::sort_assign( list );
              };

              { timer t( "sort_std", std::cout);
                listtest::sort_std( list );
              };

              std::ifstream plik2{ "test2.txt" };
              list = listtest::readfile(plik2);
           //   std::cout << list << "\n";

              { timer t( "read sort_move", std::cout);
                listtest::sort_move( list );
              };
   return 0;


}
