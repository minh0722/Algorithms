#ifndef ALGORITHM_SEGMENT_TREE
#define ALGORITHM_SEGMENT_TREE

#include <vector>
#include "common.h"

namespace algorithm
{
    template <typename T>
    class MinSegmentTree
    {
        struct Node
        {
            T minVal;
            int count;
        };

    public:
        MinSegmentTree(std::vector<T>& arr);

        MinSegmentTree(unsigned int n, bool isBinary = false);

        void add(T val, int start, int end);

        Node queryRangeMinAdd(int start, int end);

        void set(T val, int start, int end);

        Node queryRangeMinSet(int start, int end);

    private:

        Node queryRangeMinSet(int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd);

        Node queryRangeMinAdd(int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd);

        void add(T val, int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd);

        void set(T val, int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd);

        void build(std::vector<T>& arr, int curr, int start, int end);

        void build(int curr, int start, int end, bool isBinary = false);

    private:
        std::vector<Node> m_tree;

        std::vector<bool> m_lazySetFlag;
        std::vector<T> m_lazySetVal;

        std::vector<T> m_lazyAddVal;

        int n;
    };
}
#endif // ALGORITHM_SEGMENT_TREE

#include "segment_tree.hpp"