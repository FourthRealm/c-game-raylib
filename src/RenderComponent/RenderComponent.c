#include "RenderComponent.h"
#include "stdlib.h"
#include "math.h"

static RendererArray renderers;

EntityId AddRenderComponent(EntityId id, Texture texture, Color tint) {
    RenderComponent data = {id, texture, tint};

    if(GetEntityById(id) == NULL)
        return InvalidEntityID;

    return AddRenderer(data)->id;
}

void ClearRendererArray(void) {
    FreeRendererArray();
    InitRendererArray();
}

RenderComponent* GetRenderComponent(EntityId id) {
    for(size_t i = 0; i < renderers.size; i++) {
        if(renderers.data[i].id == id)
            return &renderers.data[i];
    }

    // No entity found with id
    return NULL;
}

void UpdateAllRenderComponents(void) {
    for(size_t i = 0; i < renderers.size; i++) {
        RenderComponent* renderer = &renderers.data[i];
        UpdateRenderComponent(GetEntityById(renderer->id), renderer);
    }
}

static void UpdateRenderComponent(Entity* entity, RenderComponent* renderer) {
    float scale = entity->size.x / renderer->texture.width;
    DrawTextureEx(renderer->texture, entity->position, entity->rotation, scale, renderer->tint);
}

void InitRendererArray(void) {
    // Allocate memory
    renderers.data = (RenderComponent*)malloc(InitialRendererArraySize * sizeof(RenderComponent));

    // Ensure the array isn't empty
    if(renderers.data == NULL)
        exit(EXIT_FAILURE);

    renderers.size = 0;
    renderers.capacity = InitialRendererArraySize;
}

void FreeRendererArray(void) {
    free(renderers.data);

    renderers.data = NULL;
    renderers.size = 0;
    renderers.capacity = 0;
}

static RenderComponent* AddRenderer(RenderComponent element) {
    // Resize if capacity has been reached
    if(renderers.size == renderers.capacity)
        ResizeEntityArray();

    renderers.data[renderers.size] = element;

    // Get the reference to the newly added item
    RenderComponent* reference = &renderers.data[renderers.size];

    renderers.size++;

    return reference;
}

static void ResizeEntityArray() {
    size_t newCapacity = renderers.capacity * 2;

    // Reallocate memory
    RenderComponent* newData = (RenderComponent*)realloc(renderers.data, newCapacity * sizeof(RenderComponent));

    // Ensure the array isn't empty
    if(newData == NULL)
        exit(EXIT_FAILURE);

    renderers.data = newData;
    renderers.capacity = newCapacity;
}