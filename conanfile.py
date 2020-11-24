from conans import ConanFile, tools, CMake
import os


class OpenCLHeadersConan(ConanFile):
    name = "opencl-headers"
    version = "20190502"
    license = "Apache-2.0"
    author = "Khronos Group <webmaster@khronos.org>"
    url = "https://github.com/KhronosGroup/OpenCL-ICD-Loader"
    description = "Khronos OpenCL Headers"
    topics = ("khronos", "opencl", "headers")
    exports_sources = "CMakeLists.txt", "CL/*"
    no_copy_source = True

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()

    def package_id(self):
        self.info.header_only()