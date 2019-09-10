#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int sum = 0;
	int biggest;
	int i;
	int len;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];

	for (i = 0; i < len; i++) {
		printf("nhap phan tu %d/%d: ", (i + 1), len);
		scanf("%d", &a[i]);
	}

	printf("cac phan tu trong mang la: ");
	for (i = 0; i < len; i++) {
		int num = a[i];
		printf("%d ", num);

		sum += num;

		if (i == 0) { biggest = num; }
		if (biggest < num) { biggest = num; }
	}
	printf("\n");

	printf("tong cac phan tu trong mang la: %d\n", sum);
	printf("phan tu lon nhat trong mang la: %d\n", biggest);

	getch();
	return 0;
}
