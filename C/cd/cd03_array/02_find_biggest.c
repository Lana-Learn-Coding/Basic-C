#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int len = 5;
	int a[len];
	int biggest , smallest;

	int i;
	for (i = 0; i < len; i++) {
		int num;
		printf("nhap phan tu %d/%d: ", (i + 1), len);
		scanf("%d", &a[i]);
		num = a[i];

		if (i == 0) {
			biggest = num;
			smallest = num;
		}
		if (biggest < num) {
			biggest = num;
		}
		if (smallest > num) {
			smallest = num;
		}
	}

	printf("phan tu lon nhat la: %d\n", biggest);
	printf("phan tu nho nhat la: %d\n", smallest);

	getch();
	return 0;
}
