project("Cogger")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED 17)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../../../build/archive)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../build/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../build/runtime)

add_compile_options(-Wall -pipe -Werror)
add_link_options(-static -static-libgcc -static-libstdc++ -Wl,-allow-multiple-definition -pipe  -Werror)

add_subdirectory(src/lib)
add_subdirectory(src/demo)
