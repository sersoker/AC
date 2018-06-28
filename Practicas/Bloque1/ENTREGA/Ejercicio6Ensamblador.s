	.file	"SumaVectoresC.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan n\302\272 componentes del vector\n"
	.align 8
.LC4:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB34:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	cmpl	$1, %edi
	jle	.L13
	.cfi_offset 3, -16
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movl	$33554432, %ebx
	call	strtol
	cmpl	$33554432, %eax
	cmovbe	%eax, %ebx
	testl	%ebx, %ebx
	je	.L3
	mov	%ebx, %eax
	movsd	.LC1(%rip), %xmm3
	cvtsi2sdq	%rax, %xmm2
	xorl	%edx, %edx
	movsd	.LC2(%rip), %xmm4
	xorl	%eax, %eax
	mulsd	%xmm3, %xmm2
	.p2align 4,,10
	.p2align 3
.L6:
	cvtsi2sd	%eax, %xmm0
	addl	$1, %eax
	movapd	%xmm0, %xmm1
	mulsd	%xmm4, %xmm0
	mulsd	%xmm3, %xmm1
	addsd	%xmm2, %xmm0
	addsd	%xmm2, %xmm1
	movsd	%xmm0, v2(%rdx)
	movsd	%xmm1, v1(%rdx)
	addq	$8, %rdx
	cmpl	%ebx, %eax
	jne	.L6
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	leal	-1(%rbx), %eax
	leaq	8(,%rax,8), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movsd	v1(%rax), %xmm0
	addsd	v2(%rax), %xmm0
	movsd	%xmm0, v3(%rax)
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L7
.L8:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	(%rsp), %rdx
	subq	16(%rsp), %rdx
	leal	-1(%rbx), %ecx
	movsd	v3(%rip), %xmm3
	movl	$.LC4, %esi
	mov	%ecx, %eax
	movsd	v2(%rip), %xmm2
	movsd	v3(,%rax,8), %xmm6
	movl	%ecx, %r9d
	cvtsi2sdq	%rdx, %xmm0
	movq	8(%rsp), %rdx
	subq	24(%rsp), %rdx
	movsd	v2(,%rax,8), %xmm5
	movsd	v1(,%rax,8), %xmm4
	movl	%ecx, %r8d
	movl	$1, %edi
	movl	$7, %eax
	cvtsi2sdq	%rdx, %xmm1
	movl	%ebx, %edx
	divsd	.LC3(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	v1(%rip), %xmm1
	call	__printf_chk
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbx
	ret
.L3:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L8
.L13:
	movl	$1, %edi
	movl	$.LC0, %esi
	xorl	%eax, %eax
	call	__printf_chk
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.comm	v1,268435456,32
	.comm	v2,268435456,32
	.comm	v3,268435456,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.align 8
.LC2:
	.long	2576980378
	.long	-1078355559
	.align 8
.LC3:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
