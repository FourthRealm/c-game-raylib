#include "GameEngine.h"
#include <stdio.h>

int main(void) {
    InitialiseEngine();

    CreateEntity(ENTITY_STATIC, (Vector2){0, 0}, (Vector2){25, 25}, NULL, 0);
    CreateEntity(ENTITY_STATIC, (Vector2){100, 50}, (Vector2){25, 25}, NULL, 0);
    CreateEntity(ENTITY_DYNAMIC, (Vector2){50, 200}, (Vector2){25, 25}, NULL, 100);

    while(IsGameRunning()) {
        UpdateEngine();
    }

    ShutdownEngine();
    CloseWindow();

    return 0;
}