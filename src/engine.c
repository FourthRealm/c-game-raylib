#include "engine.h"
#include <stdlib.h>

// ================================
// Transform
// ================================

Transform NewTransform(Vector2 position, Vector2 scale) {
    return (Transform){position, scale};
}

Vector2 TransformLeft(Transform* transform) {
    return (Vector2){transform->position.x - (transform->scale.x / 2), transform->position.y};
}

Vector2 TransformRight(Transform* transform) {
    return (Vector2){transform->position.x + (transform->scale.x / 2), transform->position.y};
}

Vector2 TransformUp(Transform* transform) {
    return (Vector2){transform->position.x, transform->position.y - (transform->scale.y / 2)};
}

Vector2 TransformDown(Transform* transform) {
    return (Vector2){transform->position.x, transform->position.y + (transform->scale.y / 2)};
}

// ================================
// Collisions
// ================================

void NewCollisionData(CollisionData* array, size_t capacity) {
    free(array->data);

    array->data = (EntityId*)malloc(capacity * sizeof(EntityId));
    array->capacity = capacity;
    array->size = 0;
}

void AddCollisionData(CollisionData* array, EntityId collision) {
    // Resize
    if(array->size == array->capacity) {
        size_t newCapacity = array->capacity * 2;
        array->data = (EntityId*)realloc(array->data, newCapacity * sizeof(EntityId));
        array->capacity = newCapacity;
    }

    array->data[array->size++] = collision;
}

void CheckCollision(Entity* a, Entity* b, CollisionData* cacheLocation) {
    bool collision = !(TransformRight(&a->transform).x < TransformLeft(&b->transform).x ||
                       TransformLeft(&a->transform).x > TransformRight(&b->transform).x ||
                       TransformUp(&a->transform).y < TransformDown(&b->transform).y ||
                       TransformDown(&a->transform).y > TransformUp(&b->transform).y);

    if(collision)
        AddCollisionData(cacheLocation, b->id);
}

// ================================
// Entity
// ================================

static size_t currentEntityId = 1;

void NewEntityArray(EntityArray* array, size_t capacity) {
    free(array->data);

    array->data = (Entity*)malloc(capacity * sizeof(Entity));
    array->capacity = capacity;
    array->size = 0;
}

void AddEntity(EntityArray* array, Entity entity) {
    // Resize
    if(array->size == array->capacity) {
        size_t newCapacity = array->capacity * 2;
        array->data = (Entity*)realloc(array->data, newCapacity * sizeof(Entity));
        array->capacity = newCapacity;
    }

    array->data[array->size] = entity;
    Entity* ref = &array->data[array->size];

    // Run the entities start function
    ref->start(ref);

    // Add one to the arrays size.
    // This is done before setting id, because id's start at one.
    ref->id = ++array->size;
}

void CreateEntity(EntityArray* array, Vector2 position, EntityMethod start, EntityMethod update) {
    Entity entity = {0, 0,                       // Identification
                     {position, {1, 1}},         // Transform
                     (Vector2){0, 0}, NULL,      // Physics
                     false, WHITE,               // Rendering
                     start, update};             // Custom behaviour 
                     
    // Additional entity data will be set in the entity's start
    // method, which is called in add entity.
    AddEntity(array, entity);
}

Entity* GetEntityById(EntityArray* array, uint16_t id) {
    for(size_t i = 0; i < array->size; i++) {
        if(array->data[i].id == id)
            return &array->data[i];
    }

    return NULL;
}

void UpdateEntity(EntityArray* array, Entity* entity, float dt) {
    PhysicsStep(array, entity, dt);
    RenderEntity(entity);

    entity->update(entity);
}

// ================================
// Physics
// ================================

void PhysicsStep(EntityArray* array, Entity* entity, float dt) {
    Transform* transform = &entity->transform;

    transform->position.x += entity->velocity.x * dt;
    transform->position.y += entity->velocity.y * dt;

    // Calculate collisions
    NewCollisionData(entity->collisionData, COLLISION_DATA_START_CAPACITY);
    for(size_t i = 0; i < array->size; i++) {
        if(entity->id != array->data[i].id)
            CheckCollision(entity, array->data[i], entity->collisionData);
    }

    if(entity->collisionData->size > 0) {
        transform->position.x -= entity->velocity.x * dt;
        transform->position.y -= entity->velocity.y * dt;
    }
}

// ================================
// Rendering
// ================================

void RenderEntity(Entity* entity) {
    Transform* transform = &entity->transform;
    if(entity->isCircular) {
        DrawCircle(transform->position.x, transform->position.y, transform->scale.x, WHITE);
    }
    else {
        Vector2 topLeft = {TransformLeft(transform).x, TransformUp(transform).y};
        DrawRectangle(topLeft.x, topLeft.y, transform->scale.x, transform->scale.y, WHITE);
    }
}