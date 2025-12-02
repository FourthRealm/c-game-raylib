add_library(ConfigLib STATIC Config.c Config.h)
target_include_directories(ConfigLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})