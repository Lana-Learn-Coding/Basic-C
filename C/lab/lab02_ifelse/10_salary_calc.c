#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	const int BASE_WORK_H = 35;
	const float OT_SALARY_FACTOR = 1.5;
	int salary_per_h, work_h;
	double salary;

	printf("nhap so gio lam viec: ");
	scanf("%d", &work_h);
	printf("nhap luong co ban: ");
	scanf("%d", &salary_per_h);

	if (work_h > BASE_WORK_H) {
		int ot_work_h = work_h - BASE_WORK_H;
		salary = salary_per_h * (BASE_WORK_H + OT_SALARY_FACTOR * ot_work_h);
	} else {
		salary = salary_per_h * work_h;
	}

	printf("so tien luong la %.2lf\n", salary);

	getch();
	return 0;
}
