add_library(core Engine.cpp Grain.cpp Sand.cpp)

target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(core SFML::Graphics)