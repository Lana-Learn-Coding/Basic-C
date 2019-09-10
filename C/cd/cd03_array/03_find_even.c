#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int len = 5;
	int a[len];
	int even_index = -1; /* index start at 0 so -1 mean not found. */

	int i;
	for (i = 0; i < len; i++) {
		int is_even;
		printf("nhap phan tu %d/%d: ", (i + 1), len);
		scanf("%d", &a[i]);
		is_even = a[i] % 2 == 0;

		if (even_index < 0 && is_even) {
			even_index = i;
		}
	}

	if (even_index >= 0) {
		printf("tim thay so chan %d tai vi tri %d\n",  a[even_index], even_index);
	} else {
		printf("khong tim that so chan\n");
	}

	getch();
	return 0;
}
