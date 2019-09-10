#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int negative_index = -1; /* index start at 0 so -1 mean not found. */
	int len;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];

	int i;
	for (i = 0; i < len; i++) {
		printf("nhap phan tu %d/%d: ", (i + 1), len);
		scanf("%d", &a[i]);

		if (negative_index < 0 && a[i] < 0) {
			negative_index = i;
		}
	}

	if (negative_index >= 0) {
		printf("tim thay so am %d tai vi tri %d\n",  a[negative_index], negative_index);
	} else {
		printf("khong tim that so am\n");
	}

	getch();
	return 0;
}
