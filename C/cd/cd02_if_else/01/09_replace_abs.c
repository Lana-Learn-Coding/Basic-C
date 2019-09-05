#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float a, b, c;
	printf("nhap 3 so thuc a b c: ");
	scanf("%f %f %f", &a, &b, &c);
	printf("gia tri tuyet doi cua '%.2f' '%.2f' '%.2f' la: ", a, b, c);

	if (a < 0) { a = a * -1; }
	if (b < 0) { b = b * -1; }
	if (c < 0) { c = c * -1; }
	printf("%4.2f %4.2f %4.2f", a, b, c);

	getch();
	return 0;
}
