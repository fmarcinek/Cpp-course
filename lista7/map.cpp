#include "map.h"


std::map<std::string, unsigned int, case_insensitive_cmp> frequencytable(const std::vector<std::string>& text){
    std::map<std::string, unsigned int, case_insensitive_cmp> our_map;
    for (std::string word : text){
        our_map[word]++;
    }
    return our_map;
}


std::ostream& operator << (std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp> &freq){
    for (auto& kv : freq){
        stream << kv.first + " -> " << kv.second << "\n";
    }

    return stream;
}

bool case_insensitive_cmp::operator( ) (const std::string& s1, const std::string& s2) const {

    for (int i = 0; i < std::min<int>(s1.size(), s2.size()); ++i)
    {
        if (s1[i] == s2[i])
            continue;
        if (std::abs(s1[i] - s2[i]) == 32)
            continue;

        return s1[i] < s2[i];
    }

    if (s1.size() < s2.size())
        return true;

    return false;
}

size_t case_insensitive_hash::operator( ) (const std::string& s) const {

    size_t w = 0;

    for(size_t i = 0; i < s.size(); i++)
    {
        w = (w * 29)%1000000007 + (tolower(s[i]) - 'a' + 1);
        w %= 1000000007;
    }

    return w;
}

bool case_insensitive_equality::operator( ) (const std::string& s1, const std::string& s2) const {
    case_insensitive_cmp c;
    return !c(s1, s2) && !c(s2,s1);
}

// std::unordered_map< std::string, unsigned int,
// case_insensitive_hash, case_insensitive_equality >
// hashed_frequncytable( const std::vector< std::string > & text );
