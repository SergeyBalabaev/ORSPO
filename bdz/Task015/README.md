# Task015 — CMake: работа с несколькими файлами и директориями 🔍

```
project/
├── CMakeLists.txt
├── main.c
├── lib/
│   ├── CMakeLists.txt
│   ├── lib.c
│   └── lib.h
└── build/
```
---
## Разбор CMakeLists.txt

### Корневой CMakeLists.txt

| Строка | Что делает|
| :--- | :--- | 
| `add_subdirectory(lib)` | Подключает `CMakeLists.txt` из папки `lib` для сборки библиотеки |
| `add_executable(myapp main.c)` | Создает исполняемый файл `myapp` из `main.c` |
| `target_link_libraries(myapp mylib)` |Линкует программу с библиотекой `mylib` |
| `target_include_directories(myapp PRIVATE lib)` | Добавляет папку `lib` в пути поиска заголовочных файлов для `myapp` |

### lib/CMakeLists.txt

| Строка | Что делает|
| :--- | :--- | 
| `add_library(mylib STATIC lib.c)` | Создает статическую библиотеку `mylib` из `lib.c` |
| `target_include_directories(mylib PUBLIC ...)` | Указывает, что при использовании `mylib` нужно добавить текущую папку в пути поиска заголовков |

**Важно:** `PUBLIC` означает, что папка с заголовками нужна не только при сборке самой библиотеки, но и для тех, кто её использует.

---

## Сборка проекта

```bash
# Создание директории для сборки
mkdir build
cd build

# Генерация файлов сборки
cmake ..

# Сборка проекта
cmake --build .

# Запуск программы
./myapp
```

---

## Дополнительные возможности

### Добавление разных типов сборки

```cmake
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

### Установка флагов компиляции

```cmake
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Werror")
```

### Или для конкретной цели

```cmake
target_compile_options(myapp PRIVATE -Wall -Wpedantic -Werror)
```

### Добавление нескольких исходных файлов

```cmake
set(SOURCES main.c utils.c math.c)
add_executable(myapp ${SOURCES})
```

### Поиск библиотек в системе

```cmake
find_library(MATH_LIB m)
target_link_libraries(myapp ${MATH_LIB})
```

---

## Задание 

* Выполните сборку проекта через `CMake`.

* Запустите программу и убедитесь, что она работает.

* Измените тип библиотеки с `STATIC` на `SHARED` в `lib/CMakeLists.txt` и пересоберите проект.

* Выполните ldd myapp и посмотрите на зависимости.

* Зачем разделять проект на несколько `CMakeLists.txt`?

* В чем разница между `PRIVATE`, `PUBLIC` и `INTERFACE` в `CMake`?

* Что произойдет, если не указать `target_include_directories` для `myapp`?
