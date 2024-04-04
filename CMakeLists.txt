# CMakeList.txt : CMake project for SetCpp, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.13)

project (UnorderedSet VERSION 1.0 LANGUAGES CXX)

if(MSVC)
    # Генерируем статическую заглушку для динамических биб "src/main.cpp"лиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(Set STATIC "src/include/unordered_set.cpp")
target_include_directories(Set PUBLIC "include")
# Add source to this project's executable.
add_executable (UnorderedSet "src/main.cpp")

target_link_libraries(UnorderedSet Set)
