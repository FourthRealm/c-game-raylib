#include "raylib.h"
#include "raymath.h"
#include "Entity.h"
#include <stdio.h>

int main(void) {
    InitEntityArray();
    
    CreateEntity(ENTITY_STATIC, (Vector2){0, 0}, (Vector2){5, 5});
    CreateEntity(ENTITY_STATIC, (Vector2){-5, -5}, (Vector2){5, 5});
    CreateEntity(ENTITY_DYNAMIC, (Vector2){10, 0}, (Vector2){5, 5});

    EntityArray entities = GetEntities();

    printf("%zu\n", entities.size);
    printf("%zu\n", entities.capacity);

    FreeEntityArray();

    return 0;
}