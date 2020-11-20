#include"dice.h"

int main()
{
	Dice a, b, c;
	srand((int)time(0));
	int r = 1 + rand() % 20;
	for (int i = 0; i < r; i++)
		cout << a.Roll() << " ";
	cout << endl;
	r = 1 + rand() % 20;
	for (int i = 0; i < r; i++)
		cout << b.Roll() << " ";
	cout << endl;
	r = 1 + rand() % 20;
	for (int i = 0; i < r; i++)
		cout << c.Roll() << " ";
	cout << endl;
	cout << "Xuc sac a gieo " << a.getRC() << " lan." << endl;
	cout << "Xuc sac b gieo " << b.getRC() << " lan." << endl;
	cout << "Xuc sac c gieo " << c.getRC() << " lan." << endl;
	system("pause");
	return 0;
}