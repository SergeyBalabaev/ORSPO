Задача 17. 🔍 

Скомпилируйте программу с ключом -g

gcc -g gdb_vals.c -o gdb_vals 

Запустите отладку

gdb gdb_vals

Выполните следующие команды:

list
break 32
clear 32
run
info registers
info locals
ptype a
print a
print &a
print sizeof(a)
set var a =  512
print a

Для чего они предназначены?

