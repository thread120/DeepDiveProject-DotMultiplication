; CRUZ, Airon John R.
; CEPARCO-S11
; CODE: X86 Single Instruction Multiple Data (SIMD) implementation of DOT PRODUCT kernel

section .text
    bits 64 
    default rel
    global dotproduct_simd

dotproduct_simd:
    vzeroall                            ; instantiate all ymm registers to 0
    shr rcx, 2                          ; ymm=256/64 = 4 elements = 2^2

L1:
    vmovdqu ymm1, [rdx]                 ; load 4 elements of vector A 
    vmovdqu ymm2, [r8]                  ; load 4 elements of vector B
    vpmuludq ymm2, ymm2, ymm1            ; perform packed unsigned 32-bit integer multiplication
    vpaddq ymm3, ymm3, ymm2             ; accumulate the products
    add rdx, 32                         ; increment by 32 since 4 elements * 8 bytes each = 32
    add r8, 32
    loop L1                             ; loop until rcx reaches 0

    vpermq ymm0, ymm3, 0x4E             ; permute the elements of ymm3 to [2, 3, 0, 1]
    vpaddq ymm3, ymm3, ymm0             ; horizontally add the permuted ymm3
    vpermq ymm0, ymm3, 0x11             ; permute the elements of ymm3 to [1, 0, 3, 2]
    vpaddq ymm3, ymm3, ymm0             ; horizontally add the permuted ymm3

    vmovdqu [r9], ymm3                   ; move the result to sdot @ r9 since 4th parameter
    ret
