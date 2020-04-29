OpenCL-Headers/tests README
===========================

The test_headers.c test is designed to make sure that the various cl_typen types
work and conform to expectation for recent versions of cl_platform.h. Conforming
to these expectations make use of these types practical for developers writing
portable code.

The various tests ending in .h.c are there to verify that the various OpenCL
headers can compile stand alone. That is to ensure that they may be used a la
carte. This provides developers a lifeline in the case that some unneeded part
of OpenCL (e.g. cl/gl sharing) brings in a pile of symbols (e.g. all of OpenGL)
that collides with other headers needed by the application. It is also poor form
to require headers to be included in a particular order, especially if multiple
systems require they be included in mutually incompatible order. So, here we
require that each header can be used standalone so that the order is irrelevant.

We also check to make sure that the headers don't cause spurious warnings. These
tests are intended to be compiled using the most stringent compiler flags
available for the platform, within reason. All warnings should be errors and
extra warnings that it is expected developers are likely to use should be turned
on.
