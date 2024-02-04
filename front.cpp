//front.cpp
//Drake Wheeler
//CS163
//Program 2
//4/23/2023
//This file holds the definitions for the front class which interacts with the user and works
//with the public back-end functions to store, retrieve, and edit data

#include "front.h"
using namespace std;

front::front()
{
}



front::~front()
{
}



void front::welcome(void)
{
	cout << "Hello, this program allows you to keep a digital pile of binders in which you can store to-do lists." << endl;
    cout << "Select options from the menu to first create and interact with the binders. After making a binder" << endl;
	cout << "you can choose to make a to-do list and edit it and interact with it. Then it will be added to the" << endl;
	cout << "binder on the top of the pile. Try all the menu options to see all the ways you interact with the binders" << endl;
	cout << "and to-do lists." << endl;


	return;
}



int front::menu(void)
{
	int choice {0};

	cout << "\nSelect an option from the menu below" << endl;
	cout << "1) Add a new binder to your digital pile of binders" << endl;
	cout << "2) View all binders in the pile" << endl;
	cout << "3) Remove a binder from the top of the pile" << endl;
	cout << "4) View binder on the top of the pile" << endl;
	cout << "5) Make and interact with a to-do list then add it to the binder on the top of the pile" << endl;
	cout << "6) View the binder on the top of the pile and it's to-do list" << endl;
	cout << "8) Exit program" << endl;

	choice = get_integer();

	return choice;
}



void front::option_one(void)
{
	int answer {0};
	front_binder temp_binder; //Instance of temp dtruct with binder info to add binder to stack

	fill_temp_binder(temp_binder); 

	try
	{
		pile.push_binder(temp_binder);
	}
	catch (int thrown)
	{
		if (!thrown)
			cout << "\nError adding binder to digital pile of binders." << endl;	
		else
			cout << "\nBinder added to the pile." << endl;
	}

	return;
}



void front::option_two(void)
{
	try
	{
		pile.display_binders();
	}
	catch (int binders)
	{
		if (!binders)
			cout << "\nThere are no binders to display." << endl;
	}


	return;
}



void front::option_three(void)
{
	try
	{
		pile.pop();
	}
	catch (int removed)
	{
		if (!removed)
			cout << "\nThere are no binders to remove." << endl;
		else
			cout << "\nA binder has been removed." << endl;
	}

	return;
}



void front::option_four(void)
{
	front_binder binder_info;
	queue* q_ptr;

	try
	{
		pile.peek(binder_info, q_ptr);
	}
	catch (int binders)
	{
		if (!binders)
			cout << "\nThere are no binders in the pile." << endl;
		else
		{
			cout << "\nBinder Subject: " << binder_info.subject << endl;
			cout << "Status: " << binder_info.status << endl;
			cout << "Description: " << binder_info.description << endl;
			cout << "Difficulty: " << binder_info.difficulty << endl;
		}
	}

	return;
}



