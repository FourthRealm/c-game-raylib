#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Config.h"
#include "Entity.h"

/// @brief Initialise all systems
void InitialiseEngine(void);

/// @brief Update all systems
void UpdateEngine(void);

/// @brief Free memory and shut down systems
void ShutdownEngine(void);

/// @brief Determines if the game is running
bool IsGameRunning(void);

#endif // GAME_ENGINE_H