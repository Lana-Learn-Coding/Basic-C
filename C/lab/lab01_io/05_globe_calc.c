#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float radius;
	float area, capacity;
	float PI = 3.141593;

	printf("nhap ban kinh hinh cau\n");
	scanf("%f", &radius);

	area = radius * radius * PI * 4;
	capacity = 4 / 3 * PI * radius * radius * radius;

	printf("hinh cau co dien tich la %.2f \nhinh cau co the tich la %.2f", area, capacity);
	getch();
	return 0;
}
