
#ifndef STRING_INCLUDED
#define STRING_INCLUDED 1

#include <iostream>
#include <cstring>

class string
{
   size_t len;
   char *p;

public:
   string( )
      : len{0},
        p{ nullptr }   // Works, see the slides.
   { }

   string( const char* s )
      : len{ strlen(s) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s[i];
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
   }

   void operator = ( const string& s )
   {
      if( len != s.len )
      {
         delete[] p;
         len = s. len;
         p = new char[ len ];
      }

      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
   }

   char operator [] ( size_t i ) const
   {
     return p[i];
   }

   char& operator [] ( size_t i )
   {
     return p[i];
   }

   void operator += ( char c )
   {
      char *old = p;
      p = new char [len + 1];
      for (unsigned i = 0; i < len; ++i)
          p[i] = old[i];
      p[len - 1] = c;
      len += 1;
      delete[] old;
   }

   void operator += ( const string& s )
   {
    char *old = p;
    size_t j = len;
    p = new char [j + s.len];
    for(unsigned i = 0; i < j; ++i )
        p[i] = old[i];
    for (unsigned i = 0; i<s.len; ++i )
        p[j + i] = s[i];
    len += s.len;
    delete[] old;
   }

   size_t size( ) const { return len; }

   ~string( )
   {
      delete[] p;
   }


   using iterator = char* ;
   using const_iterator = const char* ;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }

};

std::ostream& operator << ( std::ostream& out, const string& s );

string operator + ( const string& s1, const string& s2 );


bool operator == ( const string& s1, const string& s2 );
bool operator != ( const string& s1, const string& s2 );
bool operator < ( const string& s1, const string& s2 );
bool operator > ( const string& s1, const string& s2 );
bool operator <= ( const string& s1, const string& s2 );
bool operator >= ( const string& s1, const string& s2 );

#endif
