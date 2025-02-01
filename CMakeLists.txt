cmake_minimum_required(VERSION 3.10)
project(Forgotten_World)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG master
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)


# Add ENet include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/Lua)
include_directories(${CMAKE_SOURCE_DIR}/src/client/states)
include_directories(${CMAKE_SOURCE_DIR}/src/client)
# Link against ENet library
link_directories(${CMAKE_SOURCE_DIR}/lib)



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
add_executable(Forgotten_World  ${CLIENT_SOURCES})
add_executable(server ${CMAKE_SOURCE_DIR}/src/server/server.cpp)

# Link ENet library to executables
if(WIN32)
    target_link_libraries(server enet64)
    # Windows also needs ws2_32 and winmm
    target_link_libraries(server ws2_32 winmm)
else()
    target_link_libraries(server enet)
endif()

target_link_libraries(Forgotten_World PRIVATE SFML::Graphics SFML::Audio ImGui-SFML::ImGui-SFML ${CMAKE_SOURCE_DIR}/lib/lua54.lib)


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
    ${CMAKE_SOURCE_DIR}/src/config $<TARGET_FILE_DIR:Forgotten_World>/config
)
