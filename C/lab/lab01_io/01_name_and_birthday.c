#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int birth_year;
	char name[20];
	int current_year = 2019;

	printf("Moi ban nhap ten: ");
	scanf("%s", &name);
	printf("Moi ban nhap nam sinh: ");
	scanf("%d", &birth_year);

	printf("xin chao ban %s, nam nay %d tuoi.", name, current_year - birth_year);

	getch();
	return 0;
}
