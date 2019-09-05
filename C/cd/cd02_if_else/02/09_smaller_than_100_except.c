#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int i;
	int even_cnt = 0;
	const int COL_MAX = 10;
	for (i = 0; i <= 100; i++) {
		int is_odd = i % 2 != 0;
		int is_valid = i != 5 &&
		               i != 7 &&
		               i != 53;

		if (is_odd && is_valid) {
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
