#include "Examples\RotatingShapes.cpp"
#include "Utilities\RaylibTimer.cpp"


int main()
{
    //RotatingShapes::test();
    //RaylibTimer::test();
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "HelloRaylib");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}