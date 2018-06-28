	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta numero de filas N.\n"
	.section	.rodata.str1.4,"aMS",@progbits,1
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
.LFB39:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 3, -12
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
	movl	$10, 8(%esp)
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	strtol
	movl	%eax, %ebx
	movl	$0, %edx
.L4:
	movl	$1, x(,%edx,4)
	movl	$1, y(,%edx,4)
	addl	$1, %edx
	cmpl	$114748364, %edx
	jne	.L4
	leal	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	$1, %edx
.L6:
	movl	%ebx, %eax
	imull	x(,%edx,4), %eax
	addl	%eax, y(,%edx,4)
	addl	$1, %edx
	cmpl	$114748365, %edx
	jne	.L6
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	$114748364, 16(%esp)
	movl	40(%esp), %eax
	subl	32(%esp), %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	movl	44(%esp), %eax
	subl	36(%esp), %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fdivs	.LC1
	faddp	%st, %st(1)
	fstpl	8(%esp)
	movl	$.LC2, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	y+458993452, %eax
	movl	%eax, 12(%esp)
	movl	y, %eax
	movl	%eax, 8(%esp)
	movl	$.LC3, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	x,458993456,32
	.comm	y,458993456,32
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	1315859240
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
