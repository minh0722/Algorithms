#ifndef ALGORITHM_SEGMENT_TREE_HPP
#define ALGORITHM_SEGMENT_TREE_HPP

namespace algorithm
{
    template <typename T>
    MinSegmentTree<T>::MinSegmentTree(std::vector<T>& arr) : n(arr.size())
    {
        m_tree.resize(arr.size() * 4);

        m_lazySetFlag.resize(m_tree.size(), false);
        m_lazySetVal.resize(m_tree.size(), 0);

        m_lazyAddVal.resize(m_tree.size(), 0);

        build(arr, 0, 0, arr.size() - 1);
    }

    template <typename T>
    MinSegmentTree<T>::MinSegmentTree(unsigned int n, bool isBinary/* = false*/) : n(n)
    {
        m_tree.resize(n * 4);

        m_lazySetFlag.resize(m_tree.size(), false);
        m_lazySetVal.resize(m_tree.size(), 0);

        m_lazyAddVal.resize(m_tree.size(), 0);

        build(0, 1, n, isBinary);
    }

    template <typename T>
    void MinSegmentTree<T>::add(T val, int start, int end)
    {
        if (start > end)
        {
            return;
        }

        add(val, start, end, 0, 0, n - 1);
    }

    template <typename T>
    typename MinSegmentTree<T>::Node MinSegmentTree<T>::queryRangeMinAdd(int start, int end)
    {
        return queryRangeMinAdd(start, end, 0, 0, n - 1);
    }

    template <typename T>
    void MinSegmentTree<T>::set(T val, int start, int end)
    {
        if (start > end)
        {
            return;
        }

        set(val, start, end, 0, 0, n - 1);
    }

    template <typename T>
    typename MinSegmentTree<T>::Node MinSegmentTree<T>::queryRangeMinSet(int start, int end)
    {
        return queryRangeMinSet(start, end, 0, 0, n - 1);
    }

    template <typename T>
    typename MinSegmentTree<T>::Node MinSegmentTree<T>::queryRangeMinSet(int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd)
    {
        // no overlap
        if (nodeRangeEnd < queryStart || nodeRangeStart > queryEnd)
        {
            return { INT_MAX, 0 };
        }
        // complete overlap
        else if (nodeRangeStart >= queryStart && nodeRangeEnd <= queryEnd)
        {
            return m_tree[currNode];
        }

        // partial overlap
        int leftChild = currNode * 2 + 1;
        int rightChild = currNode * 2 + 2;
        int nodeRangeMid = (nodeRangeStart + nodeRangeEnd) / 2;

        if (m_lazySetFlag[currNode])
        {
            m_tree[leftChild].minVal = m_lazySetVal[currNode];
            m_tree[rightChild].minVal = m_lazySetVal[currNode];
            m_lazySetFlag[currNode] = false;
        }

        Node left = queryRangeMinSet(queryStart, queryEnd, leftChild, nodeRangeStart, nodeRangeMid);
        Node right = queryRangeMinSet(queryStart, queryEnd, rightChild, nodeRangeMid + 1, nodeRangeEnd);

        if (left.minVal > right.minVal)
        {
            return right;
        }
        else if (left.minVal < right.minVal)
        {
            return left;
        }
        else
        {
            return { left.minVal, left.count + right.count };
        }
    }

    template <typename T>
    typename MinSegmentTree<T>::Node MinSegmentTree<T>::queryRangeMinAdd(int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd)
    {
        // no overlap
        if (nodeRangeEnd < queryStart || nodeRangeStart > queryEnd)
        {
            return { INT_MAX, 0 };
        }
        // complete overlap
        else if (nodeRangeStart >= queryStart && nodeRangeEnd <= queryEnd)
        {
            return m_tree[currNode];
        }

        // partial overlap
        int leftChild = currNode * 2 + 1;
        int rightChild = currNode * 2 + 2;
        int nodeRangeMid = (nodeRangeStart + nodeRangeEnd) / 2;

        if (m_lazyAddVal[currNode])
        {
            m_tree[leftChild].minVal += m_lazyAddVal[currNode];
            m_tree[rightChild].minVal += m_lazyAddVal[currNode];

            m_lazyAddVal[currNode] = 0;
        }

        const Node left = queryRangeMinAdd(queryStart, queryEnd, leftChild, nodeRangeStart, nodeRangeMid);
        const Node right = queryRangeMinAdd(queryStart, queryEnd, rightChild, nodeRangeMid + 1, nodeRangeEnd);

        if (left.minVal > right.minVal)
        {
            return right;
        }
        else if (left.minVal < right.minVal)
        {
            return left;
        }
        else
        {
            return { left.minVal, left.count + right.count };
        }
    }

