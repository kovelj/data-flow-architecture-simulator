add_library(simulationEngine STATIC)
add_library(tsslib STATIC)

add_subdirectory(implementation)

target_link_libraries(tsslib PUBLIC simulationEngine)