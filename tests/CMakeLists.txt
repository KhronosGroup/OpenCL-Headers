# Add a test for a given source file for each version of OpenCL
function(add_header_test NAME SOURCE)
  # Some headers include system files which require anonymous structs
  # so we cannot test them with /Za:
  set(TEST_SKIP_ANSI_TESTING
    cl_d3d10_h cl_d3d11_h cl_dx9_media_sharing_h cl_dx9_media_sharing_intel_h cl_icd_h cl_layer_h)
  get_filename_component(LANG_DIR "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
  if(LANG_DIR MATCHES cpp)
    set_source_files_properties("../${SOURCE}"
      PROPERTIES LANGUAGE CXX
    )
    set(LANG cpp)
  else()
    set(LANG c)
  endif()
  foreach(VERSION 100 110 120 200 210 220 300)
    set(TEST_EXE ${NAME}_${LANG}_${VERSION})
    list(FIND TEST_SKIP_ANSI_TESTING ${NAME} TEST_SKIP_INDEX)
    if(NOT (${TEST_SKIP_INDEX} GREATER -1 AND MSVC AND CMAKE_C_FLAGS MATCHES "/Za"))
      add_executable(${TEST_EXE} "../${SOURCE}")
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
