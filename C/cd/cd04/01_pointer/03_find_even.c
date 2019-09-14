#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int len = 5;
	int a[len];
	int even_index = -1; /* index start at 0 so -1 mean not found. */
	int *p = &a[0];

	int i;
	for (i = 0; i < len; i++) {
		int is_even;
		printf("nhap phan tu %d/%d: ", i, len);
		scanf("%d", p);
		is_even = *p % 2 == 0;

		if (even_index < 0 && is_even) {
			even_index = i;
		}
		p++;
	}

	if (even_index >= 0) {
		printf("tim thay so chan %d tai vi tri %d\n",  *(a + even_index), even_index);
	} else {
		printf("khong tim that so chan\n");
	}

	getch();
	return 0;
}
