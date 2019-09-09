#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char cnt = 0;
	char find;
	char *char_p;
	char str[128];
	printf("nhap vao 1 chuoi: ");
	gets(str);
	printf("nhap vao 1 ki tu: ");
	scanf(" %c", &find);

	char_p = strchr(str, find);
	while (char_p != NULL) {
		cnt++;
		char_p = strchr(char_p + 1, find);
	}
	printf("ki tu %c xuat hien %d lan trong chuoi\n", find, cnt);

	getch();
	return 0;
}
