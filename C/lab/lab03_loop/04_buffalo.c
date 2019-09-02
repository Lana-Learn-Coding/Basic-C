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
	const int TOTAL_BUFFALOS = 100, TOTAL_FEEDS = 300;
	const int STANDING_EAT = 15, LAYING_EAT = 9, OLD_EAT = 1;
	int standings = 0, layings = 0, olds = 0;

	int i;
	for (i = 0; i <= TOTAL_BUFFALOS; i += 3) {
		olds = i;
		/*
		* Get the number of standing_buffalos and laying_buffalos
		* based on old_buffalos predicted.
		* Hard to understand, but its faster than nested loop.
		*
		* WARNING: here comes the math
		*/
		int buffalos_left = TOTAL_BUFFALOS - olds;
		int feeds_left = TOTAL_FEEDS - olds * OLD_EAT;
		standings = (feeds_left - LAYING_EAT * buffalos_left) /
		            (STANDING_EAT - LAYING_EAT);
		layings = buffalos_left - standings;

		if ( standings > 0 && layings > 0) {
			/*
			* check the result of standings and layings calculation
			* by re-calculate the total feed consummation.
			*/
			int total_feeds = (olds * OLD_EAT) +
			                  (layings * LAYING_EAT) +
			                  (standings * STANDING_EAT);
			if (total_feeds == TOTAL_FEEDS) {
				printf("trau dung %3d, trau nam %3d, trau gia %3d\n", standings, layings, olds);
			}
		}
	}

	getch();
	return 0;
}
