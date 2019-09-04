#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int age;
	char gender;
	float math, philology, english, average;
	int current_year = 2019;

	const int MATH_FACTOR = 2, PHILOLOGY_FACTOR = 2, ENGLISH_FACTOR = 1;
	const int AVG_FACTOR = MATH_FACTOR + PHILOLOGY_FACTOR + ENGLISH_FACTOR;

	printf("nhap tuoi: ");
	scanf("%d", &age);
	printf("nhap gioi tinh (M/F): ");
	scanf(" %c", &gender);
	printf("nhap diem toan van anh: ");
	scanf("%f %f %f", &math, &philology, &english);
	printf("\n");

	average = (math * MATH_FACTOR +
	           philology * PHILOLOGY_FACTOR +
	           english * ENGLISH_FACTOR) /
	          AVG_FACTOR;

	printf(" %-20s %-20s %-20s", "Nam sinh", "Gioi tinh", "Diem trung binh");
	printf("\n");
	printf(" %-20d %-20d %-20.2f", (current_year - age), gender, average);

	getch();
	return 0;
}
