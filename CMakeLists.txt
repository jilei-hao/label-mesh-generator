cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(label-mesh-generator)

set (CMAKE_CXX_STANDARD 11)


# configure ITK
set(ITK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/itk")
set(ITK_MODULES_ENABLED
  ITKCommon
  ITKImageIO
  ITKThresholding
  # add more modules here
)

set(BUILD_TESTING OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_SHARED_LIBS OFF)

# Find and include ITK with required modules
find_package(ITK REQUIRED COMPONENTS ${ITK_MODULES_ENABLED})
include(${ITK_USE_FILE})


# Add source files from this project
add_subdirectory(source bin)



