file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cc)
set(SOURCES ${SOURCES})

add_library(Cogger SHARED ${SOURCES})