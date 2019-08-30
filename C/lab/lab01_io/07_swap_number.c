#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int a, b;
	printf("nhap 2 so a va b\n");
	scanf("%d %d", &a, &b);

	printf("2 so vua nhap: %d %d\n", a, b);
	printf("2 so sau khi dao vi tri %d %d\n", b, a);

	getch();
	return 0;
}
