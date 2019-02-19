
#include "powerproduct.h"
#include <algorithm>




bool operator < (const powvar& p1, const powvar& p2) {
  if (p1.v > p2.v) {
    return false;
  } else if (p2.v == p1.v) {
    return p1.n < p2.n;
  } else {
    return true;
  }
}


std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const powerproduct& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int powerproduct::power( ) const
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}

void powerproduct::normalize() {
  if (repr.size() == 0) return;

  std::sort(repr.begin(), repr.end());
  std::vector<powvar> newRepr;
  std::string v = repr[0].v;
  int n = 0;

  for ( auto pow : repr) {
    if (pow.v == v) {
      n += pow.n;
    }
    else {
      if (n != 0) newRepr.push_back({v, n});
      v = pow.v;
      n = pow.n;
    }
  }

  if (n != 0) newRepr.push_back({v, n});
  repr = std::move (newRepr);
}

int powerproduct::compare(const powerproduct& c1, const powerproduct& c2) {
  size_t n = std::min(c1.size(), c2.size());
  for (size_t i=0; i<n; i++) {
    if (c1.repr[i] < c2.repr[i]) {
      return -1;
    }
    if (c2.repr[i] < c1.repr[i]) {
      return 1;
    }
  }
  if (c1.size() < c2.size()) return -1;
  if (c1.size() == c2.size()) return 0;
  return 1;
}


powerproduct operator * ( powerproduct c1, const powerproduct& c2 ) {
  c1.repr.reserve(c1.size() + c2.size());

  for (auto e : c2.repr) {
    c1.repr.push_back(e);
  }
  c1.normalize();
  return c1;
}
