#include "raylib.h"
#include "raymath.h"

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
    Vector2 mapPos{0.0, 0.0};

    //speed variable
    float speed{4.0};

    SetTargetFPS(60);

    //Game
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0);
        {
            // set mapPos = mapPos - direction
            Vector2Normalize(direction);
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    CloseWindow();

}
