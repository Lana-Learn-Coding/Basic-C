#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float math, physic, chemistry;
	float average;

	printf("nhap diem toan\n");
	scanf("%f", &math);
	printf("nhap diem ly\n");
	scanf("%f", &physic);
	printf("nhap diem hoa\n");
	scanf("%f", &chemistry);

	average = (math + physic + chemistry) / 3;
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
