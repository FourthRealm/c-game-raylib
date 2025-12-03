#include "raylib.h"
#include "GameEngine.h"
#include "Entity.h"
#include "RenderComponent.h"
#include <unistd.h>
#include <libgen.h>
#include <limits.h>

int main(void) {
    char exePath[PATH_MAX];
    uint32_t size = sizeof(exePath);
    if(_NSGetExecutablePath(exePath, &size) == 0) {
        chdir(dirname(exePath));
    }

    InitialiseEngine();

    EntityId id = CreateEntity((Vector2){100, 100}, (Vector2){200, 200});
    AddRenderComponent(id, LoadTexture("assets/TestTiles.png"), WHITE);

    while(IsGameRunning()) {
        UpdateEngine();
    }

    ShutdownEngine();
    CloseWindow();

    return 0;
}