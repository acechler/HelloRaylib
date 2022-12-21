#include <memory>
#include "Examples\RotatingShapes.cpp"
#include "Utilities\RaylibTimer.cpp"

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


struct Vector2 rngVector(){

    struct Vector2 localVector;
    localVector.x = GetRandomValue(1, GetScreenWidth());
    localVector.y = GetRandomValue(1, GetScreenHeight());
    return localVector;
}


// This seems to be on the right track -> https://stackoverflow.com/questions/15678823/passing-vector-of-struct-to-function
void drawGraph(Graph const &graph, std::vector<Vector2> &locations, int size){

    const Vector2 RECT_SIZE{32,32};
    for(int i = 0; i < size; ++i){
        DrawRectangleV(locations.at(i), RECT_SIZE, WHITE);
        for(int v: graph.adjacencyList[i]){
            DrawLineV(locations.at(i), locations.at(v), RED);
        }
    }
}

int main()
{
    // RotatingShapes::test();
    // RaylibTimer::test();
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "HelloRaylib");
    SetTargetFPS(60);
    std::vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    int totalEdges = edges.size() - 1;
    Graph graph(edges, totalEdges);
    std::vector<Vector2> locations(totalEdges);
    
    for (auto &location : locations){
        location = rngVector();
    }


    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        drawGraph(graph, locations, totalEdges);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}