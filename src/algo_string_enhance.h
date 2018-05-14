//
//  algo_string_enhance.h
//  algo_datastructure
//
//  Created by Yunpeng Hou on 10/3/17.
//


#ifndef algo_string_enhance_h
#define algo_string_enhance_h

#include <string>
#include <vector>

namespace algo
{
namespace string_enhance
{
    using std::vector;
    using std::string;
    
    
    
    // Split inputString by delimiter
    vector<string> split( const string& inputString, const string& delimiter, vector<string>& result );
    
    // Split inputString by whitespace char (' ', '\t', ...)
    vector<string> split( const string& inputString );
    
    vector<string> splitBySpaces( const string& inputString );
    
    //--------------------------------
    // KMP string matching
    //--------------------------------

    // Given the string and a pattern, find all indexes in inputString that matches the pattern
    // Using KMP algorithm
    void findMatchKMP( const string& inputString, const string& pattern, vector<int>& matches );
    
    // Compute longest prefix suffix table for KMP algorithm
    void getLongestPrefixSuffixTable(const string& pattern, vector<int>& lpsTable);
}
}


#endif /* algo_string_enhance_h */
