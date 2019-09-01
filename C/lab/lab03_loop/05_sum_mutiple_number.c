#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int sum = 0;
	printf("Chuong trinh tinh tong:\n");

	/* keep ask for input until get 0 */
	int i = 1;
	while (1) {
		int num;
		printf("nhap so thu %d: ", i);
		scanf("%d", &num);
		sum += num;
		i++;

		if (num == 0) { break; }
	}
	printf("tong cua %d so vua nhap la: %d\n", (i - 1), sum);

	getch();
	return 0;
}
