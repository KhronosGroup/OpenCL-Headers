set(CPACK_PACKAGE_VENDOR "khronos")

set(CPACK_PACKAGE_DESCRIPTION "OpenCL (Open Computing Language) C header files")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if(NOT CPACK_PACKAGING_INSTALL_PREFIX)
  set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

# DEB packaging configuration
set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_VENDOR})

set(CPACK_DEBIAN_PACKAGE_HOMEPAGE
    "https://github.com/KhronosGroup/OpenCL-Headers")

# Version number [epoch:]upstream_version[-debian_revision]
set(LATEST_RELEASE_VERSION "2023.04.17")
set(CPACK_DEBIAN_PACKAGE_VERSION "${PROJECT_VERSION}~${LATEST_RELEASE_VERSION}")  # upstream_version
set(CPACK_DEBIAN_PACKAGE_RELEASE "1") # debian_revision (because this is a
                                      # non-native pkg)
set(PACKAGE_VERSION_REVISION "${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}")

set(DEBIAN_PACKAGE_NAME "opencl-c-headers")
set(CPACK_DEBIAN_PACKAGE_NAME
    "${DEBIAN_PACKAGE_NAME}"
    CACHE STRING "Package name" FORCE)

# Get architecture
execute_process(COMMAND dpkg "--print-architecture" OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
string(STRIP "${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}" CPACK_DEBIAN_PACKAGE_ARCHITECTURE)

# Package file name in deb format:
# <PackageName>_<VersionNumber>-<DebianRevisionNumber>_<DebianArchitecture>.deb
set(CPACK_DEBIAN_FILE_NAME "${CPACK_PACKAGE_VENDOR}-${DEBIAN_PACKAGE_NAME}_${PACKAGE_VERSION_REVISION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb")

set(CPACK_DEBIAN_PACKAGE_DEBUG ON)

include(CPack)
