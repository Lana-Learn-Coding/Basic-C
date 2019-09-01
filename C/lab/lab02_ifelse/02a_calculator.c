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
	/*
	* Notice the space before %c
	*
	* 1. ENTER key press generates a \n, which is a vaild input for %c format specifier,
	* adding a space before %c tells scanf() to ignore all leading whitespace-like inputs,
	* (including that previously stored \n) and read the first non-whitespace character from stdin.
	*
	* 2. As for the case with %d format specifier,
	* it consumes (and ignores) any leading whitespace-like inputs before scanning for numeric inputs,
	* so the "%d" case does not suffer any issues.
	*
	* Or, you can use fflush(stdin) before scanf() instead
	*/
	scanf(" %c", &operator);

	switch (operator) {
	case MULTIPLICATION:
		printf("%d nhan %d bang %d\n", m, n, m * n );
		break;
	case ADDITION:
		printf("%d cong %d bang %d\n", m, n, m + n );
		break;
	case DIVISION:
		/*
		* If casting the result only (float) (m / n) if n > m gonna return 0.0,
		* because in that case, we're performing integer division before casting to float,
		* so we're casting result of the integer division.
		*
		* If we want to do floating point division, you need to divide floating point values in the first place.
		* Prefer denominator over numerator (Why ?) (numerator / denominator)
		*/
		printf("%d chia %d bang %.2f\n", m, n, m / (float) n);
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
