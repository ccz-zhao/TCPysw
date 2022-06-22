file(GLOB_RECURSE ALL_CPP_FILE *.cpp)
file(GLOB_RECURSE ALL_Header_FILE *.h)

add_library(util ${ALL_CPP_FILE} ${ALL_Header_FILE})

target_include_directories(util INTERFACE .)