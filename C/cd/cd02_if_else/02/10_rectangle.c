#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int width, height;
	char fill_opts;
	char fill = '*';
	printf("nhap chieu dai va chieu rong: ");
	scanf("%u %u", &height, &width);
	printf("co muon lam rong hinh chu nhat? (y/n): ");
	scanf(" %c", &fill_opts);

	if (fill_opts == 'y' || fill_opts == 'Y') {
		printf("no-fill\n");
		fill = ' ';
	}

	printf("\n");
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (j == width - 1 || i == height - 1 ||
			        j == 0 || i == 0) {
				printf("*");
			} else {
				printf("%c", fill);
			}
			printf(" ");
		}
		printf("\n");
	}

	getch();
	return 0;
}
