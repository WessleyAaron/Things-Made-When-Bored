#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool yesno = true;
int userChoice, userBankChoice;
string username, password;
string usernameAttempt, passwordAttempt;
double userBalanceMoney, moneyDeposit, moneyWithdrawal;

int main();

int logoff() //when you leave the bank terminal
{
	cout << "Goodbye\n" << endl;

	main(); //takes you back to the main function

	return 0;
}

int withdrawal() //where you take money out of your account
{
	system("cls");

	if (userBalanceMoney == 0.00) //when you don't have any money in your account
	{
		color(12);

		cout << "You don't have any money to take out\n" << endl;
	}

	else if (userBalanceMoney > 0.00) //while you have at least 1 penny in your account
	{
		cout << "How much money would you like to withdrawal? $";
		cin >> moneyWithdrawal; //user enters how much money to take out of the account

		cout << "\n";

		if (moneyWithdrawal > userBalanceMoney) //when you try to take out more money than you have
		{
			color(12);

			cout << "You don't have that much money to take out\n" << endl;
		}

		else if (moneyWithdrawal <= userBalanceMoney) //when you try to take out money that is less than or equal too what you have in your account
		{
			userBalanceMoney = userBalanceMoney - moneyWithdrawal; //math that takes money out of the account

			color(10);

			cout << "Thank you for your withdrawal\n" << endl;
		}
	}

	//goes back to the account function

	return 0;
}

int deposit() //where you deposit your money
{
	system("cls");

	cout << "How much money would you like to deposit? $";
	cin >> moneyDeposit; //user enters how much money to deposit

	cout << "\n";

	userBalanceMoney = userBalanceMoney + moneyDeposit; //math that adds deposit to what is already in the account

	color(10);

	cout << "Thank you for your deposit\n" << endl;

	//goes back to the account function

	return 0;
}

int account() //where you choose what you want to do (take in/take out money) or leave
{
	cout << fixed << showpoint;
	cout << setprecision(2); //makes it so each money display shows 2 decimal points

	do{
		color(14);

		cout << "Your current balance is $" << userBalanceMoney << "\n" << endl; //shows your current balance
		cout << "What would you like to do? [1] Deposit, [2] Withdrawal, [3] Log Off: "; //user chooses what to do
		cin >> userBankChoice;

		cout << "\n";

		switch (userBankChoice)
		{
		case 1:
			deposit(); //takes you to the deposit function
			break;
		case 2:
			withdrawal(); //takes you to the withdrawal function
			break;
		}
	}

	while (userBankChoice != 3);

	logoff(); //takes you to the log off function

	return 0;
}

int signIn() //where you sign in
{
	cout << "Username: ";
	cin >> usernameAttempt; //where you attempt to log in, username attempt

	cout << "\n";

	cout << "Password: ";
	cin >> passwordAttempt; //password attempt

	cout << "\n";

	if (usernameAttempt == username && passwordAttempt == password) //when your username and password both work
	{
		account(); //takes you to the account function
	}

	else //when you entered something wrong
	{
		cout << "Something was wrong. Please try again\n" << endl;

		signIn(); //replays the sign in function
	}

	return 0;
}

int accountCreate() //where you create your account
{
	system("cls");

	cout << "Please create a username: ";
	cin >> username; //saves your username

	cout << "\n";

	cout << "Please create a password: ";
	cin >> password; //saves your password

	cout << "\n";

	cout << "Account created. Please Log in" << endl;

	cout << "\n";

	signIn(); //takes you to the sign in function

	return 0;
}

int mainbank() //initial starting point
{
	system("cls");

	int userSignIn, userCreate;

	color(14);

	cout << "Welcome to the bank terminal\n" << endl;
	cout << "Do you have an account? [1] Yes or [2] No: ";
	cin >> userChoice;

	cout << "\n";

	if (userChoice == 1) //if you've already created an account before
	{
		cout << "Would you like to sign in? [1] Yes or [2] No: ";
		cin >> userSignIn;

		cout << "\n";

		switch (userSignIn)
		{
		case 1:
			signIn(); //takes you to the sign in function
			break;
		case 2:
			mainbank(); //replays the main function
			break;
		}
	}

	else if (userChoice == 2) //if this is your first time running this program
	{
		cout << "Would you like to create an account? [1] Yes or [2] No: ";
		cin >> userCreate;

		cout << "\n";

		switch (userCreate)
		{
		case 1:
			accountCreate(); //takes you to the account create function
			break;
		case 2:
			mainbank(); //replays the main function
			break;
		}
	}

	return 0;
}