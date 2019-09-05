#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float biggest;
	int cnt = 3;
	printf("tim so nguyen lon nhat trong %d so: \n", cnt);

	int i;
	float input_num;
	for (i = 1; i <= cnt; i++) {
		printf("nhap so thu %d/%d: ", i, cnt);
		scanf("%f", &input_num);

		/* first iter */
		if (i == 1) { biggest = input_num; }
		if (biggest < input_num) { biggest = input_num; }
	}

	printf("\n");
	printf("so lon nhat trong %d so vua nhap la: %.f\n", cnt, biggest);

	getch();
	return 0;
}
