# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/_deps/picotool-src")
  file(MAKE_DIRECTORY "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/_deps/picotool-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/_deps/picotool-build"
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/_deps"
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/tmp"
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/src/picotoolBuild-stamp"
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/src"
  "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Mmiud/Documents/IoT_laitteiden_oliot/lab5/pico_minimal_cpp/cmake-build-debug/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
