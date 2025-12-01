#include "GameEngine.h"

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

bool IsGameRunning(void) {
    return !WindowShouldClose();
}