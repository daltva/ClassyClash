#include "raylib.h"

int main(int argc, char const *argv[])
{
    //Window Dimensions
    double windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    //Initializing Window
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash");

    //Map variable
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    float mgX{};

    SetTargetFPS(60);

    //Game
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    CloseWindow();

}
