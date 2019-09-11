#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char find;
	char *char_p;
	char str[128];
	printf("nhap vao 1 chuoi: ");
	gets(str);
	printf("nhap vao 1 ki tu: ");
	scanf(" %c", &find);

	char_p = strchr(str, find);
	while (char_p != NULL) {
		printf("tim thay %c tai vi tri: %d\n", find, char_p - str);
		char_p = strchr(char_p + 1, find);
	}

	getch();
	return 0;
}
