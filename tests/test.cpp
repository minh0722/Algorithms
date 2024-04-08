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

TEST(SelectionSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::selectionSort(v);

	EXPECT_TRUE(util::isSorted(v));
}

TEST(BubbleSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::bubbleSort(v);

	EXPECT_TRUE(util::isSorted(v));
}

TEST(HeapSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::heapSort(v);

	EXPECT_TRUE(util::isSorted(v));
}

TEST(MergeSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::mergeSort(v.data(), 0, v.size() - 1);

	EXPECT_TRUE(util::isSorted(v));
}

TEST(QuickSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::quickSort(v.data(), 0, v.size() - 1);

	EXPECT_TRUE(util::isSorted(v));
}

TEST(RadixSort, SortIsCorrect)
{
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), generator);
	algorithm::sort::radixSort(v.data(), v.size());

	EXPECT_TRUE(util::isSorted(v));
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}