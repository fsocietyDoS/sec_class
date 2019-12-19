
.global _start

.text

_start:

	mov $10, %rax
	mov $5,  %rdi

	add %rax, %rdi
	mov $60, %rax
	syscall
