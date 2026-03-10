# Task014 — Основы CMake 🔍

## Что такое CMake?

**`CMake (cross-platform make)`** — кроссплатформенное программное средство автоматизации сборки программного обеспечения из исходного кода. CMake не занимается непосредственно сборкой, а лишь генерирует файлы сборки (Makefile, проекты для Visual Studio, Xcode и т.д.) из предварительно написанного файла сценария CMakeLists.txt.

---

## Основные команды

```bash
# Создание директории для сборки
mkdir build
cd build

# Генерация файлов сборки
cmake ..

# Сборка проекта
cmake --build .

# Очистка
cmake --build . --target clean
```
## Простой CMakeLists

```cmake
cmake_minimum_required(VERSION 3.16)
project(main)

set(SOURCE_EXE main.c)
set(SOURCE_LIB lib.c)

add_library(lib STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main lib)
```

| Строка | Что делает|
| :--- | :--- | 
| `cmake_minimum_required(VERSION 3.16)` | Минимальная версия CMake |
| `project(main)` | Название проекта |
| `set(SOURCE_EXE main.c)` | Переменная с исходным файлом программы |
| `set(SOURCE_LIB lib.c)` | Переменная с исходным файлом библиотеки |
| `add_library(lib STATIC ${SOURCE_LIB})` | Создание библиотеки (статической) |
| `add_executable(main ${SOURCE_EXE})` | Создание исполняемого файла |
| `target_link_libraries(main lib)` | Линковка библиотеки с программой |

---
## Задание

* Создайте директорию `build` и перейдите в неё.

* Выполните `cmake ..` для генерации файлов сборки.

* Выполните `cmake --build .` для сборки проекта.

* Запустите полученную программу.