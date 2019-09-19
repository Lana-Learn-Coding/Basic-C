#include <stdio.h>
#include <stdlib.h>

#define INPUT 1
#define PRINT 2
#define EXIT 3

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int is_input_valid = 0;
	int num;

	/* menu */
	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap du lieu\n", INPUT);
			printf("%d. in du lieu vua nhap\n", PRINT);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts > INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = (is_input_valid && opts != INPUT) || opts == EXIT;
			while (!is_input_valid) {
				printf("nhap du lieu: ");
				scanf("%d", &num);
				is_input_valid = 1;
			}
		} while (!is_opts_valid);


		switch (opts) {
		case PRINT:
			printf("du lieu da nhap: %d\n", num);
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin sua lai\n");
		}
	}

	return 0;
}
