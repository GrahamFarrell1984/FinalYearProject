project(game)

if (WIN32)
    set(SFML_DIR "C:/Library/SFML-2.5.1/lib/cmake/SFML")
elseif (APPLE)
    set(SFML_DIR "./library/frameworks/SFML-2.5.1/lib/cmake/SFML")
elseif (UNIX AND NOT APPLE)
    set(SFML_DIR "/usr/lib/arm-linux-gnueabihf/cmake/SFML")
endif ()

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Using GLOB requires us to reload this CMake file every time we add new .cpp files.
file(GLOB FILES_SRC "main.cpp" "*.cpp" "*/*.cpp")

add_executable(${PROJECT_NAME} ${FILES_SRC})

# Add project include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/input)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/scenes)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/managers)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Copy assets folder to source to the build directory:
FILE(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
