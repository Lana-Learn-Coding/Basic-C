#include <stdio.h>
#include <conio.h>

/* Check whether a num is odd and if is a common-multiple of 3 and 5 */
int main(int argc, char const *argv[])
{
	int num;
	int is_odd, is_common_multiple_3and5;

	printf("nhap so nguyen\n");
	scanf("%d", &num);

	is_odd = (num % 2) != 0;
	is_common_multiple_3and5 = (num % 3) == 0 && (num % 5) == 0;

	if (is_odd)
		printf("day la so le\n");
	else
		printf("day la so chan\n");

	if (is_common_multiple_3and5)
		printf("chia het cho 3 va 5\n");
	else
		printf("khong chia het cho 3 va 5\n");

	getch();
	return 0;
}
