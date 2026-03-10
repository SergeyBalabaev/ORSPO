.section .data
var:
    .quad 42

.section .text
.global _start

_start:
    lea var(%rip), %rax     
    mov (%rax), %rdi        
    mov $60, %rax           
    syscall
    