#include "RotatingRectangles.cpp"




typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime){
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer){
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer){
    return GetTime() - timer.startTime;
}

void timerExample(){
    Timer myTimer = {0,5};
    StartTimer(&myTimer, myTimer.lifeTime);

    while (WindowShouldClose() == false){

        // // if(TimerDone(myTimer)){
        // //     for (auto it = begin (vectors); it != end (vectors); ++it) {
        // //         it->x =  GetRandomValue(1, 800);
        // //         it->y =  GetRandomValue(1, 600);
        // //     }
        // //     StartTimer(&myTimer, myTimer.lifeTime);
        // // }

       
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();       
    }

}


int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    
    std::vector<Vector2> vectors(100);
    RotatingRectangles rect(vectors);

    InitWindow(screenWidth, screenHeight, "HelloRaylib");
    SetTargetFPS(60);

    // Timer myTimer = {0,5};
    // StartTimer(&myTimer, myTimer.lifeTime);

    while (WindowShouldClose() == false){

        // if(TimerDone(myTimer)){
        //     for (auto it = begin (vectors); it != end (vectors); ++it) {
        //         it->x =  GetRandomValue(1, 800);
        //         it->y =  GetRandomValue(1, 600);
        //     }
        //     StartTimer(&myTimer, myTimer.lifeTime);
        // }

        rect.update();
        BeginDrawing();
        ClearBackground(BLACK);
        rect.draw();
        EndDrawing();       
    }


    CloseWindow();
    return 0;
}