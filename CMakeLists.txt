# CMake configs
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

# Project configs
project(GuiTemplate)

# Variables
set(SOURCE_FILES main.cpp App.h App.cpp)
set(APPLICATION_LIBRARY AppLibrary)

# Grab the wxWidget library and include the use file
# Additionally, turn off wxWidget's built-in precompiled headers
set(wxBUILD_PRECOMP_OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

# Add the application library to this project
add_subdirectory(${APPLICATION_LIBRARY})
include_directories(${APPLICATION_LIBRARY})


# Add build targets to the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${APPLICATION_LIBRARY})

# Add precompiled headers to the project
target_precompile_headers(${PROJECT_NAME} PRIVATE ./${APPLICATION_LIBRARY}/pch.h)