 .global _start

.data
    ; что-то   
.text
_start:

        movq     $0, %rbx
N_EQ:
        ; что-то        
        jne N_EQ

        ; и тут что-то

        mov     $60, %rax               
        mov     $0, %rdi                
        syscall                         
        

