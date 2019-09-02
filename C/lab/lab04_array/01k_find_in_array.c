#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int find;
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

	printf("nhap gia tri can tim: ");
	scanf("%d", &find);
	for (i = 0; i < size; i++) {
		if (array[i] == find) {
			printf("tim thay %d tai vi tri %d trong mang\n", find, i + 1);
			break;
		}

		if (i == size - 1) { /* last element */
			printf("khong tim thay %d trong mang\n", find);
		}
	}

	getch();
	return 0;
}
