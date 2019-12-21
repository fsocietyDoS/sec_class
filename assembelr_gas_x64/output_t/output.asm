.global _start
.data
hello:.string "Hacking is not a crime\n"
.text
_start:

	mov $1, %rax
	mov $1, %rdi
	mov $hello, %rsi
	mov $7, %rdx
	syscall
	
	mov $60, %rax
	mov $0 , %rdi
	syscall
