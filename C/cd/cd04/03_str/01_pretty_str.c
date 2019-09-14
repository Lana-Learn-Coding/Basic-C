#include <stdio.h>
#include <conio.h>
#include <string.h>

void convert_separator_to_space(char str[]);

void add_space_before_uppercase(char str[], int max_sz);

int is_uppercase(char chr);

int main(int argc, char const *argv[])
{
	int max_sz = 128;
	char str[max_sz];
	printf("nhap vao 1 chuoi, toi da %d ki tu: ", max_sz - 1);
	gets(str);

	/* upper first char */
	str[0] = toupper(str[0]);

	convert_separator_to_space(str);

	add_space_before_uppercase(str, max_sz);

	printf("chuoi da duoc chuan hoa: %s\n", str);
	getch();
	return 0;
}

void convert_separator_to_space(char str[]) {
	char separators[] = {' ', '_', '-', '\0'};
	int len = strlen(str);
	int separators_len = strlen(separators);
	int i;
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
}

void add_space_before_uppercase(char str[], int max_sz) {
	char filled_str[max_sz];
	int len = strlen(str);
	int chr_cnt = 1;
	int i;
	filled_str[0] = str[0];

	for (i = 1; i < len && chr_cnt < max_sz; i++) {
		char chr = str[i];
		if (is_uppercase(chr)) {
			/*
			* ignore if previous char already a spc,
			* otherwise insert space and shift char-
			* count to next index
			*/
			if (str[i - 1] != ' ') {
				filled_str[chr_cnt] = ' ';
				chr_cnt++;
			}
		}
		if (chr_cnt < max_sz) {
			filled_str[chr_cnt] = chr;
			chr_cnt++;
		} else {
			break;
		}
	}
	/* make sure that the end of string is NULL */
	if (chr_cnt >= max_sz) {
		filled_str[max_sz - 1] = '\0';
	}
	strcpy(str, filled_str);
}

int is_uppercase(char chr) {
	if (chr == ' ') {
		return 0;
	}
	return chr == toupper(chr);
}
