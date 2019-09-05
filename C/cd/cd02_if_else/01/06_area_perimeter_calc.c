#include <stdio.h>
#include <conio.h>
#include <math.h>

#define TRIAGLE 1
#define QUADRILATERAL 2

int main(int argc, char const *argv[])
{
	int opts;
	while (1) {
		printf("chon 1 lua chon trong menu sau:\n");
		printf("%d, tam giac\n", TRIAGLE);
		printf("%d, tu giac\n", QUADRILATERAL);
		printf("lua chon cua ban la: ");
		scanf("%d", &opts);

		/* valid opts in range of available options */
		if (opts < 1 || opts > 2) {
			printf("lua chon khong hop le!\n\n");
			continue;
		}

		printf("\n");
		if (opts == TRIAGLE) {
			float a, b, c;
			int is_triagle, is_right_angled, is_isosceles, is_equilateral;
			float area, perimeter;
			printf("nhap 3 canh a b c cua tam giac: ");
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

				perimeter = a + b + c;
				/* heron's formula */
				area = sqrt(perimeter *
				            (perimeter - 2 * a) *
				            (perimeter - 2 * b) *
				            (perimeter - 2 * c)) / 4;
				printf("chu vi tam giac la %.2f\n", perimeter);
				printf("dien tich tam giac la %.2f\n\n", area);
			} else {
				printf("day khong phai la tam giac!\n\n");
				continue;
			}
		}

		/*
		* Note that information about 4 edges only can't help.
		* We must also know at least 1 angles in special case,
		* and 2 in irregular case.
		*/
		printf("\n");
		if (opts == QUADRILATERAL) {
			float a, b, c, d;
			float perimeter;
			int is_quadrilateral, is_square, is_rectangle;
			printf("nhap 4 canh cua tu giac : ");
			scanf("%f %f %f %f", &a, &b, &c, &d);
			perimeter = a + b + c + d;

			is_quadrilateral = a > 0 &&
			                   b > 0 &&
			                   c > 0 &&
			                   d > 0;
			if (is_quadrilateral) {
				is_square = a == b && b == c && c == d;
				is_rectangle = (a == b && c == d) ||
				               (a == c && b == d) ||
				               (a == d && b == c) ;
				if (is_square) {
					printf("day CO THE la hinh vuong\n");
				} else if (is_rectangle) {
					printf("day CO THE la hinh chu nhat\n");
				} else {
					printf("thieu thong tin de tinh toan dien tich\n");
				}
				printf("chu vi cua hinh tu giac tren la %f\n\n", perimeter);
			} else {
				printf("day khong phai la tu giac!\n\n");
			}
		}
	}

	getch();
	return 0;
}
