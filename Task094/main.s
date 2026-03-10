.section .text
.global _start

_start:
    mov $42, %rax        
    push %rax            
    pop %rbx             

    mov $60, %rax       
    mov %rbx, %rdi        
    syscall              

