#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int birth_year;
	int current_year = 2019;

	printf("moi ban nhap nam sinh: ");
	scanf("%d", &birth_year);

	printf("nam nay ban %d tuoi.", current_year - birth_year);

	getch();
	return 0;
}
