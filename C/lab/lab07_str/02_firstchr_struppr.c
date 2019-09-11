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

	/* upper first char */
	str[0] = toupper(str[0]);
	int i;
	for (i = 1; i < len; i++) {
		char pre_chr = str[i - 1];
		if (pre_chr == ' ') {
			str[i] = toupper(str[i]);
		}
	}

	printf("chuoi da duoc viet hoa chu cai dau: %s\n", str);
	getch();
	return 0;
}
