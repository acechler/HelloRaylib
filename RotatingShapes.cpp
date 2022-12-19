#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <raylib.h>
#include <raymath.h>

class RotatingShapes
{
private:
    std::vector<Vector2> vectors;

public:
    RotatingShapes(std::vector<Vector2> vectors)
    {
        this->vectors = vectors;
        for (auto it = std::begin(this->vectors); it != std::end(this->vectors); ++it)
        {
            it->x = GetRandomValue(1, 800);
            it->y = GetRandomValue(1, 600);
        }
    }

    void update()
    {
        for (auto it = std::begin(this->vectors); it != std::end(this->vectors); ++it)
        {
            it->x += cos(it->y / 100);
            it->y -= cos(it->x / 100);
        }
    }

    void draw()
    {
        for (auto it = std::begin(this->vectors); it != std::end(this->vectors); ++it)
        {
            DrawRectangleLines(it->x, it->y, 25, 25, RED);
            // DrawText(TextFormat("x: %08i", v.x), 200, 120, 20, GREEN);
        }
    }
    ~RotatingShapes() {}
};