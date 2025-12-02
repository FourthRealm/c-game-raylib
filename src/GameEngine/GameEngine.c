#include "GameEngine.h"
#include "raylib.h"
#include "Config.h"
#include "Entity.h"

void InitialiseEngine(void) {
    InitWindow(GetWindowWidth(), GetWindowHeight(), "Game");
    SetTargetFPS(GetTargetFPS());

    InitEntityArray();
}

void UpdateEngine(void) {
    BeginDrawing();
    ClearBackground(BLACK);

    UpdateAllEntities();

    EndDrawing();
}

void ShutdownEngine(void) {
    FreeEntityArray();
}

uint8_t IsGameRunning(void) {
    return !WindowShouldClose();
}