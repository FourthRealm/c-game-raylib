#include "GameEngine.h"
#include "raylib.h"
#include "Config.h"
#include "Entity.h"
#include "RenderComponent.h"

void InitialiseEngine(void) {
    InitWindow(GetWindowWidth(), GetWindowHeight(), "Game");
    SetTargetFPS(GetTargetFPS());

    InitEntityArray();
    InitRendererArray();
}

void UpdateEngine(void) {
    BeginDrawing();
    ClearBackground(BLACK);

    UpdateAllRenderComponents();

    EndDrawing();
}

void ShutdownEngine(void) {
    FreeEntityArray();
    FreeRendererArray();
}

uint8_t IsGameRunning(void) {
    return !WindowShouldClose();
}