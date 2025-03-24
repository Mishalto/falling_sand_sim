add_executable(falling_sand_sim main.cpp)
add_subdirectory(Сore)

target_link_libraries(falling_sand_sim PRIVATE core)
target_include_directories(falling_sand_sim PRIVATE ${CMAKE_SOURCE_DIR}/include)
