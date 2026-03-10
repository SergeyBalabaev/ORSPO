.globl _start
 
.data 
message: .asciz "Hello MPSU!\n"   # текст выводимого сообщения
 
.text
_start:
 
    movq $message, %rsi  # в RSI - адрес строки
    movq $1, %rdi        # в RDI - дексриптор вывода в стандартный поток (консоль)
    movq $12, %rdx       # в RDX - длина строки
    movq $1, %rax        # в RAX - номер функции для вывода в поток 
    syscall              # вызываем функцию Linux
 
    movq $60, %rax
    syscall
