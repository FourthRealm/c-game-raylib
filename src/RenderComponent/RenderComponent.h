#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <stddef.h>
#include <stdint.h>
#include "raylib.h"
#include "Entity.h"

#define InitialRendererArraySize 100

typedef struct {
    EntityId id;
    Texture texture;
    Color tint;
} RenderComponent;

EntityId AddRenderComponent(EntityId id, Texture texture, Color tint);

void ClearRendererArray(void);

/// @brief Get a render component by its ID.
RenderComponent* GetRenderComponent(EntityId id);

/// @brief Updates all render components currently in the renderer list.
void UpdateAllRenderComponents(void);

/// @brief Updates a render component.
static void UpdateRenderComponent(Entity* entity, RenderComponent* renderer);

/// @brief Dynamic array for components.
typedef struct {
    RenderComponent* data; ///< Stored data of the array.
    size_t size; ///< Current size of the array.
    size_t capacity; ///< Maximum size of the array before resize.
} RendererArray;

/// @brief Initialise array, allocating the specified memory.
void InitRendererArray(void);

/// @brief Clear renderer array and frees it's memory.
void FreeRendererArray(void);

/// @brief Add a renderer to the end of array.
static RenderComponent* AddRenderer(RenderComponent element);

/// @brief Dynamically resize array.
static void ResizeRendererArray(void);

#endif // RENDER_COMPONENT_H