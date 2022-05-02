# Add a test for a given source file for each version of OpenCL
function(add_header_test NAME SOURCE)
  # Some headers include system files which require anonymous structs
  # so we cannot test them with /Za:
  set(TEST_SKIP_ANSI_TESTING
    cl_d3d10_h cl_d3d11_h cl_dx9_media_sharing_h cl_dx9_media_sharing_intel_h cl_icd_h cl_layer_h)
  get_filename_component(LANG_DIR "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
  if(LANG_DIR MATCHES cpp)
    set(CPP_SOURCE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${SOURCE}pp")
    file(RELATIVE_PATH REL_SOURCE_PATH "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/../${SOURCE}")
    file(TO_NATIVE_PATH "${REL_SOURCE_PATH}" NATIVE_SOURCE_PATH)
    file(WRITE
      "${CPP_SOURCE_PATH}"
      "#include \"${NATIVE_SOURCE_PATH}\"\n"
    )
    set(SOURCE_PATH "${CPP_SOURCE_PATH}")
    set(LANG cpp)
  else()
    set(SOURCE_PATH "../${SOURCE}")
    set(LANG c)
  endif()
  foreach(VERSION 100 110 120 200 210 220 300)
    set(TEST_EXE ${NAME}_${LANG}_${VERSION})
    list(FIND TEST_SKIP_ANSI_TESTING ${NAME} TEST_SKIP_INDEX)
    if(NOT (${TEST_SKIP_INDEX} GREATER -1 AND MSVC AND CMAKE_C_FLAGS MATCHES "/Za"))
      add_executable(${TEST_EXE} "${SOURCE_PATH}")
      target_compile_definitions(${TEST_EXE}
        PUBLIC -DCL_TARGET_OPENCL_VERSION=${VERSION}
      )
      target_include_directories(${TEST_EXE}
        PUBLIC ${PROJECT_SOURCE_DIR}
      )
      add_test(NAME ${TEST_EXE} COMMAND ${TEST_EXE})
    endif()
  endforeach(VERSION)
endfunction(add_header_test)

add_subdirectory(lang_c)
if(OPENCL_HEADERS_BUILD_CXX_TESTS)
  enable_language(CXX)
  add_subdirectory(lang_cpp)
endif()
