#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include "raymath.h"
#include <stdlib.h> // For malloc, free, realloc
#include <stddef.h> // For size_t

#define InitialEntityArraySize 100

/// @brief Defines the classification of entity.
typedef enum {
    ENTITY_STATIC, ///< Entities that do not move or update position dynamically.
    ENTITY_DYNAMIC ///< Entities that update position and velocity every frame.
} EntityType;

/// @brief Represents a single game object or entity.
typedef struct {
    EntityType type; ///< The type of the entity (static or dynamic).
    Vector2 position; ///< Current position in world space.
    Vector2 velocity; ///< Current velocity (only relevant to dynamic entities).
    Vector2 size; ///< Dimensions of entity (for collisions/rendering).
} Entity;

/// @brief Adds a new entity to the dynamic entities array.
Entity* CreateEntity(EntityType type, Vector2 pos, Vector2 size);

/// @brief Empties the entity array.
void DestroyAllEntities(void);

/// @brief Updates all entities.
void UpdateEntities(void);

/// @brief Implementation of a dynamic array for entities.
typedef struct {
    Entity* data; ///< Stored data of the array.
    size_t size; ///< Current size of the array.
    size_t capacity; ///< Maximum size of the array before resize.
} EntityArray;

/// @brief Initialise an entity array, allocating the specified memory to the array.
void InitEntityArray(void);

/// @brief Clears an entity array and frees it's memory.
void FreeEntityArray(void);

/// @brief Add an entity to the end of array.
Entity* AddEntity(Entity element);

/// @brief Dynamically resize an entity array.
static void ResizeEntityArray(void);

/// @brief Get a copy of the current entities array. Use for debugging only.
EntityArray GetEntities();

#endif // ENTITY_H