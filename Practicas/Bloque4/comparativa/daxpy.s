	.file	"daxpy.c"
	.comm	y,458993456,32
	.comm	x,458993456,32
	.section	.rodata
.LC0:
	.string	"Falta numero de filas N.\n"
	.align 4
.LC2:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\n"
	.align 4
.LC3:
	.string	"Valor M[0][0]= %d M[n-1][n-1]=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$80, %esp
	cmpl	$1, 8(%ebp)
	jg	.L2
	movl	stderr, %eax
	movl	%eax, 12(%esp)
	movl	$25, 8(%esp)
	movl	$1, 4(%esp)
	movl	$.LC0, (%esp)
	call	fwrite
	movl	$-1, (%esp)
	call	exit
.L2:
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	atoi
	movl	%eax, 48(%esp)
	movl	48(%esp), %eax
	movl	%eax, 52(%esp)
	movl	$114748364, 48(%esp)
	movl	$0, 44(%esp)
	jmp	.L3
.L4:
	movl	44(%esp), %eax
	movl	$1, x(,%eax,4)
	movl	44(%esp), %eax
	movl	$1, y(,%eax,4)
	addl	$1, 44(%esp)
.L3:
	movl	44(%esp), %eax
	cmpl	48(%esp), %eax
	jl	.L4
	leal	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	$1, 44(%esp)
	jmp	.L5
.L6:
	movl	44(%esp), %eax
	movl	x(,%eax,4), %edx
	movl	52(%esp), %eax
	imull	%eax, %edx
	movl	44(%esp), %eax
	movl	y(,%eax,4), %eax
	addl	%eax, %edx
	movl	44(%esp), %eax
	movl	%edx, y(,%eax,4)
	addl	$1, 44(%esp)
.L5:
	movl	44(%esp), %eax
	cmpl	48(%esp), %eax
	jle	.L6
	leal	72(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	72(%esp), %edx
	movl	64(%esp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	movl	76(%esp), %edx
	movl	68(%esp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fldl	.LC1
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	56(%esp)
	movl	48(%esp), %eax
	movl	%eax, 12(%esp)
	fldl	56(%esp)
	fstpl	4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	48(%esp), %eax
	subl	$1, %eax
	movl	y(,%eax,4), %edx
	movl	y, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
