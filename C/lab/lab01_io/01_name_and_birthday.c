#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int yearOfBirth;
	char name[20];
	int currentYear = 2019;

	printf("Moi ban nhap ten: ");
	scanf("%s", &name);
	printf("Moi ban nhap nam sinh: ");
	scanf("%d", &yearOfBirth);

	printf("xin chao ban %s, nam nay %d tuoi.", name, currentYear - yearOfBirth);

	getch();
	return 0;
}