# Cmake configs
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

# Project configs
project(AppLibrary)

# Variables
set(SOURCE_FILES pch.h MainFrame.cpp MainFrame.h View.cpp View.h)

# Grab the wxWidget library and include the use file
# Additionally, turn off wxWidget's built-in precompiled headers
set(wxBUILD_PRECOMP_OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

# Add source files to this library
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Link required libraries to this library
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Add precompiled headers to the project
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)


