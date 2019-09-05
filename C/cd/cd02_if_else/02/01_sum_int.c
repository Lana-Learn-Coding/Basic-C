#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int bigger, smaller;
	int sum = 0;
	printf("nhap 2 so nguyen a va b: ");
	scanf("%d %d", &bigger, &smaller);

	if (bigger < smaller) {
		int temp =	smaller;
		smaller = bigger;
		bigger = temp;
	}

	int i;
	for (i = smaller + 1; i < bigger; i++) {
		sum += i;
	}

	printf("tong cac so nam giua %d va %d la %d\n", smaller, bigger, sum);

	getch();
	return 0;
}
