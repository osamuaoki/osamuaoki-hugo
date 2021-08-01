	.file	"string-array.c"
	.section	.rodata
.LC0:
	.string	"Before foo[] = '%s'\n\n"
.LC1:
	.string	"After  foo[] = '%s'\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movabsq	$7523094288207667809, %rax
	movq	%rax, -16(%rbp)
	movb	$0, -8(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movb	$64, -13(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 4.8.1-9) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
