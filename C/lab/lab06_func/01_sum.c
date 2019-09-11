#include <stdio.h>
#include <conio.h>

int sum(int a, int b);

int main(int argc, char const *argv[])
{
	int a, b;
	printf("nhap 2 so a b: ");
	scanf("%d %d", &a, &b);

	printf("tong 2 so %d + %d la %d", a, b, sum(a, b));
	getch();
	return 0;
}

int sum(int a, int b) {
	return a + b;
}
