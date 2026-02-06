This project has been created as part
of the 42 curriculum by vokotera

# Description

Push_swap is a sorting algorithm project where you need to sort data on  a stack with limited set of operations. The goal is to make it in smallest number of actions possible

The program takes a list of integers as input and output a series of operations that will sort them in ascending order.
 - `sa`, `sb`, `ss`: swap the 2 top elemets
 - `pa`, `pb`: push from one stack to another
 - `ra`, `rb`, `rr`: rotate (shift all elements by one)
 - `rra`, `rrb`, `rrr`: reverse rotate (shift all elements down be one)

This project projet using different sorting strategies:
 - Special cases for 2-5 numbers
 - Turk Algorithm for larger datasets(5 - 500 numbers);

# Instructions
    make - this gonna make push_swap program
    ./push_swap [list of integers]

Examples

    ./push_swap 3 2 1 5 6 4
    ./push_swap "5 -100 500 600 10000"
    ARG="5 3 2 1"; ./push_swap $ARG

The program will outputs the list of operations that he made.

Cleaning instructions

    make clean - remove object files
    make fclean - remove object files and executable program
    make re - recompile everything

# Resources
- [Turk Algoritm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Exit Function](https://www.geeksforgeeks.org/c/c-exit-abort-and-assert-functions/)
- [Nodes/Linked list](https://www.programiz.com/dsa/linked-list)
- And other websites and videos

**AI Usage:**
- Understanding how turk algoritm work and help with logic 
- Help with errors and with indetifying edge cases 
