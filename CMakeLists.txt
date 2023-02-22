cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.0...3.22)

# Include guard for including this project multiple times
if(TARGET Headers)
  return()
endif()

project(OpenCLHeaders
  VERSION 2.2
  LANGUAGES C # Ideally should be NONE, but GNUInstallDirs detects platform arch using try_compile
  # https://stackoverflow.com/questions/43379311/why-does-project-affect-cmakes-opinion-on-cmake-sizeof-void-p
)

option(OPENCL_HEADERS_BUILD_TESTING "Enable support for OpenCL C headers testing." OFF)
option(OPENCL_HEADERS_BUILD_CXX_TESTS "Enable support for OpenCL C headers testing in C++ mode." ON)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(JoinPaths)

include(GNUInstallDirs)

add_library(Headers INTERFACE)
add_library(OpenCL::Headers ALIAS Headers)

if(CMAKE_SYSTEM_NAME MATCHES Darwin)
  execute_process(
    COMMAND ln -snf ${CMAKE_CURRENT_SOURCE_DIR}/CL ${CMAKE_CURRENT_BINARY_DIR}/CL
    COMMAND ln -snf ${CMAKE_CURRENT_SOURCE_DIR}/CL ${CMAKE_CURRENT_BINARY_DIR}/OpenCL
  )
  target_include_directories(Headers
    INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )
  install(CODE "
    file(MAKE_DIRECTORY  ${CMAKE_INSTALL_FULL_INCLUDEDIR}/CL)
    execute_process(
      COMMAND ln -snf CL ${CMAKE_INSTALL_FULL_INCLUDEDIR}/OpenCL
    )"
  )
else()
  target_include_directories(Headers
    INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )
endif()

install(
  TARGETS Headers
  EXPORT OpenCLHeadersTargets
)
install(
  DIRECTORY CL
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

export(
  EXPORT OpenCLHeadersTargets
  FILE ${PROJECT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersTargets.cmake
  NAMESPACE OpenCL::
)
file(
  WRITE ${PROJECT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfig.cmake
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/OpenCLHeadersTargets.cmake\")"
)

set(config_package_location ${CMAKE_INSTALL_DATADIR}/cmake/OpenCLHeaders)
install(
  EXPORT OpenCLHeadersTargets
  FILE OpenCLHeadersTargets.cmake
  NAMESPACE OpenCL::
  DESTINATION ${config_package_location}
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfig.cmake
  DESTINATION ${config_package_location}
)

unset(CMAKE_SIZEOF_VOID_P)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfigVersion.cmake
  DESTINATION ${config_package_location}
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR OPENCL_HEADERS_BUILD_TESTING)
  include(CTest)
endif()
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR OPENCL_HEADERS_BUILD_TESTING) AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

join_paths(OPENCL_INCLUDEDIR_PC "\${prefix}" "${CMAKE_INSTALL_INCLUDEDIR}")

configure_file(OpenCL-Headers.pc.in OpenCL-Headers.pc @ONLY)
set(pkg_config_location ${CMAKE_INSTALL_DATADIR}/pkgconfig)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/OpenCL-Headers.pc
  DESTINATION ${pkg_config_location})
