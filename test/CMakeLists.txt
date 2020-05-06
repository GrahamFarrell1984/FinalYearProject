project(test)

# Using GLOB requires us to reload this CMake file every time we add new .cpp files.
file(GLOB FILES_SRC "main.cpp" "*.cpp" "*/*.cpp")
add_executable(test ${FILES_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ../src/)
