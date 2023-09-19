include("${CMAKE_CURRENT_LIST_DIR}/PackageSetup.cmake")

# Configuring pkgconfig

# We need two different instances of OpenCL-Headers.pc
# One for installing (cmake --install), which contains CMAKE_INSTALL_PREFIX as prefix
# And another for the Debian package, which contains CPACK_PACKAGING_INSTALL_PREFIX as prefix

join_paths(OPENCL_INCLUDEDIR_PC "\${prefix}" "${CMAKE_INSTALL_INCLUDEDIR}")

set(pkg_config_location ${CMAKE_INSTALL_DATADIR}/pkgconfig)
set(PKGCONFIG_PREFIX "${CMAKE_INSTALL_PREFIX}")
configure_file(
  OpenCL-Headers.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/pkgconfig_install/OpenCL-Headers.pc
  @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/pkgconfig_install/OpenCL-Headers.pc
  DESTINATION ${pkg_config_location}
  COMPONENT pkgconfig_install)

set(PKGCONFIG_PREFIX "${CPACK_PACKAGING_INSTALL_PREFIX}")
configure_file(
  OpenCL-Headers.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/pkgconfig_package/OpenCL-Headers.pc
  @ONLY)
# This install component is only needed in the Debian package
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/pkgconfig_package/OpenCL-Headers.pc
  DESTINATION ${pkg_config_location}
  COMPONENT pkgconfig_package
  EXCLUDE_FROM_ALL)

# By using component based packaging, component pkgconfig_install
# can be excluded from the package, and component pkgconfig_package
# can be included.
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_GROUPING "ALL_COMPONENTS_IN_ONE")

include(CPackComponent)
cpack_add_component(pkgconfig_install)
cpack_add_component(pkgconfig_package)
set(CPACK_COMPONENTS_ALL "Unspecified;pkgconfig_package")

set(CPACK_DEBIAN_PACKAGE_DEBUG ON)

include(CPack)
