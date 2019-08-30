#include <stdio.h>
#include <conio.h>

#define MATH_FACTOR 3
#define PHYSIC_FACTOR 2
#define CHEMISTRY_FACTOR 1

int main(int argc, char const *argv[])
{
	float math, physic, chemistry;
	float average, total;
	int averageFactor = CHEMISTRY_FACTOR + PHYSIC_FACTOR + MATH_FACTOR;

	printf("nhap diem toan\n");
	scanf("%f", &math);
	printf("nhap diem ly\n");
	scanf("%f", &physic);
	printf("nhap diem hoa\n");
	scanf("%f", &chemistry);

	total = math + physic + chemistry;
	average = (math * MATH_FACTOR + physic * PHYSIC_FACTOR + chemistry * CHEMISTRY_FACTOR) / averageFactor;

	printf("tong diem la %.2f \ndiem trung binh la %.2f", total, average);

	getch();
	return 0;
}