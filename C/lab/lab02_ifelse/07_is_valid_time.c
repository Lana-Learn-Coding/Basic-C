#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int seconds, hours, minutes;
	int is_valid;
	printf("nhap gio phut giay theo dinh dang hh:mm:ss ");
	scanf("%d:%d:%d", &hours, &minutes, &seconds);

	is_valid = (59 >= seconds && seconds >= 0 ) &&
	           (59 >= minutes && minutes >= 0) &&
	           (24 >= hours && hours >= 0);

	printf("%d gio %d phut %d giay ", hours, minutes, seconds);
	if (is_valid)
		printf("hop le\n");
	else
		printf("khong hop le\n");

	getch();
	return 0;
}
