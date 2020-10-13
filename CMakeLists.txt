cmake_minimum_required(VERSION 3.0)

project(OpenCLHeaders
  VERSION 2.2
  LANGUAGES C # Ideally should be NONE, but GNUInstallDirs detects platform arch using try_compile
  # https://stackoverflow.com/questions/43379311/why-does-project-affect-cmakes-opinion-on-cmake-sizeof-void-p
)

add_library(Headers INTERFACE)
target_include_directories(Headers
  SYSTEM
  BEFORE
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(
  TARGETS Headers
  EXPORT OpenCLHeadersTargets
)

include(GNUInstallDirs)

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

if(BUILD_TESTING)
  include(CTest)
  add_subdirectory(tests)
endif()
