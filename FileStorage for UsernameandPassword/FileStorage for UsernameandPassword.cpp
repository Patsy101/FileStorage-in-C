#include <fstream> // including filestream support provides functions for working with files directive at the start of the program
#include <string>// emulates a string data type
#include <iostream>

using namespace std;
// Created By Patrick Tricenio 2023
bool IsLoggedIn()

{
	string username, password, un, pw;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read(username + ".txt"); // input filestream for reading data from the file. it works like a cin function that reads from standard input
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)//(test-expression) { statements-to-execute-when-true}
	{
		return true;
	}
	else //statements-to-execute-when-false
	{
		return false;
	}
}


int main()//main console
{
	int choice;
	cout << "1. Register Username\n2: Login\nYour choice:"; cin >> choice;

	if (choice == 1)
	{
		string username, password, name;// adding the three declarations
		cout << "type your own username: "; cin >> username;// user types their own username
		cout << "Kia Ora!!" << name << endl;//greetings
		cout << "type your own password "; cin >> password;// password is visible
		cout << "Let's get started" << name << endl;
		cout << "Please re-enter your username: ";//user is asked to retype username
		cin.ignore(256, '\n');// Character input ignore 256 letters and \n is an end statement same thing applies with integer value of \0
		getline(cin, name);

		cout << "Thanks, " << name << endl;

		ofstream file; // for writing data to the file, it works like a cout function that writes to standard output.
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2)// back to option 2 // if and else statements have a boolean value of true and false
	{
		bool status = IsLoggedIn();

		if (!status)// (test-expression) { statements-to-execute-when-true}
		{
			cout << "False Login!" << endl;
			system("PAUSE");
			return 0;// signals an error 
		}
		else //statements-to-execute-when-false
		{
			cout << "Successfully logged in !" << endl;
			system("PAUSE");
			return 1;
		}
	}
}

