#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int a, b;
	printf("nhap 2 so nguyen a va b\n");
	scanf("%d %d", &a, &b);

	printf("tong 2 so la %d\n", a + b);
	printf("hieu 2 so la %d\n", a - b);
	printf("tich 2 so la %d\n", a * b);
	printf("thuong 2 so la %d (du %d)\n", a / b, a % b);
	
	getch();
	return 0;
}
