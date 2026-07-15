target_sources(${PROJECT_NAME}
        PRIVATE
            Compiler.cpp
            Memory.cpp
            Strategija.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME}
        PRIVATE
            simulationEngine
)