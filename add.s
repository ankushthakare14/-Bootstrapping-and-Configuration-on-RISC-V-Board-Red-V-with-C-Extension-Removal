.global _start

_start:
	li t2,10
	li t1,0
	loop:beq t2, x0, exit
	addi t1,t1,1
	addi t2,t2,-1
	j loop
	exit:
		nop 		#no operation
	
