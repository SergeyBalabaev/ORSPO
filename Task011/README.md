Задача 11. 🔍 

Скомпилируйте программу, собрав lib.c как статическую и динамическую библиотеки


Статическая:
gcc -c main.c -o main1.o
gcc -c lib.c -o lib.o
ar cr libmain.a lib.o
gcc main1.o libmain.a -o main1


Динамическая:
gcc -c main.c -o main2.o
gcc -c lib.c -o lib.o
gcc -shared -o libmain1.so lib.o
gcc  main2.o  libmain1.so -Wl,-rpath,. -o main2 


Выполните команды 
ldd main1
ldd main2
Объясните полученный результат


Выполните команды 
objdump main1 -d
objdump main2 -d
Найдите отличия в файлах
