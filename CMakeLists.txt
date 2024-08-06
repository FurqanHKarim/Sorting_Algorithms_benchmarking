cmake_minimum_required(VERSION 3.10)


project(Sorting_alogorithms_Benchmarking)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
)

add_subdirectory(
    ${PROJECT_SOURCE_DIR}/Time_Benchmarking
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/app/main.cpp)

target_link_libraries(${PROJECT_NAME} 
    Time_Benchmarking
    )
