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

# Создание директории и сборка в ней
cmake -S . -B build
cmake --build build

# Пояснение:
# -S . — папка с исходниками
# -B build — папка для сборки

```



## Простой CMakeLists

```cmake
cmake_minimum_required(VERSION 3.16)
project(main)
set(SOURCE main.c)
add_executable(main ${SOURCE})
```

| Строка | Что делает|
| :--- | :--- | 
| `cmake_minimum_required(VERSION 3.16)` | Минимальная версия CMake |
| `project(main)` | Название проекта |
| `set(SOURCE main.c)` | Переменная с исходным файлом программы |
| `add_executable(main ${SOURCE})` | Создание исполняемого файла |

---
## Задание

* Создайте директорию `build` и перейдите в неё.

* Выполните `cmake ..` для генерации файлов сборки.

* Выполните `cmake --build .` для сборки проекта.

* Запустите полученную программу.

* Проделайте аналогичные действия, но под Windows, используя PowerShell