#ifndef MAP
#define MAP


#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>



struct case_insensitive_cmp
{
    bool operator() (const std::string& s1, const std::string& s2) const;
    // Return true if s1 < s2, ignoring case of the letters.
};

struct case_insensitive_hash
{
    size_t operator () (const std::string& s) const;
};

struct case_insensitive_equality
{
    bool operator ( ) ( const std::string& s1, const std::string& s2 ) const;
};


//template<typename C = std::less<std::string>>
std::map<std::string, unsigned int, case_insensitive_cmp>
frequencytable(const std::vector<std::string>& text);


//template<typename C>
std::ostream& operator << (std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp> &freq);


// std::unordered_map< std::string, unsigned int,
// case_insensitive_hash, case_insensitive_equality >
// hashed_frequncytable( const std::vector< std::string > & text );


#endif
