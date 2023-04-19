0x0F-function_pointers

TASKS
0.Write a function that prints a name.

Prototype: void print_name(char *name, void (*f)(char *));
1.Write a function that executes a function given as a parameter on each element of an array.

Prototype: void array_iterator(int *array, size_t size, void (*action)(int));
where size is the size of the array
and action is a pointer to the function you need to use
2.Write a function that searches for an integer.
3.Write a program that performs simple operations.
4.Write a program that prints the opcodes of its own main function.
