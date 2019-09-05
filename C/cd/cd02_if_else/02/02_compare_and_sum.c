#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int smaller, bigger;
	int is_valid = 0;
	int sum_odd = 0, sum_even = 0;
	while (!is_valid) {
		printf("nhap 2 so nguyen a va b: ");
		scanf("%d %d", &smaller, &bigger);

		is_valid =  bigger > smaller && bigger != smaller + 1;
		if (!is_valid) {
			printf("khong hop le! \n");
			printf("1. so thu 2 khong duoc nho hon so thu 1\n");
			printf("2. so thu 2 khong duoc lon hon so thu 1 mot don vi\n");
			printf("\n");
		}
	}

	int i;
	for (i = smaller + 1; i < bigger; i++) {
		if (i % 2 == 0) {
			sum_even += i;
		} else {
			sum_odd += i;
		}
	}

	printf("tong cac so le nam giua %d va %d la %d\n", smaller, bigger, sum_odd);
	printf("tong cac so chan nam giua %d va %d la %d\n", smaller, bigger, sum_even);

	getch();
	return 0;
}
