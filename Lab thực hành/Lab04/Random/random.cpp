#include "random.h"

Random::Random()
{
	srand((int)time(0));
}

int Random::Next()
{
	return rand();
}

int Random::Next(int max)
{
	return (rand()%(max+1));
}
