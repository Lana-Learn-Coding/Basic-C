#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int old, current, diff;
	long int money_per_kwh;
	printf("nhap so dien cu (kWh): ");
	scanf("%d", &old);
	printf("nhap so dien hien tai (kWh): ");
	scanf("%d", &current);

	diff = current - old;
	if (diff <= 50) { money_per_kwh = 1000; }
	if (diff > 50 && diff <= 100) { money_per_kwh = 2000; }
	if (diff > 100) { money_per_kwh = 3500; }

	printf("so tien dien la %li\n", (long int) diff * money_per_kwh);

	getch();
	return 0;
}
