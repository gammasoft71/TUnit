cmake_minimum_required(VERSION 3.3)

#Project
project(tunit.manual_tests)
set(SOURCES
  src/manual_tests.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tunit/tests")
