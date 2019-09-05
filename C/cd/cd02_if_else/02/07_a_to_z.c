#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int i;
	for (i = 97; i <= 122; i++) {
		printf("%c ", (char) i);
	}

	getch();
	return 0;
}
