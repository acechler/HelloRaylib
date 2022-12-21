#include <memory>
#include "Examples\RotatingShapes.cpp"
#include "Utilities\RaylibTimer.cpp"
#include "Utilities\Graph.cpp"



struct Vector2 rngVector()
{

    struct Vector2 localVector;
    localVector.x = GetRandomValue(1, GetScreenWidth());
    localVector.y = GetRandomValue(1, GetScreenHeight());
    return localVector;
}

void drawGraph(Graph const &graph, std::vector<Vector2> &locations, int size)
{

    const Vector2 RECT_SIZE{32, 32};
    int halfWidth = RECT_SIZE.x / 2;
    int halfHeight = RECT_SIZE.y / 2;
    for (int i = 0; i < size; ++i)
    {
        DrawRectangleV(locations.at(i), RECT_SIZE, WHITE);
        DrawText(TextFormat("%01i", i), locations.at(i).x, locations.at(i).y, 20, GREEN);
        for (int v : graph.adjacencyList[i])
        {
            DrawCircle(locations.at(i).x + halfWidth, locations.at(i).y + halfHeight, 5.f, BLUE);

            DrawLine(locations.at(i).x + halfWidth, locations.at(i).y + halfHeight,
                     locations.at(v).x + halfWidth, locations.at(v).y + halfHeight,
                     WHITE);

            DrawCircle(locations.at(v).x + halfWidth, locations.at(v).y + halfHeight, 5.f, RED);
        }
    }
}


void drawingGraphTest(){
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "HelloRaylib");
    SetTargetFPS(60);
    std::vector<Edge> edges = {
        {0, 1}, {0, 2}, {1, 2}, {2, 1}, {3, 2}, {3, 4}, {3, 6}, {4, 5}, {5, 6}};
    int totalEdges = edges.size() - 1;
    Graph graph(edges, totalEdges);
    std::vector<Vector2> locations(totalEdges);

    for (auto &location : locations)
    {
        location = rngVector();
    }

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        drawGraph(graph, locations, totalEdges);
        EndDrawing();
    }

    CloseWindow();
}


int main()
{
    RotatingShapes::test();
    // RaylibTimer::test();

    // const int screenWidth = 800;
    // const int screenHeight = 600;
    // InitWindow(screenWidth, screenHeight, "HelloRaylib");
    // SetTargetFPS(60);
    // std::vector<Edge> edges = {
    //     {0, 1}, {0, 2}, {1, 2}, {2, 1}, {3, 2}, {3, 4}, {3, 6}, {4, 5}, {5, 6}};
    // int totalEdges = edges.size() - 1;
    // Graph graph(edges, totalEdges);
    // std::vector<Vector2> locations(totalEdges);

    // for (auto &location : locations)
    // {
    //     location = rngVector();
    // }

    // while (WindowShouldClose() == false)
    // {
    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //     drawGraph(graph, locations, totalEdges);
    //     EndDrawing();
    // }

    // CloseWindow();
    return 0;
}