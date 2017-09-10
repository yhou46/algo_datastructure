
// std lib
#include <iostream>
#include <vector>

// Self lib
#include "algo_sort.h"

int main(int argc, const char * argv[])
{
	std::vector<int> input;
	algo_datastructure::sort::quickSort(input);
	
	return 0;
}
