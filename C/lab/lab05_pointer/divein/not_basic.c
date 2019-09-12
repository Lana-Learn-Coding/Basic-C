#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num = 10;
	int *ptr = &num;
	int **ptr_pointer = &ptr;

	printf("int num = %d\n", num);
	printf("int *ptr = &num (pointer of num)\n");
	printf("int **ptr_pointer = &ptr (pointer of pointer)\n");
	printf("\n");

	printf("-> variable: \n");
	printf("*&num = %d (get value of num by address of num)\n", *&num);
	printf("&*&num = %d (get address of ...)\n", &*&num);
	printf("*&*&num = %d (get value of ... ...)\n", *&*&num);
	printf("and so on...\n");
	printf("\n");

	printf("-> pointer: \n");
	printf("&*ptr = %d (address of value of num = address of num)\n", &*ptr);
	printf("*&ptr = %d (value of address of ptr = value of ptr)\n", *&ptr);
	printf("&*&ptr = %d (address of ... = address of ptr)\n", &*&ptr);
	printf("and so on...\n");
	printf("\n");

	printf("-> pointer of pointer:\n");
	printf("ptr  = %d (value of ptr_pointer = address of ptr)\n", ptr_pointer);
	printf("&ptr = %d (address of ptr_pointer)\n", &ptr_pointer);
	printf("*ptr = %d (value of ptr)\n", *ptr_pointer);
	printf("work like normal pointer\n");
	printf("\n");

	printf("-> error:\n");
	printf("*num = ERROR! (num is a variable, * not works)\n");
	printf("**ptr = ERROR! (*ptr is a value, * not works)\n");
	printf("&&num = ERROR! (&num is a address, & not works)\n");
	printf("\n");

	printf("-> conclusion:\n");
	printf("  *[address]: get the value that store at address\n");
	printf("  &[variable]: get the address that store the value of variable\n");
	printf("  &[variable]: get the address that store the value of variable\n");
	printf("  pointer is a variable which store a address\n");
	printf("  pointer is treated as both a variable and a address\n");

	getch();
	return 0;
}
