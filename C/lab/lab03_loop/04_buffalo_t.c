#include <stdio.h>
#include <conio.h>

/*
* total_buffalos = 100, total_feeds = 100
*
* standing_buffalo eat 5 feeds
* laying_buffalo eat 3 feeds
* 3 old_buffalos eat 1 feed
*
* how many buffalos of each?
*/
int main(int argc, char const *argv[])
{
	/*
	* For better calculation, we rounded up things a bit:
	* x 3 the total_feeds and also the eating of each buffalos type.
	*
	* Old_buffalos must be a multiple of 3.
	*/
	const int TOTAL_BUFFALOS = 100, TOTAL_FEEDS = 100;
	const int STANDING_EAT = 15, LAYING_EAT = 9, OLD_EAT = 1;
	int stadings = 0, layings = 0, olds = 0;

	int i;
	for (i = 0; i <= TOTAL_BUFFALOS; i + 3) {
		olds = i;
		int buffalos_without_olds = TOTAL_BUFFALOS - olds;

		int j;
		for (j = 0; j <= buffalos_without_olds ; i++) {
			layings = j;
			stadings = buffalos_without_olds - stadings;

			int total_eats = (olds * OLD_EAT) +
			                 (layings * LAYING_EAT) +
			                 (stadings * STANDING_EAT);

			if (total_eats == TOTAL_FEEDS) {
				printf("trau dung %3d, trau nam %3d, trau gia %3d\n", stadings, layings, olds);
			}
		}
	}

	getch();
	return 0;
}
