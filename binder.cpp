//binder.cpp
//Drake Wheeler
//CS163
//Program 2
//4/23/2023
//This file holds the class definitions to the binder class. The binder class also acts as a node. 
//This classes functions will be used to interact with that node.

#include "binder.h"
using namespace std;



//Sets pointers to nullptr
binder::binder(void)
{
	subject = nullptr;
	status = nullptr;
	description = nullptr;
	difficulty = nullptr;
	q_object = nullptr;

	return;
}



//Pass in struct with binder info to initialize binder members with that info
binder::binder(front_binder& temp_binder)
{
	set_binder(temp_binder);

	return;
}



//Releases all the memory of the binder
binder::~binder(void)
{
	delete [] subject;
	delete [] status;
	delete [] description;
	delete [] difficulty;

	delete q_object;

	return;
}



//sets pointer passed in to q_object
void binder::get_q(queue*& q_ptr)
{
	q_ptr = q_object;

	return;
}



//Used to check if there's a to-do list in the binder already or not
int binder::empty_q(void)
{
	if (!q_object) return 1; //Throws 1 if it there's no to-do list

	return 0; //If there is a to-do list
}



//Pass in pointer to queue to set it in binder
void binder::set_todo_list(queue* q_ptr)
{
	q_object = q_ptr;

	return;
}



//Organizes set_dynamic_member to set all binder members dynamically to info passed in by struct
void binder::set_binder(front_binder& temp_binder)
{
	set_dynamic_member(temp_binder.subject, subject);
	set_dynamic_member(temp_binder.status, status);
	set_dynamic_member(temp_binder.description, description);
	set_dynamic_member(temp_binder.difficulty, difficulty);

	return;
}



//Display binder details to user
void binder::display(void)
{
	cout << "\nBinder Subject: " << subject << endl;
	cout << "Status: " << status << endl;
	cout << "Description: " << description << endl;
	cout << "Difficulty: " << difficulty << endl;

	return;
}



//Sets struct passed in members to binder's members
void binder::set_arg(front_binder& temp_binder)
{	
	strcpy(temp_binder.subject, subject);
	strcpy(temp_binder.status, subject);
	strcpy(temp_binder.description, description);
	strcpy(temp_binder.difficulty, difficulty);

	return;
}



//Private ADT member function only used inside other ADT functions
//Takes in temporary struct member and node member pointer to set pointer to dynamically allocated array 
void binder::set_dynamic_member(char temp_struct_member[], char*& actual_member)
{
    actual_member = new char[strlen(temp_struct_member) + 1]; //Sets struct member pointer to perfect size array
    strcpy(actual_member, temp_struct_member); //Copies user input to dynamically allocated array

    return;
}
