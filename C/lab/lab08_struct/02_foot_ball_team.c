#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct player {
	char name[31];
	int number;
};

struct team {
	char code[6];
	char name[31];
	struct player players[30];
	int size;
};

struct player get_player();

int main(int argc, char const *argv[])
{
	struct team team;

	printf("nhap ma doi bong (toi da 5 ki tu): ");
	scanf("%s", &team.code);
	fflush(stdin);
	printf("nhap ten doi bong (toi da 30 ki tu): ");
	gets(&team.name[0]);
	fflush(stdin);
	printf("nhap so luong cau tu doi bong (toi da 30): ");
	scanf("%d", &team.size);
	printf("nhap cac cau thu trong doi bong:\n");

	int i;
	for (i = 0; i < team.size; i++) {
		printf("%d. ", i + 1);
		team.players[i] = get_player();
	}
	printf("\n");
	printf("ma doi bong: %s\n", team.code);
	printf("ten doi bong: %s\n", team.name);
	printf("danh sach cau thu:\n");
	for (i = 0; i < team.size; i++) {
		struct player player = team.players[i];
		printf("%d. %s\n", player.number, player.name);
	}

	getch();
	return 0;
}

struct player get_player()
{
	struct player player;
	fflush(stdin);
	printf("nhap ten cau thu (toi da 30 ki tu): ");
	gets(&player.name[0]);
	fflush(stdin);
	printf("nhap so ao cau thu: ");
	scanf("%d", &player.number);
	return player;
}
