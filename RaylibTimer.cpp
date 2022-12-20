#include <raylib.h>

class RaylibTimer
{
private:
    double startTime; // Start Time (seconds)
    double lifeTime;  // Lifetime (seconds)
public:
    RaylibTimer(double startTime = 0, double lifeTime = 5) {
        this->startTime = startTime;
        this->lifeTime = lifeTime;
    }

    void StartTimer(double lifetime){
        this->startTime = GetTime();
        this->lifeTime = lifetime;
    }
    void StartTimer(){
        this->startTime = GetTime();
    }

    bool TimerDone(){
        return GetTime() - this->startTime >= this->lifeTime;
    }

    double GetElapsed(){
        return GetTime() - this->startTime;
    }

    static void test(const int screenWidth = 800, const int screenHeight = 600){
        RaylibTimer myTimer(0,5);
        myTimer.StartTimer();

        InitWindow(screenWidth, screenHeight, "HelloRaylib");
        SetTargetFPS(60);

        while (WindowShouldClose() == false){

            BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("x: %08f", myTimer.GetElapsed()), 200, 120, 20, GREEN);
            if(myTimer.TimerDone()){
                myTimer.StartTimer();
            }
            EndDrawing();
        }
    }

    ~RaylibTimer() {}
};