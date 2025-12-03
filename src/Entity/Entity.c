#include "Entity.h"
#include <stdlib.h>

static EntityArray entities;
static EntityId nextEntityId = 1;

EntityId CreateEntity(Vector2 position, Vector2 size) {
    // Create the required entity data.
    // Rotation, velocity, and color are defualted.
    Entity entityData = {nextEntityId, position, 0, size};

    nextEntityId++;

    // Add entity returns the pointer to the item in the array
    return AddEntity(entityData)->id;
}

void DestroyAllEntities(void) {
    FreeEntityArray();
    InitEntityArray();
}

Entity* GetEntityById(EntityId id) {
    for(size_t i = 0; i < entities.size; i++) {
        if(entities.data[i].id == id)
            return &entities.data[i];
    }

    // No entity found with id
    return NULL;
}

void InitEntityArray() {
    // Allocate memory
    entities.data = (Entity*)malloc(InitialEntityArraySize * sizeof(Entity));

    // Ensure the array isn't empty
    if(entities.data == NULL)
        exit(EXIT_FAILURE);

    entities.size = 0;
    entities.capacity = InitialEntityArraySize;
}

void FreeEntityArray() {
    free(entities.data);

    // Reset all members
    entities.data = NULL;
    entities.size = 0;
    entities.capacity = 0;
}

static Entity* AddEntity(Entity element) {
    // Resize if capacity has been reached
    if(entities.size == entities.capacity)
        ResizeEntityArray();

    entities.data[entities.size] = element;

    // Get the reference to the newly added item
    Entity* reference = &entities.data[entities.size];

    entities.size++;

    return reference;
}

static void ResizeEntityArray() {
    size_t newCapacity = entities.capacity * 2;

    // Reallocate memory
    Entity* newData = (Entity*)realloc(entities.data, newCapacity * sizeof(Entity));

    // Ensure the array isn't empty
    if(newData == NULL)
        exit(EXIT_FAILURE);

    entities.data = newData;
    entities.capacity = newCapacity;
}

EntityArray GetEntities() {
    return entities;
}