# prasaran

Build instructions

1. Install CMake latest version.
2. Go to the project root directory.
3. Execute these commands to build the project
```
mkdir build
cd build
cmake ..
make -j4
```
4. Execute the binary generated in the build directory.
5. Directory structure of the project should be as follows.
```
  prasaran
    /src              // All the source code, library and utilities
    /test             // Your test files that will use the library (Also, helpful for someone who uses the library)
    /build            // Run cmake and make in this directory, this directory should not be commited. 
    /CMakeLists.txt   // List file for cmake
    /README.md        // Project readme file.
```
