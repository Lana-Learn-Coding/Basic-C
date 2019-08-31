#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	const int MATH_FACTOR  = 3, PHYSIC_FACTOR = 2, CHEMISTRY_FACTOR = 1;
	const int average_factor = CHEMISTRY_FACTOR + PHYSIC_FACTOR + MATH_FACTOR;

	float math, physic, chemistry;
	float average, total;

	printf("nhap diem toan\n");
	scanf("%f", &math);
	printf("nhap diem ly\n");
	scanf("%f", &physic);
	printf("nhap diem hoa\n");
	scanf("%f", &chemistry);

	total = math + physic + chemistry;
	average = (math * MATH_FACTOR + physic * PHYSIC_FACTOR + chemistry * CHEMISTRY_FACTOR) / average_factor;

	printf("tong diem la %.2f \ndiem trung binh la %.2f", total, average);

	getch();
	return 0;
}
