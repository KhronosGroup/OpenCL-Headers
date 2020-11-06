cmake_minimum_required(VERSION 3.0)

project(PkgConfigTest
  LANGUAGES C
)

find_package(OpenCL
  REQUIRED
  CONFIG
  COMPONENTS Headers
)

add_executable(${PROJECT_NAME}
  ../pkgconfig.c
)

target_link_libraries(${PROJECT_NAME}
  OpenCL::Headers
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CL_TARGET_OPENCL_VERSION=120
)
