cmake_minimum_required(VERSION 3.10)
project(Forgotten_World)

include(FetchContent)

# Fetch SFML
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Fetch ImGui
FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

# Fetch ImGui-SFML
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG master
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/Lua)
include_directories(${CMAKE_SOURCE_DIR}/src/client/states)
include_directories(${CMAKE_SOURCE_DIR}/src/client)

# Link ENet (cross-platform)
if(WIN32)
    link_directories(${CMAKE_SOURCE_DIR}/lib)
endif()

set(CLIENT_SOURCES 
    ${CMAKE_SOURCE_DIR}/src/client/main.cpp
    ${CMAKE_SOURCE_DIR}/src/client/Player.cpp
    ${CMAKE_SOURCE_DIR}/src/client/Entity.cpp
    ${CMAKE_SOURCE_DIR}/src/client/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/client/states/State.cpp
    ${CMAKE_SOURCE_DIR}/src/client/states/GameState.cpp
    ${CMAKE_SOURCE_DIR}/src/client/states/MainMenu.cpp
)

# Add executables
add_executable(Forgotten_World ${CLIENT_SOURCES})
add_executable(server ${CMAKE_SOURCE_DIR}/src/server/server.cpp)

# Link ENet library
if(WIN32)
    target_link_libraries(server enet64 ws2_32 winmm)
else()
    find_library(ENET_LIBRARY enet)
    if(NOT ENET_LIBRARY)
        message(FATAL_ERROR "Could not find ENet library. Install libenet-dev.")
    endif()
    target_link_libraries(server ${ENET_LIBRARY})
endif()

# Cross-platform Lua linking
if(WIN32)
    target_link_libraries(Forgotten_World PRIVATE SFML::Graphics SFML::Audio ImGui-SFML::ImGui-SFML ${CMAKE_SOURCE_DIR}/lib/lua54.lib)
else()
    find_package(Lua REQUIRED)
    target_link_libraries(Forgotten_World PRIVATE SFML::Graphics SFML::Audio ImGui-SFML::ImGui-SFML ${LUA_LIBRARIES})
    include_directories(${LUA_INCLUDE_DIR})
endif()

# Copy assets & config after build
add_custom_command(
    TARGET Forgotten_World POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/assets
    $<TARGET_FILE_DIR:Forgotten_World>/assets
    COMMENT "Copying assets folder to runtime directory"
)
add_custom_command(
    TARGET Forgotten_World POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/config
    $<TARGET_FILE_DIR:Forgotten_World>/config
)
