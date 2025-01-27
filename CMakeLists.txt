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

# Link against ENet library
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add executables
add_executable(client ${CMAKE_SOURCE_DIR}/src/client/client.cpp)
add_executable(server ${CMAKE_SOURCE_DIR}/src/server/server.cpp)

# Link ENet library to executables
if(WIN32)
    target_link_libraries(client enet64)
    target_link_libraries(server enet64)
    # Windows also needs ws2_32 and winmm
    target_link_libraries(client ws2_32 winmm)
    target_link_libraries(server ws2_32 winmm)
else()
    target_link_libraries(client enet)
    target_link_libraries(server enet)
endif()