#include "raylib.h"
#include "GameEngine.h"
#include "Entity.h"
#include <stdio.h>

int main(void) {
    InitialiseEngine();

    CreateEntity(1, (Vec2){0, 0}, (Vec2){25, 25});
    CreateEntity(1, (Vec2){100, 50}, (Vec2){25, 25});
    CreateEntity(1, (Vec2){50, 200}, (Vec2){25, 25});

    while(IsGameRunning()) {
        UpdateEngine();
    }

    ShutdownEngine();
    CloseWindow();

    return 0;
}