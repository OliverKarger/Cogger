file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cc)
set(SOURCES ${SOURCES})

add_executable(CoggerDemo ${SOURCES})

target_link_libraries(CoggerDemo Cogger)