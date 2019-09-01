#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int a, b, c;
	int tmp;
	printf("nhap 3 so a b c\n");
	scanf("%d %d %d", &a, &b, &c);

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
		/* a > b */
	}
	if (b < c) {
		tmp = b;
		b = c;
		c = tmp;
		/*
		* b > c
		* but because b changed,
		* so check if a > (new) b
		*/
	}
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
		/* a > b */
	}

	printf("lon den nho: %d %d %d\n", a, b, c);
	printf("nho den lon: %d %d %d\n", c, b, a);

	getch();
	return 0;
}
