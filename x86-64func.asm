; CRUZ, Airon John R.
; CEPARCO-S11
; CODE: X86-64 implementation of DOT PRODUCT kernel

section .text
    bits 64 
    default rel
    global dotproduct_x8664

dotproduct_x8664:

    mov rdi, rdx                    ; second parameter = long long Vector 'A'
    mov rsi, r8                        ; third parameter = long long Vector 'B'
    xor r10, r10                    ; Sum accumulator (instantiate to 0)

    xor r11, r11                    ; Index variable (instantiate to 0)


L1:

    mov rax, QWORD[rdi + r11 * 8]    ; load n-th element of Vector A
    imul rax, QWORD[rsi + r11 * 8]    ; load n-th element of Vector B and multiply with the corresponding n-th element of Vector A
    add r10, rax                    ; Accumulate the product
    inc r11                            ; increment index variable
    loop L1                            ; loop until rcx equates to 0


    mov [r9], r10                    ; Move the result to sdot @ r9 since 4th parameter
    ret