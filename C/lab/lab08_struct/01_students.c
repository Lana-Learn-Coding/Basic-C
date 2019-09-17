#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student {
	char code[6];
	char name[31];
	int maths;
	int physics;
	int chemistry;
	int total;
};

int main(int argc, char const *argv[])
{
	struct student student;

	printf("nhap ma hoc sinh (toi da 5 ki tu): ");
	scanf("%s", &student.code);
	fflush(stdin);
	printf("nhap ten hoc sinh (toi da 50 ki tu): ");
	gets(&student.name[0]);
	fflush(stdin);
	printf("nhap diem toan: ");
	scanf("%d", &student.maths);
	printf("nhap diem ly: ");
	scanf("%d", &student.physics);
	printf("nhap diem hoa: ");
	scanf("%d", &student.chemistry);

	student.total = student.chemistry + student.maths + student.physics;

	printf("ma hoc sinh: %s\n", student.code);
	printf("ten hoc sinh: %s\n", student.name);
	printf("\n");
	printf("diem toan: %d\n", student.maths);
	printf("diem ly: %d\n", student.physics);
	printf("diem hoa: %d\n", student.chemistry);
	printf("diem tong: %d\n", student.total);

	getch();
	return 0;
}
