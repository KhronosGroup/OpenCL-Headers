set(CPACK_PACKAGE_VENDOR "khronos")

set(CPACK_PACKAGE_DESCRIPTION "OpenCL API C headers")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if(NOT CPACK_PACKAGING_INSTALL_PREFIX)
  set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

if(NOT CPACK_SOURCE_IGNORE_FILES)
  set(CPACK_SOURCE_IGNORE_FILES="/.github/;/build/")
endif()

# DEB packaging configuration
set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_VENDOR})

set(CPACK_DEBIAN_PACKAGE_HOMEPAGE
    "https://github.com/KhronosGroup/OpenCL-Headers")

# Get Debian package name from project name
string(TOLOWER ${PROJECT_NAME} DEBIAN_PACKAGE_NAME)
string(REPLACE "opencl" "opencl-" DEBIAN_PACKAGE_NAME ${DEBIAN_PACKAGE_NAME})

# Version number [epoch:]upstream_version[-debian_revision]
set(CPACK_DEBIAN_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION}) # upstream_version
set(CPACK_DEBIAN_PACKAGE_RELEASE "1") # devian_revision (because this is a
                                      # non-native pkg)

set(CPACK_DEBIAN_PACKAGE_NAME
    "${CPACK_PACKAGE_VENDOR}-${DEBIAN_PACKAGE_NAME}"
    CACHE STRING "Package name" FORCE)

set(CPACK_DEBIAN_PACKAGE_FILE_NAME "${CPACK_DEBIAN_PACKAGE_NAME}-${CPACK_DEBIAN_PACKAGE_VERSION}")

# Package file name in deb format:
# <PackageName>_<VersionNumber>-<DebianRevisionNumber>_<DebianArchitecture>.deb
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

set(CPACK_DEBIAN_PACKAGE_DEBUG ON)

include(CPack)
