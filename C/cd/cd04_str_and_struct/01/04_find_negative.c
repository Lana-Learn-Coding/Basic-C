#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int negative_index = -1; /* index start at 0 so -1 mean not found. */
	int len;
	int *p;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];
	p = &a[0];

	int i;
	for (i = 0; i < len; i++) {
		printf("nhap phan tu %d/%d: ", i, len);
		scanf("%d", p);

		if (negative_index < 0 && *p < 0) {
			negative_index = i;
		}
		p++;
	}

	if (negative_index >= 0) {
		printf("tim thay so am %d tai vi tri %d\n",  *(a + negative_index), negative_index);
	} else {
		printf("khong tim thay so am\n");
	}

	getch();
	return 0;
}
