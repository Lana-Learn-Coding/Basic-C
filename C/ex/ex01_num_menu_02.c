#include <stdio.h>
#include <conio.h>

#define PRINT 1
#define CHECK_IS_ODD 2
#define PRINT_DIVISORS 3
#define CHECK_IS_PRIME 4
#define CHECK_IS_PERFECT 5
#define FIND_BIGGEST 6
#define EXIT_PROGRAM 7

/* Note that we haven't learned function yet */
int main(int argc, char** argv) {

	int opts = 0;
	int num;
	printf("nhap vao mot so nguyen: ");
	scanf("%d", &num);
	printf("\n");

	while (1) {
		printf("chon 1 trong cac lua chon sau: \n");
		printf("%d, in so vua nhap\n", PRINT);
		printf("%d, kiem tra so chan hay le\n", CHECK_IS_ODD);
		printf("%d, in ra cac uoc va tong cac uoc\n", PRINT_DIVISORS);
		printf("%d, kiem tra so co phai la nguyen to\n", CHECK_IS_PRIME);
		printf("%d, kiem tra so co phai la hoan hao\n", CHECK_IS_PERFECT);
		printf("%d, nhap 3 so , tim so lon nhat\n", FIND_BIGGEST);
		printf("%d, thoat\n", EXIT_PROGRAM);
		printf("lua chon cua ban la: ");
		scanf("%d", &opts);
		printf("\n");

		int is_valid_opts = opts >= 1 && opts <= 7;
		if (is_valid_opts) { break; }

		printf("lua chon %d khong hop le!\n", opts);
		printf("xin thu lai\n");
	}

	switch (opts) {
	case PRINT: {
		printf("so ban vua nhap la: %d\n", num);
		break;
	}
	case CHECK_IS_ODD: {
		if (num % 2 == 0)
			printf("%d la so chan\n", num);
		else
			printf("%d la so le\n", num);
		break;
	}
	case PRINT_DIVISORS: {
		printf("cac uoc so cua %d la ", num);
		int sum_divisor = 0;
		int i;
		for (i = 1; i <= num; i++) {
			if (num % i == 0) {
				printf("%4d ", i);
				sum_divisor += i;
			}
		}
		printf("\ntong cac uoc so cua %d la %d\n", num, sum_divisor);
		break;
	}
	case CHECK_IS_PRIME: {
		int is_prime = 1;
		int i;
		for (i = 2; i < num; i++) {
			if (num % i == 0) {
				is_prime = 0;
				break;
			}
		}

		if (num < 2) { is_prime = 0; } /* somehow 1 is not a prime number */
		if (is_prime)
			printf("%d la so nguyen to\n", num);
		else
			printf("%d khong phai la so nguyen to\n", num);
		break;
	}
	case CHECK_IS_PERFECT: {
		/* this sum already ignore the num as a divisor */
		int sum_divisor = 0;
		int i;
		for (i = 1; i < num; i++) {
			if (num % i == 0) {
				sum_divisor += i;
			}
		}
		if (sum_divisor == num)
			printf("%d la 1 so hoan hao\n", num);
		else
			printf("%d khong phai la so hoan hao\n", num );
		break;
	}
	case EXIT_PROGRAM: {
		printf("thoat chuong trinh...");
		exit(0);
	}
	/*
	* this case is special, its separate from other
	* as is not use the num, instead, use is own variable
	*/
	case FIND_BIGGEST: {
		int biggest;
		int cnt = 3;
		printf("tim so nguyen lon nhat trong %d so: \n", cnt);

		int i;
		int input_num;
		for (i = 1; i <= cnt; i++) {
			printf("nhap so thu %d/%d: ", i, cnt);
			scanf("%d", &input_num);

			/* first iter */
			if (i == 1) { biggest = input_num; }

			if (biggest < input_num) { biggest = input_num; }
		}
		printf("so lon nhat trong %d so vua nhap la: %d\n", cnt, biggest);
		break;
	}
	/*
	* in case something went wrong,
	* or the opts not checked carefully
	*/
	default: printf("co loi xay ra, chuong trinh da dung hoat dong!");
	}

	getch();
	return 0;
}
