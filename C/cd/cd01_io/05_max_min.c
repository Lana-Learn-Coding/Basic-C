#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int biggest, smallest;
	int cnt = 3;
	printf("tim so nguyen lon nhat trong %d so: \n", cnt);

	int i;
	int input_num;
	for (i = 1; i <= cnt; i++) {
		printf("nhap so thu %d/%d: ", i, cnt);
		scanf("%d", &input_num);

		/* first iter */
		if (i == 1) {
			biggest = input_num;
			smallest = input_num;
		}
		if (biggest < input_num) { biggest = input_num; }
		if (smallest > input_num) { smallest = input_num; }
	}

	printf("\n");
	printf("so lon nhat trong %d so vua nhap la: %d\n", cnt, biggest);
	printf("so nho nhat trong %d so vua nhap la: %d\n", cnt, smallest);

	getch();
	return 0;
}
