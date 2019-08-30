#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float width, height;
	float area, perimeter;

	printf("nhap chieu dai\n");
	scanf("%f", &height);
	printf("nhap chieu rong\n");
	scanf("%f", &width);

	area = width * height;
	perimeter = (width + height) * 2;

	printf("chu vi hcn la %.2f \ndien tich hcn la %.2f", perimeter, area);

	getch();
	return 0;
}
