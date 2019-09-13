#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int max_sz = 128;
	int len;
	char longest_str[max_sz];
	char str[max_sz];
	char *p;
	printf("nhap vao 1 chuoi, toi da %d ki tu: ", max_sz - 1);
	gets(str);
	p = &str[0];
	len = strlen(str);


	int i;
	int pre_index = 0, max_index = 0;
	int len_max = 0;
	for (i = 0; i < len; i++) {
		char current = str[i];
		char nxt = str[i + 1];
		if (current != ' ') {
			if (nxt == ' ' || nxt == '\0') {
				int sub_str_len = (i + 1) - pre_index;
				if (len_max < sub_str_len) {
					len_max = sub_str_len;
					max_index = i - sub_str_len;
				}
			}
		} else {
			pre_index = i + 1;
		}
	}

	p += max_index;
	strncpy(longest_str, p , len_max);
	longest_str[len_max] = '\0';
	printf("chuoi dai nhat co %d ki tu\n", len_max);
	printf("chuoi dai nhat la: %s", longest_str);

	getch();
	return 0;
}
