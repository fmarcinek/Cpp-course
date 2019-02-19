#include "string.h"


std::ostream& operator << ( std::ostream& out, const string& s )
{
   for( size_t i = 0; i < s.size( ); ++ i )
        out << s[i];

   return out;
}

string operator + ( const string& s1, const string& s2 )
{
  string s = s1;
  s += s2;
  return s;
}



bool operator == ( const string& s1, const string& s2 )
{
  if (s1.size() != s2.size()) return false;
  for ( unsigned i = 0; i<s1.size(); ++i)
      if (s1[i] != s2[i]) return false;
  return true;

}

bool operator != ( const string& s1, const string& s2 )
{
 return ! (s1 == s2);
}


bool operator > ( const string& s1, const string& s2 )
{
  size_t m = std::min(s1.size(),s2.size());

  for (unsigned i = 0; i<m; ++i) {
    if (s1[i]==s2[i]) continue;
    else return (s1[i]>s2[i]);
  }


  return (s2.size() < s1.size());
}

bool operator < ( const string& s1, const string& s2 )
{
    return (s2 > s1);
}

bool operator <= ( const string& s1, const string& s2 )
{
    return !(s1 > s2);
}
bool operator >= ( const string& s1, const string& s2 )
{
    return !(s2 > s1);
}
