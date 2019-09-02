#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{

	int sum = 0, sum_square = 0, sum_even = 0;
	int biggest;

	int size;
	printf("nhap kich thuoc cua mang: ");
	scanf("%d", &size);

	int array[size];
	/* read element to array */
	int i;
	for (i = 1; i <= size ; i++) {
		printf("nhap phan tu thu %d/%d cua mang: ", i, size);
		scanf("%d", &array[i - 1]);
	}
	printf("\n");

	for (i = 0; i < size; i++) {
		int num = array[i];
		int is_even = num % 2 == 0;
		int num_square = num * num;

		/* calculate various sums */
		sum += num;
		sum_square += num_square;
		if (is_even) { sum_even += num; }

		/* find biggest */
		if (i == 0) { biggest = num; }
		if (biggest < num) { biggest = num; }
	}

	printf("tong binh phuong cac phan tu trong mang la %d\n", sum_square);
	printf("tong cac phan tu chan trong mang la %d\n", sum_even);
	printf("trung binh cong cac trong mang la %.2f\n", (float) sum / size);
	printf("so lon nhat trong mang la %d\n", biggest);

	getch();
	return 0;
}