//Allows user to edit to-do list however they like, then it's added to binder on top of pile
void front::option_five(void)
{
	int answer {0};
	front_todo todo_info; //Instance of temp struct with todo info to add to queue
	queue* q_object = new queue; //Instance of queue to add a todo list to current binder

	do
	{
		cout << "\nWould you like to..." << endl;
		cout << "1) Add an item to the to-do list" << endl;
		cout << "2) Display the to-do list" << endl;
		cout << "3) Remove an item from the to-do list (first in, first out)" << endl;
		cout << "4) Peek and see what the next item in the to-do list is (first in, first out)" << endl;
		cout << "5) Stop editing to-do list, add it to current binder, and go back to main menu" << endl;

		answer = get_integer();

		if (answer == 1)
		{
			fill_temp_todo(todo_info);
			try
			{
				q_object->enqueue(todo_info);
			}
			catch (int thrown)
			{
				if (thrown != 1)
					cout << "\nError adding to-do item to list." << endl;
			}
		}
		else if (answer == 2)
		{
			try
			{
				q_object->display_queue();
			}
			catch (int display)
			{
				if (!display)
				{
					cout << "\nNo to-do items to display in the list." << endl;
				}
			}
		}
		else if (answer == 3)
		{
			try
			{
				q_object->dequeue();
			}
			catch (int removed)
			{
				if (!removed)
					cout << "\nThere were no items in the list to remove." << endl;
				else
					cout << "\nItem has been removed from the list." << endl;
			}
		}
		else if (answer == 4)
		{
			try
			{
				q_object->peek(todo_info);
			}
			catch (int to_peek)
			{
				if (!to_peek)
				{
					cout << "\nThere are no to-do items in the list." << endl;
				}
				else
				{
					cout << "\nTo-do item name: " << todo_info.name << endl;
					cout << "Description: " << todo_info.description << endl;
					cout << "Link: " << todo_info.link << endl;
					cout << "Fun level: " << todo_info.fun << endl;
				}
			}
		}

	} while (answer != 5);

	try
	{
		pile.push_todo(q_object); //Adds todo list to stack, puts it in most recent binder
	}
	catch (int already)
	{
		if (!already) 
			cout << "\nThere are no binders in the pile for this to-do list to be added to." << endl;
		else if (already == 1)
			cout << "\nThis binder already has a to-do list." << endl;
		else
			cout << "\nThis to-do list has been added to the binder on the top of the pile." << endl;
	}
							  
	q_object = nullptr; //Sets pointer from this function to null

	return;
}	




void front::option_six(void)
{
	front_binder binder_info;
	queue* q_object;

	try
	{
		pile.peek(binder_info, q_object);
	}
	catch (int binders)
	{
		if (!binders)
			cout << "\nThere are no binders in the pile and thus no to-do list." << endl;
		else
		{
			cout << "\nBinder Subject: " << binder_info.subject << endl;
			cout << "Status: " << binder_info.status << endl;
			cout << "Description: " << binder_info.description << endl;
			cout << "Difficulty: " << binder_info.difficulty << endl;

			if (q_object) //If this binder has a queue
			{
				try
				{
					q_object->display_queue();
				}
				catch (int items)
				{
					if (!items)
						cout << "\nThere is no to-do list in this binder." << endl;
				}
			}
			else
				cout << "\nThere is no queue in this binder." << endl;
		}
	}	

	return;
}
	


void front::fill_temp_todo(front_todo& temp_todo)
{
	cout << endl;
	get_char_array("the to-do item", temp_todo.name);
	get_char_array("the description", temp_todo.description);
	get_char_array("a link or website for the item", temp_todo.link);
	get_char_array("how fun this item will be to do", temp_todo.fun);

	return;
}




void front::fill_temp_binder(front_binder& temp_binder)
{
	cout << endl;
	get_char_array("the binder subject", temp_binder.subject);
	get_char_array("how much has been completed so far", temp_binder.status);
	get_char_array("a description of the type of information in this collection", temp_binder.description);
	get_char_array("how challenging this binder is", temp_binder.difficulty);

	return;
}



// Gets struct member detail from user, first argument is prompt for detail, second arg is where user input will be stored (temp struct member)
void front::get_char_array(char member_name[], char actual_temp_member[])
{
    cout << "Type in " << member_name << ": ";                       // Prompts user for detail
    cin.get(actual_temp_member, MAX_CHARS, '\n');                    // Stores user input in temporary array
    cin.ignore(100, '\n');                                           // Clears input stream
    cout << "You entered \"" << actual_temp_member << "\"." << endl; // Echos to user what they entered

    return;
}



int front::get_integer(void)
{
    int num{0};

    cout << "Enter integer here: ";
    cin >> num;
    while (!cin || cin.peek() != '\n') // If user doesn't enter an integer...
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid entry, enter and integer: ";
        cin >> num; // Prompts for and gets input again
    }
    cin.ignore(100, '\n');

    return num;
}
