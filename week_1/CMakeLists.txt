cmake_minimum_required(VERSION 3.8 FATAL_ERROR) # Можно поставить вместо 3.8,
                                                # ту что выдается по cmake --version
project(noder)

add_executable(noder src/main.cpp src/node.cpp)

# target_link_libraries(${PROJECT_NAME} PRIVATE libname1 libname2 libname3)
# Если нужна линковка с другими библиотеками

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
