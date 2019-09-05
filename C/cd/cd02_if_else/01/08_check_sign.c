#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float a, b;
	int is_same_sign;
	printf("nhap 2 so thuc a va b: ");
	scanf("%f %f", &a, &b);

	is_same_sign = a * b >= 0;
	if (a == 0 || b == 0) {
		printf("khong xac dinh, vi '0' khong co dau\n");
	} else {
		if (is_same_sign) {
			printf("cung dau\n");
		} else {
			printf("khac dau\n");
		}
	}

	getch();
	return 0;
}
