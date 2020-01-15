cmake_minimum_required (VERSION 2.8.11)

project(OpenCL_Headers_Tests)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/..)

# Make sure headers do not produce warnings
add_compile_options(-Wall -Wextra -Werror -pedantic -Wno-format)

# Add a test for a given source file for each version of OpenCL
function(add_header_test NAME SOURCE)
  foreach(VERSION 100 110 120 200 210 220)
    set(TEST_EXE ${NAME}_${VERSION})
    add_executable(${TEST_EXE} ${SOURCE})
    target_compile_definitions(${TEST_EXE}
      PUBLIC -DCL_TARGET_OPENCL_VERSION=${VERSION}
    )
    add_test(NAME ${TEST_EXE} COMMAND ${TEST_EXE})
  endforeach(VERSION)
endfunction(add_header_test)

# Tests
add_header_test(cl_h test_cl.h.c)
add_header_test(cl_gl_h test_cl_gl.h.c)
add_header_test(cl_platform_h test_cl_platform.h.c)
add_header_test(cl_opencl_h test_opencl.h.c)
add_header_test(headers test_headers.c)
