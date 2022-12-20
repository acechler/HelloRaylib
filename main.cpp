#include <memory>
#include "Examples\RotatingShapes.cpp"
#include "Utilities\RaylibTimer.cpp"

typedef struct{
    int src, dest;
} Edge;



class Graph
{

public:
    std::vector<std::vector<int>> adjacencyList;
    Graph(std::vector<Edge> const &edges, int size) {
        adjacencyList.resize(size);

        for(auto &edge:edges){
            adjacencyList[edge.src].push_back(edge.dest);
            // uncomment the following code for undirected graph
            // adjacencyList[edge.dest].push_back(edge.src);
        }
    }

    std::vector<std::vector<int>> getList(){
        return this->adjacencyList;
    }

    ~Graph() {}
};

void drawGraph(Graph const &graph, int size){

    std::vector<Vector2> locations(size);

    for(auto& location: locations){
        location.x = GetRandomValue(1,GetScreenWidth());
        location.y = GetRandomValue(1,GetScreenHeight());
    }
    for(int i = 0; i < size; ++i){
        DrawRectangleV(locations[i],{32,32},WHITE);
        for(int v: graph.adjacencyList[i]){
            DrawLineV(locations[i],locations[v],GREEN);
        }
 
    }

        
}

int main()
{
    //RotatingShapes::test();
    //RaylibTimer::test();
    const int screenWidth = 800;
    const int screenHeight = 600;
    std::vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    int totalEdges = edges.size() - 1;
    Graph graph(edges,totalEdges);
    
    InitWindow(screenWidth, screenHeight, "HelloRaylib");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(BLACK);
        
        drawGraph(graph, totalEdges);
        
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}