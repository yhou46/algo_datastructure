
// std lib
#include <iostream>
#include <vector>

// Self lib
#include "algo_sort.h"
#include "datastructure_linkedlist.h"

using namespace algo;
using namespace datastructure;

int main(int argc, const char * argv[])
{
    std::vector<int> input = {7,6,5,4,1,2,3};
    
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

    LinkedList linkedList(input);
    std::cout << linkedList;
    
    return 0;
}
