#ifndef GET_RANDOM_NUMBER_IN_RANGE
#define GET_RANDOM_NUMBER_IN_RANGE

#include <stdlib.h>
#include <time.h>

/* https://www.geeksforgeeks.org/generating-random-number-range-c/ */
int getRandomNumberInRange(int lower, int higher)
{
    srand(time(NULL));
    return (rand() % (higher - lower + 1)) + lower;
}

#endif