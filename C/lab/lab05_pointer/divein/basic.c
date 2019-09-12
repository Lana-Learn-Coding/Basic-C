#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num = 10;
	int *ptr = &num;

	printf("int num = %d\n", num);
	printf("int *ptr = &num (pointer of num)\n");
	printf("\n");

	printf("-> variable: \n");
	printf("num  = %d (value of num)\n", num);
	printf("&num = %d (address of num)\n", &num);
	printf("*num = ERROR!\n");
	/* printf("*ptr = %d\n", *ptr); */
	printf("\n");

	printf("-> pointer: \n");
	printf("ptr  = %d (value of ptr = address of num)\n", ptr);
	printf("&ptr = %d (address of ptr)\n", &ptr);
	printf("*ptr = %d (value of num)\n", *ptr);
	printf("\n");

	getch();
	return 0;
}
