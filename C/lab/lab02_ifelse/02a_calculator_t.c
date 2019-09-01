#include <stdio.h>
#include <conio.h>

#define MULTIPLICATION '*'
#define SUBTRACTION '-'
#define ADDITION '+'
#define DIVISION '/'

int main(int argc, char const *argv[])
{
	int m, n;
	char operator;

	printf("nhap 2 so tu nhien m va n\n");
	scanf("%d %d", &m , &n);

	printf("chon 1 phep tinh\n");
	printf("phep chia: %c\n", DIVISION);
	printf("phep nhan: %c\n", MULTIPLICATION);
	printf("phep cong: %c\n", ADDITION);
	printf("phep tru: %c\n", SUBTRACTION);
	scanf("%c", &operator);

	switch (operator) {
	case MULTIPLICATION:
		printf("%d nhan %d bang %d\n", m, n, m * n );
		break;
	case ADDITION:
		printf("%d cong %d bang %d\n", m, n, m + n );
		break;
	case DIVISION:
		printf("%d chia %d bang %.2f\n", m, n, (float)(m / n));
		break;
	case SUBTRACTION:
		printf("%d tru %d bang %d\n", m, n, m - n );
		break;
	default:
		printf("phep tinh khong hop le!\n");
	}

	getch();
	return 0;
}
