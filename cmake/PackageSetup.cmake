set(CPACK_PACKAGE_VENDOR "khronos")

set(CPACK_PACKAGE_DESCRIPTION "OpenCL (Open Computing Language) C header files
OpenCL (Open Computing Language) is a multi-vendor open standard for
general-purpose parallel programming of heterogeneous systems that include
CPUs, GPUs and other processors.
.
This package provides the C development header files for the OpenCL API
as published by The Khronos Group Inc.  The corresponding specification and
documentation can be found on the Khronos website.")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if(NOT CPACK_PACKAGING_INSTALL_PREFIX)
  set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

# DEB packaging configuration
if(NOT DEFINED CPACK_DEBIAN_PACKAGE_MAINTAINER)
  set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_VENDOR})
endif()

set(CPACK_DEBIAN_PACKAGE_HOMEPAGE
    "https://github.com/KhronosGroup/OpenCL-Headers")

# Version number [epoch:]upstream_version[-debian_revision]
set(CPACK_DEBIAN_PACKAGE_VERSION "${PROJECT_VERSION}")  # upstream_version
if(DEFINED LATEST_RELEASE_VERSION)
    # Remove leading "v", if exists
    string(LENGTH "${LATEST_RELEASE_VERSION}" LATEST_RELEASE_VERSION_LENGTH)
    string(SUBSTRING "${LATEST_RELEASE_VERSION}" 0 1 LATEST_RELEASE_VERSION_FRONT)
    if(LATEST_RELEASE_VERSION_FRONT STREQUAL "v")
        string(SUBSTRING "${LATEST_RELEASE_VERSION}" 1 ${LATEST_RELEASE_VERSION_LENGTH} LATEST_RELEASE_VERSION)
    endif()

  string(APPEND CPACK_DEBIAN_PACKAGE_VERSION "~${LATEST_RELEASE_VERSION}")
endif()
set(CPACK_DEBIAN_PACKAGE_RELEASE "1") # debian_revision (because this is a
                                      # non-native pkg)
set(PACKAGE_VERSION_REVISION "${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}${DEBIAN_VERSION_SUFFIX}")

set(DEBIAN_PACKAGE_NAME "opencl-c-headers")
set(CPACK_DEBIAN_PACKAGE_NAME
    "${DEBIAN_PACKAGE_NAME}"
    CACHE STRING "Package name" FORCE)

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
set(CPACK_DEBIAN_PACKAGE_SECTION "libdevel")
set(CPACK_DEBIAN_PACKAGE_BREAKS "opencl-headers (<< ${CPACK_DEBIAN_PACKAGE_VERSION}), opencl-clhpp-headers (<< ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_PACKAGE_REPLACES "opencl-headers (<< ${CPACK_DEBIAN_PACKAGE_VERSION})")

# Package file name in deb format:
# <PackageName>_<VersionNumber>-<DebianRevisionNumber>_<DebianArchitecture>.deb
set(CPACK_DEBIAN_FILE_NAME "${DEBIAN_PACKAGE_NAME}_${PACKAGE_VERSION_REVISION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb")
