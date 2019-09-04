#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	char character;
	printf("nhap 1 ki tu: ");
	character = getchar();

	printf("ki tu vua nhap la: ");
	putchar(character);

	getch();
	return 0;
}
