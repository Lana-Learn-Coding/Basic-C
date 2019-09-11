#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i;
	char separators[] = {'_', ' ', '-'};
	int separators_len;
	int len;
	char str[128];
	printf("nhap vao 1 chuoi: ");
	gets(str);
	len = strlen(str);
	separators_len = strlen(separators);
	printf("len %d\n", separators_len);

	/* upper first char */
	str[0] = toupper(str[0]);

	for (i = 1; i < len; i++) {
		char pre_chr = str[i - 1];
		int j;
		for (j = 0; j < separators_len; j++) {
			if (pre_chr == separators[j]) {
				str[i] = toupper(str[i]);
				str[i - 1] = ' ';
			}
		}
	}

	/* separate upper */
	for (i = 0; i < count; ++i) {
	}

	printf("chuoi da duoc viet hoa chu cai dau: %s\n", str);
	getch();
	return 0;
}
