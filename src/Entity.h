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

/// @brief Strong type for entity ID's.
typedef unsigned int EntityId;

/// @brief Represents a single game object or entity.
typedef struct {
    EntityId id; ///< Unique ID for the entity
    EntityType type; ///< The type of the entity (static or dynamic).

    Vector2 position; ///< Current position in world space.
    float rotation; ///< Current rotation in degrees.
    Vector2 size; ///< Dimensions of entity (for collisions/rendering).

    Vector2 velocity; ///< Current velocity (only relevant to dynamic entities).

    Texture2D* texture; ///< Reference to the texture of this entity.
    Color colorTint; ///< Tint applied to this entity.

    int health; ///< Health of the entity.
} Entity;

/// @brief Adds a new entity to the dynamic entities array.
Entity* CreateEntity(EntityType type, Vector2 pos, Vector2 size, Texture2D* texture, int health);

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