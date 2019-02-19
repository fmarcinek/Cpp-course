#include <iostream>
#include <vector>
#include "map.h"


int main(){

   std::vector<std::string> v = { "AA", "aA", "Aa", "this", "THIS" };

   std::cout << frequencytable(v) << "\n";


   case_insensitive_cmp c;
   std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";


   case_insensitive_hash h;
   std::cout << h("xxz") << " " << h("XXX") << "\n";
   std::cout << h("Abc") << " " << h("abC") << "\n";
   // Hash value should be case insensitive.

   case_insensitive_equality e;
   std::cout << e("XXX", "xxx") << "\n";
   // Prints ’1’.

    return 0;
}
