.section .text
.global _start

_start:
    # Кладём два числа на стек
    mov $10, %rax
    push %rax            
    mov $32, %rax
    push %rax           

    # Читаем числа с помощью адресации, не меняем rsp
    mov (%rsp), %rbx      
    mov 8(%rsp), %rcx     

    # Складываем
    add %rcx, %rbx        

    # Чистим стек
    add $16, %rsp         

    # Выход с кодом = rbx
    mov $60, %rax        
    mov %rbx, %rdi        
    syscall
    