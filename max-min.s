    .section .data
num1:   .word 10    # First number
num2:   .word 20    # Second number

max:    .word 0     # To store maximum number
min:    .word 0     # To store minimum number

    .section .text
    .globl _start

_start:
    # Load the values of num1 and num2 into registers
    lw t0, num1      # Load num1 into t0
    lw t1, num2      # Load num2 into t1

    # Compare the two numbers
    bge t0, t1, num1_is_max # If num1 >= num2, branch to num1_is_max

    # If num1 < num2, num2 is max and num1 is min
    la t2, max       # Load address of max into t2
    sw t1, 0(t2)     # Store t1 (num2) in max

    la t2, min       # Load address of min into t2
    sw t0, 0(t2)     # Store t0 (num1) in min

    j done           # Jump to done

num1_is_max:
    # If num1 >= num2, num1 is max and num2 is min
    la t2, max       # Load address of max into t2
    sw t0, 0(t2)     # Store t0 (num1) in max

    la t2, min       # Load address of min into t2
    sw t1, 0(t2)     # Store t1 (num2) in min

done:
    # Exit the program (simulate with an infinite loop)
    j done           # Infinite loop to end program

