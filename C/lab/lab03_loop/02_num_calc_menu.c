#include <stdio.h>
#include <conio.h>

#define CALC_SUM 1
#define CAL_AVERAGE 2
#define FIND_BIGGEST 3

int main(int argc, char const *argv[])
{
	int a, b, c;
	int options;

	printf("nhap 3 so a b c\n");
	scanf("%d %d %d", &a, &b, &c);

	printf("chon 1 trong cac lua chon sau: \n");
	printf("%d, tinh tong 3 so\n", CALC_SUM);
	printf("%d, tinh trung binh 3 so\n", CAL_AVERAGE);
	printf("%d, tim so lon nhat\n", FIND_BIGGEST);
	scanf("%d", &options);

	switch (options) {
	case CALC_SUM:
		printf("tong 3 so la %d\n", a + b + c);
		break;
	case CAL_AVERAGE:
		printf("trung binh 3 so la %.2f\n", (float) (a + b + c) / 3);
		break;
	case FIND_BIGGEST: /* This change the variable*/
		if (c > b) { b = c; }
		if (b > a) { a = b; }
		printf("so lon nhat trong 3 so la %d\n", a);
		break;
	default:
		printf("lua chon cua ban (%d) khong hop le\n", options);
	}

	getch();
	return 0;
}
