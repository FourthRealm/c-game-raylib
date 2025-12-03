#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <stdint.h>
#include <stddef.h>

struct Entity;

typedef uint16_t EntityId;
typedef uint8_t EntityType;

// ================================
// Transform
// ================================

typedef struct Transform {
    Vector2 position;
    Vector2 scale;
} Transform;

Transform NewTransform(Vector2 position, Vector2 scale);
Vector2 TransformLeft(Transform* transform);
Vector2 TransformRight(Transform* transform);
Vector2 TransformUp(Transform* transform);
Vector2 TransformDown(Transform* transform);

// ================================
// Collisions
// ================================

#define COLLISION_DATA_START_CAPACITY 4

typedef struct CollisionData {
    EntityId* data;
    size_t size;
    size_t capacity;
} CollisionData;

void NewCollisionData(CollisionData* array, size_t capacity);
void AddCollisionData(CollisionData* array, EntityId id);
void CheckCollision(Entity* a, Entity* b, CollisionData* cacheLocation);

// ================================
// Entity
// ================================

typedef void (*EntityMethod)(struct Entity*);

typedef struct Entity {
    EntityId id;
    EntityType type;

    Transform transform;
    Vector2 velocity;
    CollisionData* collisionData;

    // Rendering
    bool isCircular;
    Color color;
    
    // Custom behaviour
    EntityMethod start;
    EntityMethod update;
} Entity;

typedef struct EntityArray {
    Entity* data;
    size_t size;
    size_t capacity;
} EntityArray;

void NewEntityArray(EntityArray* array, size_t capacity);
void AddEntity(EntityArray* array, Entity entity);

void CreateEntity(EntityArray* array, Vector2 position, EntityMethod start, EntityMethod update);
Entity* GetEntityById(EntityArray* array, uint16_t id);

void UpdateEntity(Entity* entity, float dt);
void PhysicsStep(Entity* entity, float dt);
void RenderEntity(Entity* entity);

#endif // ENTITY_H