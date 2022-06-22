file(GLOB_RECURSE SOCKET_CC *.cpp)
file(GLOB_RECURSE SOCKET_HH *.h)

add_library(socket ${SOCKET_CC} ${SOCKET_HH})

target_include_directories(socket INTERFACE .)