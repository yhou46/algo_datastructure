//
//  algo_string_enhance.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 10/3/17.
//

#include "algo_string_enhance.h"

#include <regex>
#include <sstream>
#include <string>

namespace algo
{
namespace string_enhance
{
    vector<string> split( const string& inputString )
    {
        std::regex regexExpression("\\s+");
        std::sregex_token_iterator tokenIter(inputString.begin(), inputString.end(), regexExpression,-1);
        std::vector<std::string> result(tokenIter, std::sregex_token_iterator());
        return result;
    }
    
    vector<string> splitBySpaces( const string& inputString )
    {
        std::stringstream ss(inputString);
        
        
        vector<string> result;
        std::string tempStr;
        while( std::getline(ss, tempStr, ' ') )
        {
            result.push_back(tempStr);
        }
        return result;
    }
    
    void findMatchKMP( const string& inputString, const string& pattern, vector<int>& matches )
    {
        matches.clear();
        
        vector<int> lpsTable;
        getLongestPrefixSuffixTable(pattern, lpsTable);
        
        int strPtr = 0, patternPtr = 0;
        while(strPtr < inputString.size())
        {
            if( inputString[strPtr] == pattern[patternPtr] )
            {
                ++strPtr;
                ++patternPtr;
                
                if( patternPtr == pattern.size() )
                {
                    matches.push_back(strPtr-patternPtr);
                    
                    // Under a full match, how to reset the patternPtr will have different results
                    // input: aaaaaa; pattern: aa
                    
                    //patternPtr = lpsTable[patternPtr-1]; // This will match all substring, 0,1,2,3,4
                    patternPtr = 0; // This will only match after the matched string; 0,2,4
                }
            }
            else if(patternPtr > 0) // Only under mismatch case, we find the next pattern index
            {
                patternPtr = lpsTable[patternPtr-1];
            }
            else
            {
                // if pattern 0 is a mismatch, we need to increment i
                ++strPtr;
            }
        }
    }
    
    void getLongestPrefixSuffixTable(const string& pattern, vector<int>& lpsTable)
    {
        lpsTable.clear();
        lpsTable.assign(pattern.size(), 0);
        
        int i = 1;
        int length = 0;
        while( i < lpsTable.size() )
        {
            if( pattern[i] == pattern[length] )
            {
                ++length;
                lpsTable[i] = length;
                ++i;
            }
            else if( length > 0 )
            {
                // It is more like compare pattern string to itself
                // Here input string is pattern[i], the 'pattern' is pattern[length]
                length = lpsTable[length-1];
            }
            else
            {
                lpsTable[i] = 0;
                ++i;
            }
        }
    }

}
}
