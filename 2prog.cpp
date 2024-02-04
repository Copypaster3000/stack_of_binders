//*************************************************************************************************
//2prog.cpp																					      *
//Drake Wheeler																					  * 
//CS163																					          *
//Program 2																						  *
//5/3/2023																						  * 
//This file is the main file of the program. Inside of main all the other functions are organized *
//and called to test the stack and queue classes. This program allows the user to edit a digital  *
//pile of binders. They can only add and remove from the top. It also allows the user to create   *
//and edit a to-do list which can then be added to the top binder.                                *
//*************************************************************************************************

#include "front.h"
using namespace std;

int main()
{
		int choice {0}; //Holds user's menu options

		front tester; //Instance of front created to call tester functions

		tester.welcome(); //Welcomes user explains program

		do
		{
				choice = tester.menu();

				if (choice == 1) tester.option_one(); //Adds binder to digital pile of binders
													  
				if (choice == 2) tester.option_two(); //Displays all binders to user

				if (choice == 3) tester.option_three(); //Removes a binder from the pile

				if (choice == 4) tester.option_four(); //Display binder on top of pile to user

				if (choice == 5) tester.option_five(); //Create and edit todo list, then add it to biner on top of pile

				if (choice == 6) tester.option_six(); //Let's user see binder and to-do list on top of the stack

		} while (choice != 8); //Loops until user chooses to exit program

		cout << "\nThis program has ended.\n" << endl;

		return 0;
}

