#include <iostream>
#include <string>
#include "Store.h"
#include "Game Room.h"
#include "Home.h"
#include "System Break.h"
#include "Bank.h"

using namespace std;

int main()
{
	int destination;

	color(11);

	cout << "Where would you like to go?: ";
	cin >> destination;

	cout << "\n";

	switch (destination)
	{
	case 1:
		storeFront();
		break;
	case 2:
		frontRoom();
		break;
	case 3:
		mainbank();
		break;
	case 4:
		home();
		break;
	default:
		systemBreak();
		break;
	}
}