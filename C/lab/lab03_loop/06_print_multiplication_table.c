#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num;

	while (1) {
		printf("nhap 1 so tu 1 den 9: ");
		scanf("%d", &num);

		if (num < 10 && num > 0) { break; }
		printf("khong hop le!\n");
	}

	printf("\nbang cuu chuong cua %d la\n", num);

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}

	getch();
	return 0;
}