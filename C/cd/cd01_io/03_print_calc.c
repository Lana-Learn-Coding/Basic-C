#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float a, b;
	printf("nhap 2 so thuc: ");
	scanf("%f %f", &a, &b);
	printf("\n");

	printf("tong cua %5.3f va %5.3f la: %5.3f\n", a, b, a + b);
	printf("trung binh cong cua %5.3f va %5.3f la: %.3f\n", a, b, (a + b) / 2);
	printf("tich cua %5.3f va %5.3f la: %.3f\n", a, b, a * b);
	printf("trung binh nhan cua %5.3f va %5.3f la: %.3f\n", a, b, sqrt(a * b));

	getch();
	return 0;
}
