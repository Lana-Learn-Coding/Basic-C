#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	float a, b, c;
	int is_triagle, is_right_angled, is_isosceles, is_equilateral;
	printf("nhap 3 canh a b c cua tam giac\n");
	scanf("%f %f %f", &a, &b, &c);

	is_triagle = a > 0 && b > 0 && c > 0 &&
	             a + b > c &&
	             b + c > a &&
	             c + a > b;

	if (is_triagle) {
		printf("day la tam giac ");

		is_equilateral = a == b && b == c;
		is_isosceles = a == b ||
		               b == c ||
		               c == a;
		is_right_angled = a * a + b * b == c * c ||
		                  b * b + c * c == a * a ||
		                  c * c + a * a == b * b;

		/*
		* Note that is_isosceles and is_right_angled should never happen together
		* as we can never input root-square of 2 correctly.
		* But we still do this way here to cover that case.
		*/
		if (is_right_angled) { printf("vuong "); }
		if (is_isosceles && !is_equilateral) { printf("can "); }
		if (is_equilateral) { printf("deu ");}
	} else {
		printf("day khong phai la tam giac!\n");
	}

	getch();
	return 0;
}
