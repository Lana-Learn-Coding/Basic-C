#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int i;
	int even_cnt = 0;
	const int COL_MAX = 10;
	for (i = 2; i <= 100; i++) {
		int is_even = i % 2 == 0;

		if (is_even) {
			printf("%4d ", i);

			/* split line each COL_MAX printed */
			even_cnt++;
			if (even_cnt % COL_MAX == 0) {
				printf("\n");
			}
		}
	}

	getch();
	return 0;
}
