#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	const int MATH_FACTOR  = 3, PHYSIC_FACTOR = 2, CHEMISTRY_FACTOR = 1;
	const int AVERAGE_FACTOR = CHEMISTRY_FACTOR + PHYSIC_FACTOR + MATH_FACTOR;

	float math, physic, chemistry;
	float average;

	int is_valid = 0;
	while (!is_valid) {
		printf("nhap diem toan\n");
		scanf("%f", &math);
		printf("nhap diem ly\n");
		scanf("%f", &physic);
		printf("nhap diem hoa\n");
		scanf("%f", &chemistry);

		is_valid = math >= 0 && math <= 10 &&
		           physic >= 0 && physic <= 10 &&
		           chemistry >= 0 && chemistry <= 10;

		if (!is_valid) {
			printf("diem so khong hop le!\n\n");
			printf("vui long thu lai:\n");
		}
	}

	average = (math * MATH_FACTOR +
	           physic * PHYSIC_FACTOR +
	           chemistry * CHEMISTRY_FACTOR) /
	          AVERAGE_FACTOR;
	printf("diem trung binh: %.2f\n", average);

	if (average <= 5) {
		printf("xep loai yeu, can co gang\n");
	} else if ( average > 5 && average <= 6) {
		printf("xep loai trung binh\n");
	} else if ( average > 6 && average <= 7) {
		printf("xep loai kha\n");
	} else if ( average > 7 && average <= 8) {
		printf("xep loai gioi\n");
	} else if ( average > 8 && average <= 10) {
		printf("xep loai xuat sac\n");
	} else {
		printf("wait. That's illegal\n");
	}

	getch();
	return 0;
}
