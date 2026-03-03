 .global _start

.data
mes:
    .ascii "equal\n"

        .text
_start:

        movq     $5, %rax
        cmp      $5, %rax
        jne N_EQ
                     

N_EQ:
                        
        
