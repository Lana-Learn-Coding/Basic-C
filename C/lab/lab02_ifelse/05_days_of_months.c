#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int month;
	printf("nhap thang: ");
	scanf("%d", &month);

	if (month > 12 || month < 1) {
		printf("thang khong hop le!\n");
	} else {
		switch (month) {
		case 2:
			printf("thang %d co 28 ngay\n", month);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("thang %d co 30 ngay\n", month);
			break;
		default:
			printf("thang %d co 31 ngay\n", month);
		}
	}

	getch();
	return 0;
}
