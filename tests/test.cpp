#include "sorts.h"
#include "dfs.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "util.h"
#include <vector>
#include <random>
using testing::Bool;

int generator()
{
	static std::mt19937 randomGenerator;
	static std::uniform_int_distribution<int> distribution(-100000, 100000);

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

TEST(DFS, PathFound)
{
	using algorithm::Nodev2;

	std::map<int, std::vector<Nodev2>> graph;
	graph[0].push_back(Nodev2(1, 2));
	graph[0].push_back(Nodev2(3, 3));
	graph[2].push_back(Nodev2(3, 2));
	graph[3].push_back(Nodev2(4, 2));

	EXPECT_TRUE(algorithm::graph::dfsSearchAdjList(0, 4, graph));
}

TEST(DFS, PathNotFound)
{
	using algorithm::Nodev2;

	std::map<int, std::vector<Nodev2>> graph;
	graph[0].push_back(Nodev2(1, 2));
	graph[0].push_back(Nodev2(3, 3));
	graph[2].push_back(Nodev2(3, 2));
	graph[3].push_back(Nodev2(4, 2));

	EXPECT_FALSE(algorithm::graph::dfsSearchAdjList(0, 2, graph));
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}