#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
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

	/* print all element in the array */
	printf("\ncac phan tu trong mang la: ");
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	/* print all odd element in the array */
	printf("\ncac phan tu le trong mang la: ");
	for (i = 0; i < size; i++) {
		int num = array[i];
		int is_odd = num % 2 != 0;
		if (is_odd) {
			printf("%d ", num);
		}
	}

	/* print all element which index is odd in the array */
	printf("\ncac phan tu co chi so le trong mang la: ");
	for (i = 0; i < size; i++) {
		int is_index_odd = i % 2 != 0;
		if (is_index_odd) {
			printf("%d ", array[i]);
		}
	}

	/* print all common multiple of 3 and 4 element in the array */
	printf("\ncac phan chia het cho 3 va 4 trong mang la: ");
	for (i = 0; i < size; i++) {
		int num = array[i];
		if (num % 4 == 0 && num % 3 == 0) {
			printf("%d ", num);
		}
	}

	getch();
	return 0;
}
