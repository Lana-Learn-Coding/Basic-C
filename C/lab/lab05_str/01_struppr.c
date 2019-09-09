#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int len;
	char str[128];
	printf("nhap vao 1 chuoi: ");
	gets(str);
	len = strlen(str);

	int i;
	for (i = 0; i <  len; i++) {
		str[i] = toupper(str[i]);
	}

	printf("chuoi da duoc chuyen thanh viet hoa: %s\n", str);
	getch();
	return 0;
}
