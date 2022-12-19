#include "RotatingRectangles.cpp"




/// Original While Loop Code
    //    int ball_x = 100;
    //    int ball_y = 100;
    //    int ball_speed_x = 5;
    //    int ball_speed_y = 5;
    //    int ball_radius = 15;
    // while (WindowShouldClose() == false)
    // {
    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //     ball_x += ball_speed_x;
    //     ball_y += ball_speed_y;

    //     if (ball_x + ball_radius >= screenWidth || ball_x - ball_radius <= 0)
    //     {
    //         ball_speed_x *= -1;
    //     }

    //     if (ball_y + ball_radius >= screenHeight || ball_y - ball_radius <= 0)
    //     {
    //         ball_speed_y *= -1;
    //     }

    //     DrawCircle(ball_x, ball_y, ball_radius, WHITE);
    //     EndDrawing();
    // }


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