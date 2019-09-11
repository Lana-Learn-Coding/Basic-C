#include <stdio.h>
#include <conio.h>

void read_one(int num);

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap so nguyen co 1 chu so: ");
	scanf("%u", &num);

	read_one(num);

	getch();
	return 0;
}

void read_one(int num) {
	if (-9 <= num && num <= 9) {
		printf("So ");
		if (num < 0) {
			num *= -1;
			printf("am ");
		}
		switch (num) {
		case 0:
			printf("khong\n");
			break;
		case 1:
			printf("mot\n");
			break;
		case 2:
			printf("hai\n");
			break;
		case 3:
			printf("ba\n");
			break;
		case 4:
			printf("bon\n");
			break;
		case 5:
			printf("nam\n");
			break;
		case 6:
			printf("sau\n");
			break;
		case 7:
			printf("bay\n");
			break;
		case 8:
			printf("tam \n");
			break;
		case 9:
			printf("chin \n");
			break;
		}
	} else {
		printf("loi nhap lieu\n");
	}
}
