# Создание библиотеки из lib.c
add_library(mylib STATIC lib.c)

# Указываем, что заголовочный файл доступен для тех, кто использует библиотеку
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})