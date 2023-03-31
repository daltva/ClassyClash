#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main(int argc, char const *argv[])
{
    // Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initializing Window
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    // Map variable
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};

    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);

    // Game
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();
}
