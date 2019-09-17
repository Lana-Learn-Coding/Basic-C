#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student {
	char code[6];
	char name[31];
	int powerpoint;
	int excel;
	int word;
};

struct student get_student();

int main(int argc, char const *argv[])
{
	struct student student = get_student();

	printf("ma sinh vien: %s\n", student.code);
	printf("ten sinh vien: %s\n", student.name);
	printf("\n");
	printf("diem powerpoint: %d\n", student.powerpoint);
	printf("diem excel: %d\n", student.excel);
	printf("diem word: %d\n", student.word);

	getch();
	return 0;
}

struct student get_student()
{
	struct student student;
	printf("nhap ma sinh vien (toi da 5 ki tu): ");
	scanf("%s", &student.code[0]);
	fflush(stdin);
	printf("nhap ten sinh vien (toi da 50 ki tu): ");
	gets(&student.name[0]);
	fflush(stdin);
	printf("nhap diem powerpoint: ");
	scanf("%d", &student.powerpoint);
	printf("nhap diem excel: ");
	scanf("%d", &student.excel);
	printf("nhap diem word: ");
	scanf("%d", &student.word);
	return student;
}
