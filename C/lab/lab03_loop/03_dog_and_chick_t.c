#include <stdio.h>
#include <conio.h>

/*
* dogs + chickens = 36
* dogs_legs + chickens_legs = 100
*
* how many dogs? how many chickens?
*/
int main(int argc, char const *argv[])
{
	const int LEGS_PER_DOG = 4, LEGS_PER_CHICKEN = 2;
	const int TOTAL_LEGS = 100, TOTAL = 36;

	int dogs, chickens;
	/*
	* As a dog has 4 legs and chicken has only 2:
	* If there were only chickens, the total legs would smaller than 100.
	* By knowing how many legs was missing, we can find out how many dogs
	* should be there.
	*
	* Dog legs - chicken legs = 2, so each 2 legs missing there will be 1 dog.
	*/
	int full_chicken_leg = TOTAL * LEGS_PER_CHICKEN;
	int missing_leg = TOTAL_LEGS - full_chicken_leg;
	dogs = missing_leg / 2;
	chickens = TOTAL - dogs;

	printf("so cho la %d\n", dogs);
	printf("so ga la %d\n", chickens);

	getch();
	return 0;
}
