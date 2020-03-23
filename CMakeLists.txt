cmake_minimum_required(VERSION 3.0)
project(OpenCLHeaders VERSION 2.2 LANGUAGES NONE)

add_library(OpenCLHeaders INTERFACE)
add_library(OpenCL::OpenCLHeaders ALIAS OpenCLHeaders)
target_include_directories(OpenCLHeaders INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:include>
)

install(TARGETS OpenCLHeaders EXPORT OpenCLHeadersTargets)

include(GNUInstallDirs)

install(DIRECTORY "CL" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
export(EXPORT OpenCLHeadersTargets
  FILE "${PROJECT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersTargets.cmake"
  NAMESPACE OpenCL::
)
file(WRITE "${PROJECT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfig.cmake"
	"include(\"\${CMAKE_CURRENT_LIST_DIR}/OpenCLHeadersTargets.cmake\")"
)

set(config_package_location ${CMAKE_INSTALL_DATADIR}/cmake/OpenCLHeaders)
install(EXPORT OpenCLHeadersTargets
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
  "${CMAKE_CURRENT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/OpenCLHeaders/OpenCLHeadersConfigVersion.cmake"
  DESTINATION ${config_package_location}
)
