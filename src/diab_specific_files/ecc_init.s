;
;######################################################################
;                                RAppID
;           Rapid Application Initialization and Documentation Tool
;                         Freescale Semiconductor Inc.
;
;######################################################################
;
; Target Compiler        : Diab
;
; Target Part            : MPC5643L
;
; Brief Description      : This File contain SRAM initialization and Configuration for ECC
;
;******************************************************************************* 
;
; Detail Description     : This File contains the code for SRAM initialization
;                         based on GPR/user defined values.It configures ECC
;                         Configuration Register which is a control register
;                         for specifying which types of memory errors are reported
;
;******************************************************************************* 
;
;######################################################################
;

 
 

    .equ CTR, 512
; 1024 for LSM



.ifdef __vle
;;.section .text_vle
;;.align 2


;  ----------------------------------------------------------- 
;  ECSM_ECR Register (Set to value 00000000)                  
;----------------------------------------------------------- 
    e_lis   r11, 0x4000
    e_or2i   r11, 0
;              base address of the L2SRAM, 64-bit word aligned
    e_lis    r12, CTR@h
    e_or2i   r12, CTR@l
    mtctr r12
;              loop counter to get all of L2SRAM;
loop:
    e_stmw  r0, 0(r11)
    e_addi  r11, r11, 128
;             Write all 32 GPRs to L2SRAM; 32 GPRs * 4 bytes = 128
    e_bdnz  loop
;             Loop for 64k of L2SRAM

    e_lis   r11, 0xFFF4
    e_or2i   r11, 0x0043
;             Load ECSM Configuration Reg address
    e_lis   r12, 0x0000
    e_or2i  r12, 0x0000
    e_stb   r12, 0 (r11)
;             Reporting of non-correctable Platform RAM errors disabled
;             Reporting of non-correctable Platform flash memory errors disabled
;             Reporting of single-bit Platform RAM corrections disabled
;             Reporting of single-bit Platform flash corrections disabled
.else 
;;.section .text
;;.align 2
;   ----------------------------------------------------------- 
; *  ECR Register (Set to value 00000000)                  
; *----------------------------------------------------------- 
; 
    lis   r11, 0x4000
    ori   r11, r11, 0
;              base address of the L2SRAM, 64-bit word aligned
    lis    r12, CTR@h
    ori    r12,r12, CTR@l
    mtctr r12
;              loop counter to get all of L2SRAM;
loop1:
    stmw  r0, 0(r11)
    addi  r11, r11, 128
;             Write all 32 GPRs to L2SRAM; 32 GPRs * 4 bytes = 128
    bdnz  loop1
;             Loop for 64k of L2SRAM
    lis   r11, 0xFFF4
   ori   r11, r11, 0x0043
;             Load ECSM Configuration Reg address
    lis   r12, 0x0000
    ori   r12, r12, 0x0000
    stb   r12, 0 (r11)
;             Reporting of non-correctable Platform RAM errors disabled
;             Reporting of non-correctable Platform flash memory errors disabled
;             Reporting of single-bit Platform RAM corrections disabled
;             Reporting of single-bit Platform flash corrections disabled
.endif

 
;
;######################################################################
;                           End of File
;######################################################################
;

