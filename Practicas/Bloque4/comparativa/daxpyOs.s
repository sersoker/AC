	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta numero de filas N.\n"
.LC2:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\n"
.LC3:
	.string	"Valor M[0][0]= %d M[n-1][n-1]=%d\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$16, %esp
	movl	4(%ecx), %eax
	cmpl	$1, (%ecx)
	jg	.L2
	pushl	%ebx
	pushl	%ebx
	pushl	stderr
	pushl	$.LC0
	call	fputs
	movl	$-1, (%esp)
	call	exit
.L2:
	subl	$12, %esp
	pushl	4(%eax)
	call	atoi
	addl	$16, %esp
	xorl	%edx, %edx
	movl	%eax, %ebx
.L4:
	movl	$1, x(,%edx,4)
	movl	$1, y(,%edx,4)
	incl	%edx
	cmpl	$114748364, %edx
	jne	.L4
	pushl	%ecx
	pushl	%ecx
	leal	-24(%ebp), %eax
	pushl	%eax
	pushl	$0
	call	clock_gettime
	addl	$16, %esp
	movl	$1, %edx
.L6:
	movl	x(,%edx,4), %eax
	imull	%ebx, %eax
	addl	%eax, y(,%edx,4)
	incl	%edx
	cmpl	$114748365, %edx
	jne	.L6
	pushl	%eax
	pushl	%eax
	leal	-16(%ebp), %eax
	pushl	%eax
	pushl	$0
	call	clock_gettime
	movl	-12(%ebp), %edx
	subl	-20(%ebp), %edx
	movl	-16(%ebp), %eax
	subl	-24(%ebp), %eax
	movl	$114748364, (%esp)
	pushl	%edx
	flds	.LC1
	fidivrl	(%esp)
	movl	%eax, (%esp)
	fiaddl	(%esp)
	pushl	%edx
	fstpl	(%esp)
	pushl	$.LC2
	pushl	$1
	call	__printf_chk
	addl	$32, %esp
	pushl	y+458993452
	pushl	y
	pushl	$.LC3
	pushl	$1
	call	__printf_chk
	addl	$16, %esp
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE21:
	.size	main, .-main
	.comm	x,458993456,4
	.comm	y,458993456,4
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	1315859240
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
