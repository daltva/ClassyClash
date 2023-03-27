#include "raylib.h"
#include "raymath.h"

int main(int argc, char const *argv[])
{
    //Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    //Initializing Window
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    //Map variable
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};

    //speed variable
    float speed{4.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };

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

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // draw the character
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro (knight, source, dest, Vector2{}, 0.f, WHITE); 

        EndDrawing();
    }
    CloseWindow();

}
