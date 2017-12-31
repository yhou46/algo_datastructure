
// google test framework
#include "gtest/gtest.h"

// std
#include <vector>
#include <algorithm>

// Self headers
#include "algo_sort.h"


TEST(quick_sort, quick_sort_test)
{
	using namespace algo::sort;
	std::vector<int> input = {2,3,1,5,6};
	std::vector<int> result(input);

	// 
	algo::sort::QuickSort::quickSort(input, 0, input.size());

	// std sort
	std::sort(result.begin(), result.end());
	result[0] = 12;

	for(int i=0; i < input.size(); ++i)
	{
		EXPECT_EQ(input[i], result[i]) << "Vectors x and y differ at index " << i;
	}
}


