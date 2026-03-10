# Task009 — Статические и динамические библиотеки 🔍

## Команды для сборки

### Статическая библиотека

```bash
gcc -c main.c -o main1.o
gcc -c lib.c -o lib.o
ar cr libmain.a lib.o
gcc main1.o libmain.a -o main1
```

### Динамическая библиотека

```bash
gcc -c main.c -o main2.o
gcc -c lib.c -o lib.o
gcc -shared -o libmain.so lib.o
gcc main2.o libmain.so -Wl,-rpath,. -o main2
```

# Задание 

* Соберите программу двумя способами: со `статической` и `динамической` библиотекой.

* Выполните команды `ldd main1` и `ldd main2`. Объясните полученный результат.

* Выполните команды `objdump -d main1` и `objdump -d main2`. Найдите отличия в файлах.

* Запустите обе программы и убедитесь, что они работают одинаково.

* Удалите файл `libmain.so` и попробуйте запустить `main2`. Что произошло?
