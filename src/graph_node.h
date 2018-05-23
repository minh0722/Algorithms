#ifndef ALGORITHM_GRAPH_NODE
#define ALGORITHM_GRAPH_NODE

namespace algorithm
{
	struct Node
	{
		int from = 0;
		int to = 0;
		int weight = 0;

		Node(int f, int t, int w);
		bool operator<(const Node& n) const;
	};

    struct Nodev2
    {
        int num = 0; 
        int weight = 0;

        Nodev2(int n, int w);
        bool operator<(const Nodev2& n) const;
    };

}

#endif