#include <stdio.h>
#include <conio.h>

#define INPUT 1
#define CHECK_IS_ODD 2
#define CHECK_IS_PRIME 3
#define PRINT_DIVISOR 4
#define EXIT_PROGRAM 5

/* Note that we haven't learned function yet */
int main(int argc, char const *argv[])
{

	int opts = INPUT;
	int is_inputted = 0;
	int num;

	/*
	* Ask for options:
	*  if opts == input, get the input and ask again.
	*  if opts != input then before execute ask for input number.
	*/
	while (opts ==  INPUT) {
		printf("chon 1 lua chon trong menu sau: \n");
		printf("%d, nhap 1 so\n", INPUT);
		printf("%d, kiem tra chan le\n", CHECK_IS_ODD);
		printf("%d, kiem tra so nguyen to\n", CHECK_IS_PRIME);
		printf("%d, in cac uoc cua so\n", PRINT_DIVISOR);
		printf("%d, thoat chuong trinh\n", EXIT_PROGRAM);
		printf("lua chon cua ban la: ");
		scanf("%d", &opts);
		printf("\n");

		if (opts == INPUT) {
			printf("xin nhap 1 so: ");
			scanf("%d", &num);
			is_inputted = 1;
		}

		/* valid the options and make sure number is inputted correctly */
		int is_valid = is_valid = 1 <= opts && opts <= 5;
		while (!is_inputted || !is_valid) {
			if (opts == EXIT_PROGRAM) { break; }

			if (!is_valid) {
				printf("lua chon khong hop le! \n");
				printf("lua chon cua ban la: ");
				scanf("%d", &opts);
				is_valid = 1 <= opts && opts <= 5;
			} else if (!is_inputted) {
				printf("xin nhap 1 so: ");
				scanf("%d", &num);
				is_inputted = 1;
			}
		}
		printf("\n");
	}

	/*
	* Excute based on options.
	* Note that the input number and opts
	* are already validated above, so this
	* block focus on excution.
	*/
	switch (opts) {
	case CHECK_IS_ODD: {
		int is_odd = num % 2 == 0;
		if (is_odd)
			printf("%d la so chan\n", num);
		else
			printf("%d la so le\n", num );
		break;
	}
	case PRINT_DIVISOR: {
		printf("cac uoc cua %d la: ", num);
		int i;
		for (i = 1; i <= num; i++) {
			if (num % i == 0) {
				printf("%4d", i);
			}
		}
		break;
	}
	case CHECK_IS_PRIME: {
		int i;
		int is_prime = 1;
		for (i = 2; i < num; i++) {
			if (num % i == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime)
			printf("%d la so nguyen to\n", num);
		else
			printf("%d khong phai so nguyen to\n", num);

		break;
	}
	case EXIT_PROGRAM: {
		exit(0);
	}
	default: {
		printf("chuong trinh da dung hoat dong!\n");
	}
	}

	getch();
	return 0;
}
