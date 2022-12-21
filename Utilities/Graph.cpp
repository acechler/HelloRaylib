#include<vector>

typedef struct
{
    int src, dest;
} Edge;


class Graph
{

public:
    std::vector<std::vector<int>> adjacencyList;
    Graph(std::vector<Edge> const &edges, int size)
    {
        adjacencyList.resize(size);

        for (auto &edge : edges)
        {
            adjacencyList[edge.src].push_back(edge.dest);
            // uncomment the following code for undirected graph
            // adjacencyList[edge.dest].push_back(edge.src);
        }
    }

    ~Graph() {}
};
