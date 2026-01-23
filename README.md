*This project has been created as part
of the 42 curriculum by jemonthi.*

# Description

push_swap is a 42 project that expect you to write a program named push_swap that takes as an argument the **stack a** formatted as a list of integers. The first argument should be at the top of the stack. The program must diplay the shortest sequence of instructions needed to sort **stack a** with the smallest number at the top.

The goal is to sort the stack with the lowest possible number of operations.

In case of error, it must display "Error" followed by an '\n' on the standard error.

It will write an error if there is more than 1 time the same number. (no double)

*reminder : numbers have to fit the integer value, it cannot be higher than INT_MAX or smaller than INT_MIN, if it is it will write "Error" followed by an '\n'.*

# Instructions

To compile all the files just run **make** at the root of the repository.

> make

It will create the executable "push_swap", to test it just type like the example below :

> ./push_swap "2 4 1 0 -5 12"

The program will accept every integer value possible, even the INT_MAX and INT_MIN for example :

> ./push_swap "5 22 33 -2147483648 2147483647 599 0"

It will write on the terminal every operation to sort the different numbers in ascending order.

To check if it is sorting correctly, you can download the Checker_Linux on the intranet and execute the program with it as followed :

> ./push_swap "2 200 -500 -2 1 3999 0" | ./checker_linux "2 200 -500 -2 1 3999 0"

You can also check the valgrind for the push_swap as below :

> valgrind ./push_swap "2 200 -500 -2 1 3999 0" | ./checker_linux "2 200 -500 -2 1 3999 0"

To check with random numbers between -1000 and 1000 for example you can write this command line below :

> ARG=$(seq -1000 1000 | shuf -n 20 | tr '\n' ' ')
valgrind ./push_swap $ARG | ./checker_linux $ARG

To check how many operations has been executed (for example 100 numbers), type this command :

> ARG=$(seq 1 100 | shuf | tr '\n' ' ')

then :

> ./push_swap $ARG | wc -l

# Ressources

Here are some documentations i have read during the project :

- How to use binary operator :

    - https://zestedesavoir.com/tutoriels/755/le-langage-c-1/annexes/index/

    - https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/

- How to use correctly radix_sort_binary and understand it :

    - https://www.youtube.com/watch?v=Y95a-8oNqps

    - https://www.youtube.com/watch?v=XiuSW_mEn7g

- Watch a push_swap code tutorial on youtube to understand the order of verifications :

    - https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s
