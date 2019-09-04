#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);
	printf("\n");

	printf("binh phuong cua %d la %d\n", num, num * num);

	getch();
	return 0;
}