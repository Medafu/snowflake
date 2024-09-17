#include <iostream>
#include <cmath>
#include "raylib.h"

#define SCREEN_FACTOR 80
#define BRANCH_COUNT 7
#define BRANCH_ANGLE 2.0 * PI / BRANCH_COUNT

const int screenWidth = 16 * 80;
const int screenHeight = 9 * 80;

void snowflake(Vector2 center, int hue, float length, float thickness, int depth) {

    if (depth <= 0) {
        return;
    }

    for (int i = 0; i < BRANCH_COUNT; i++) {
        Vector2 branch = {center.x + (float)cos(BRANCH_ANGLE * i) * length, center.y + (float)sin(BRANCH_ANGLE * i) * length};
        Color color = ColorFromHSV(hue, 1.0f, 1.0f);
        DrawLineEx(center, branch, thickness, color);
        snowflake(branch, hue - 40.0f, length * 0.5, thickness * 0.5f, depth - 1);
    }
}

int main() {

    InitWindow(screenWidth, screenHeight, "test");

    SetTargetFPS(60);

    Vector2 center = {GetScreenWidth() * 0.5, GetScreenHeight() * 0.5};
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        snowflake(center, 135, SCREEN_FACTOR * 2, 10.0f, 4);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