    template <typename T>
    void MinSegmentTree<T>::add(T val, int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd)
    {
        // no overlap
        if (nodeRangeEnd < queryStart || nodeRangeStart > queryEnd)
        {
            return;
        }
        // complete overlap
        else if (nodeRangeStart >= queryStart && nodeRangeEnd <= queryEnd)
        {
            int rightChild = currNode * 2 + 2;

            if (rightChild < (int)m_tree.size())
            {
                m_tree[currNode].minVal += val;

                m_lazyAddVal[currNode] += val;
            }
            else
            {
                // leaf node
                m_tree[currNode].minVal += val;
            }

            return;
        }

        // partial overlap
        int leftChild = currNode * 2 + 1;
        int rightChild = currNode * 2 + 2;
        int nodeRangeMid = (nodeRangeStart + nodeRangeEnd) / 2;

        if (m_lazyAddVal[currNode])
        {
            m_tree[leftChild].minVal += m_lazyAddVal[currNode];
            m_tree[rightChild].minVal += m_lazyAddVal[currNode];

            m_lazyAddVal[leftChild] += m_lazyAddVal[currNode];
            m_lazyAddVal[rightChild] += m_lazyAddVal[currNode];

            m_lazyAddVal[currNode] = 0;
        }

        add(val, queryStart, queryEnd, leftChild, nodeRangeStart, nodeRangeMid);
        add(val, queryStart, queryEnd, rightChild, nodeRangeMid + 1, nodeRangeEnd);

        if (m_tree[leftChild].minVal < m_tree[rightChild].minVal)
        {
            m_tree[currNode] = { m_tree[leftChild].minVal, m_tree[leftChild].count };
        }
        else if (m_tree[leftChild].minVal > m_tree[rightChild].minVal)
        {
            m_tree[currNode] = { m_tree[rightChild].minVal, m_tree[rightChild].count };
        }
        else
        {
            m_tree[currNode] = { m_tree[leftChild].minVal, m_tree[leftChild].count + m_tree[rightChild].count };
        }
    }

    template <typename T>
    void MinSegmentTree<T>::set(T val, int queryStart, int queryEnd, int currNode, int nodeRangeStart, int nodeRangeEnd)
    {
        // no overlap
        if (nodeRangeEnd < queryStart || nodeRangeStart > queryEnd)
        {
            return;
        }
        // complete overlap
        else if (nodeRangeStart >= queryStart && nodeRangeEnd <= queryEnd)
        {
            int leftChild = currNode * 2 + 1;
            int rightChild = currNode * 2 + 2;

            if (rightChild < (T)m_tree.size())
            {
                m_tree[currNode] = { val, m_tree[leftChild].count + m_tree[rightChild].count };
                m_lazySetFlag[currNode] = true;
                m_lazySetVal[currNode] = m_tree[currNode].minVal;
            }
            else
            {
                // leaf node
                m_tree[currNode] = { val, 1 };
            }

            return;
        }

        // partial overlap
        int leftChild = currNode * 2 + 1;
        int rightChild = currNode * 2 + 2;
        int nodeRangeMid = (nodeRangeStart + nodeRangeEnd) / 2;

        set(val, queryStart, queryEnd, leftChild, nodeRangeStart, nodeRangeMid);
        set(val, queryStart, queryEnd, rightChild, nodeRangeMid + 1, nodeRangeEnd);

        if (m_tree[leftChild].minVal < m_tree[rightChild].minVal)
        {
            m_tree[currNode] = { m_tree[leftChild].minVal, m_tree[leftChild].count };
        }
        else if (m_tree[leftChild].minVal > m_tree[rightChild].minVal)
        {
            m_tree[currNode] = { m_tree[rightChild].minVal, m_tree[rightChild].count };
        }
        else
        {
            m_tree[currNode] = { m_tree[leftChild].minVal, m_tree[leftChild].count + m_tree[rightChild].count };
        }
    }

    template <typename T>
    void MinSegmentTree<T>::build(std::vector<T>& arr, int curr, int start, int end)
    {
        if (start == end)
        {
            if (curr < (int)m_tree.size())
            {
                m_tree[curr] = { arr[start], 1 };
            }

            return;
        }

        int mid = (start + end) / 2;
        int leftChild = curr * 2 + 1;
        int rightChild = curr * 2 + 2;

        build(arr, leftChild, start, mid);
        build(arr, rightChild, mid + 1, end);

        if (m_tree[leftChild].minVal > m_tree[rightChild].minVal)
        {
            m_tree[curr] = { m_tree[rightChild].minVal, m_tree[rightChild].count };
        }
        else if (m_tree[leftChild].minVal < m_tree[rightChild].minVal)
        {
            m_tree[curr] = { m_tree[leftChild].minVal, m_tree[leftChild].count };
        }
        else
        {
            m_tree[curr] = { m_tree[leftChild].minVal, m_tree[leftChild].count + m_tree[rightChild].count };
        }
    }

    template <typename T>
    void MinSegmentTree<T>::build(int curr, int start, int end, bool isBinary /*= false*/)
    {
        if (start == end)
        {
            if (curr < (int)m_tree.size())
            {
                m_tree[curr] = { isBinary ? 0 : start, 1 };
            }

            return;
        }

        int mid = (start + end) / 2;
        int leftChild = curr * 2 + 1;
        int rightChild = curr * 2 + 2;

        build(leftChild, start, mid, isBinary);
        build(rightChild, mid + 1, end, isBinary);

        if (m_tree[leftChild].minVal > m_tree[rightChild].minVal)
        {
            m_tree[curr] = { m_tree[rightChild].minVal, m_tree[rightChild].count };
        }
        else if (m_tree[leftChild].minVal < m_tree[rightChild].minVal)
        {
            m_tree[curr] = { m_tree[leftChild].minVal, m_tree[leftChild].count };
        }
        else
        {
            m_tree[curr] = { m_tree[leftChild].minVal, m_tree[leftChild].count + m_tree[rightChild].count };
        }
    }
}

#endif // ALGORITHM_SEGMENT_TREE_HPP
