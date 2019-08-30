#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float math, physic, chemistry;
	float average, total;

	printf("nhap diem toan\n");
	scanf("%f", &math);
	printf("nhap diem ly\n");
	scanf("%f", &physic);
	printf("nhap diem hoa\n");
	scanf("%f", &chemistry);

	total = math + physic + chemistry;
	average = total / 3;

	printf("tong diem la %.2f \ndiem trung binh la %.2f", total, average);

	getch();
	return 0;
}
