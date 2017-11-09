
// std lib
#include <iostream>
#include <vector>
#include <string>
#include <regex>

// Self lib
#include "algo_sort.h"
#include "datastructure_linkedlist.h"
#include "datastructure_binary_index_tree.h"
#include "algo_string_enhance.h"

using namespace algo;
using namespace datastructure;

int main(int argc, const char * argv[])
{
    // Input for test case
    // std::vector<int> input = {2,1,3,4,0};
    
//    // Test sort algorithm
//    // - Test quicksort
//    // algo::sort::QuickSort::quickSort(input, 0, input.size());
//    algo::sort::MergeSort::mergeSort(input, 0, input.size());
//    
//    for(auto begin = input.begin(); begin != input.end(); ++begin)
//    {
//        std::cout << *begin << ",";
//    }
//    std::cout << "\n";
    
//    // Test for bit 1 D
//    BinaryIndexTree bit(input);
//    
//    for( int i=0; i < input.size(); ++i )
//    {
//        std::cout << "input: " << i << ":" << input[i] << "\n";
//    }
//    std::cout << "\n";
//    std::cout << bit.getRangeSum(3, 3) << "\n";
    
    // Test for bit2D
//    std::vector< std::vector<int> > input =
//    {
//        {3,0,1,4,2},
//        {5,6,3,2,1},
//        {1,2,0,1,5},
//        {4,1,0,1,7},
//        {1,0,3,0,5}
//    };
//    
//    BinaryIndexTree2D bit2D(input);
//    std::cout << bit2D;
//    
//    std::cout << "Total sum: " << bit2D.getTotalSum(2, 2) << "\n";
//    std::cout << "Region sum: " << bit2D.getRegionSum(1, 1, 2, 2) << "\n";
    
    // Test for split string
    std::string inputString("aaaaaa");
    std::string pattern("aa");
    std::vector<int> lpsTable;
    
    std::vector<int> result;
    string_enhance::findMatchKMP(inputString, pattern, result);
    
    std::cout << "input:  [" << inputString << "\n";
    std::cout << "pattern:[" << pattern << "\n";
    for( auto i: result )
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    
    return 0;
}
