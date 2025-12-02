#include "GameEngine.h"
#include "Entity.h"
#include <stdio.h>

int main(void) {
    InitialiseEngine();

    CreateEntity(true, (Vector2){0, 0}, (Vector2){25, 25});
    CreateEntity(true, (Vector2){100, 50}, (Vector2){25, 25});
    CreateEntity(true, (Vector2){50, 200}, (Vector2){25, 25});

    while(IsGameRunning()) {
        UpdateEngine();
    }

    ShutdownEngine();
    CloseWindow();

    return 0;
}