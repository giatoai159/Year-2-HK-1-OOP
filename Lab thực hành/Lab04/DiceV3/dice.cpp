#include "dice.h"

Dice::Dice()
{
	srand((int)time(0));
	_rollCount = 0;
}

int Dice::Roll()
{
	_rollCount++;
	return (1+rand()%6);
}
