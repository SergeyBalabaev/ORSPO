cmake_minimum_required(VERSION 3.16)
project(myapp)

# Добавление поддиректории с библиотекой
add_subdirectory(lib)

# Создание исполняемого файла
add_executable(myapp main.c)

# Линковка с библиотекой из поддиректории
target_link_libraries(myapp mylib)

# Добавление пути для поиска заголовочных файлов
target_include_directories(myapp PRIVATE lib)