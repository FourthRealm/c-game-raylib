#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <stddef.h>
#include <stdint.h>

#define InitialEntityArraySize 100

/// @brief Strong type for entity ID's.
typedef unsigned int EntityId;

/// @brief Represents a single game object or entity.
typedef struct {
    EntityId id; ///< Unique ID for the entity.
    uint8_t isDynamic : 1; ///< Dynamic entities are updated each frame (leave as false for non moving objects).

    Vector2 position; ///< Current position in world space.
    float rotation; ///< Current rotation in degrees.
    Vector2 size; ///< Dimensions of entity (for collisions/rendering).
} Entity;

/// @brief Adds a new entity to the dynamic entities array.
Entity* CreateEntity(uint8_t isDynamic, Vector2 pos, Vector2 size);

/// @brief Empties the entity array.
void DestroyAllEntities(void);

/// @brief Updates all entities.
void UpdateAllEntities(void);

/// @brief Updates an individual entity
static void UpdateEntity(Entity* entity);

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
static Entity* AddEntity(Entity element);

/// @brief Dynamically resize an entity array.
static void ResizeEntityArray(void);

/// @brief Get a copy of the current entities array. Use for debugging only.
EntityArray GetEntities();

#endif // ENTITY_H