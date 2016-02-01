cmake_minimum_required(VERSION 2.8.0)
project(decision_algorithm)

include_directories(.)

file(GLOB_RECURSE decision_algorithm_srcs
    "*.cpp"
)

add_library(decision_algorithm STATIC ${decision_algorithm_srcs})

set_property(TARGET decision_algorithm PROPERTY CXX_STANDARD 11)
set_target_properties(decision_algorithm PROPERTIES PREFIX "")
install(TARGETS decision_algorithm DESTINATION bin)

