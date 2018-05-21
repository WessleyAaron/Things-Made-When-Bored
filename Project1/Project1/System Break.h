#include <iostream>

using namespace std;

int systemBreak()
{
	color(12);

	cout << "You fucked up if you made it here\n" << endl;
	cout << "Restart and try again dumbass\n" << endl;

	color(7);

	system("pause");
	return 0;
} 