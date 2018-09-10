#include "sorts.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "util.h"
#include <vector>
#include <random>
using testing::Bool;

int generator()
{
	static std::mt19937 randomGenerator;
	static std::uniform_int_distribution<int> distribution(1, 100000);

	return distribution(randomGenerator);
}

TEST(InsertionSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::insertionSort(v);

	EXPECT_TRUE(util::isSorted(v));
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}