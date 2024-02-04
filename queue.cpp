//queue.cpp
//Drake Wheeler
//CS163
//Program 3
//4/23/2023
//This file holds the definitions for the functions of the class q_node and the class queue.
#include <iostream>
#include <cstring>
#include <cctype>
#include "queue.h"
using namespace std;

//Constructos sets q_nodes pointers to nullptr
q_node::q_node(void)
{
	name = nullptr;
	description = nullptr;
	link = nullptr;
	fun = nullptr;
	next = nullptr;

	return;
}



//Releases memory of the data members, expcet next ptr
q_node::~q_node(void)
{
	delete[] name;
	delete[] description;
	delete[] link;
	delete[] fun;

	return;
}


//Copies node's info to struct passed in
void q_node::copy_node_to(front_todo& todo_info)
{
	strcpy(todo_info.name, name);
	strcpy(todo_info.description, description);
	strcpy(todo_info.link, fun);
	strcpy(todo_info.fun, fun);

	return;
}


//Sets node's memeber's dynamically with info passed in by struct
void q_node::set(front_todo& temp_todo)
{
	set_dynamic_member(temp_todo.name, name);
	set_dynamic_member(temp_todo.description, description);
	set_dynamic_member(temp_todo.link, link);
	set_dynamic_member(temp_todo.fun, fun);

	return;
}



//Displays node's data members to user
void q_node::display(void)
{
	cout << "\nTo-do item name: " << name << endl;
	cout << "Description: " << description << endl;
	cout << "Link: " << link << endl;
	cout << "Fun level: " << fun << endl;

	return;
}

	

//Private ADT member function only used inside other ADT functions
//Takes in temporary struct member and node member pointer to set pointer to dynamically allocated array 
void q_node::set_dynamic_member(char temp_struct_member[], char*& actual_member)
{
    actual_member = new char[strlen(temp_struct_member) + 1]; //Sets struct member pointer to perfect size array
    strcpy(actual_member, temp_struct_member); //Copies user input to dynamically allocated array

    return;
}



//Constructor set's queues rear pointer, which can pointer to CLL of to-dos, to nullptr
queue::queue(void)
{
	rear = nullptr;

	return;
}



//Wrapper function, deletes q_node CLL
queue::~queue(void)
{
    if (!rear) return; //Return if no nodes in CLL

    q_node* current = rear->next; //Sets current to front
    q_node* temp;

    while (current != rear) //While there's more than one node left
    {
        temp = current; //Hold current
        current = current->next; //Set current to next
        delete temp; //Delete old current
    }

    delete rear; //Delets rear once it's the only node left

	return;
}



//Pass in struct with to-do item details, it is add to the back of the to-do list
void queue::enqueue(front_todo& temp_todo)
{
	if (!rear) //If there are no nodes in CLL make's new node rear and sets next to it self
	{
		q_node* new_node = new q_node;
		rear = new_node;
		rear->next = rear;
	}
	else //If there is a node in CLL, adds new node to the rear of CLL
	{
		q_node* hold = rear->next;
		rear->next = new q_node;
		rear = rear->next;
		rear->next = hold;
	}

	rear->set(temp_todo); //Sets node's data member's to todo details dynamically

	throw 1;

	return;
}



//Removes next node in CLL
void queue::dequeue(void)
{
	if (!rear) throw 0; //No node to remove

    if (rear == rear->next) //If there's only one node...
	{
		delete rear; //Deletes it 
		rear = nullptr; //and sets rear ptr to nullptr
	}
	else
	{
		q_node* hold = rear->next->next;
		delete rear->next;
		rear->next = hold;
	}

	throw 1; //Throws 1 for success

	return;
}



//Displays whole queue to user
void queue::display_queue(void)
{
	if (!rear) throw 0; //Nothing to display
	
	return display_queue(rear->next, rear);
}



//Pass in rear->next for current and rear for rear, goes thru entrie CLL and dispalys each nodes details to user
void queue::display_queue(q_node* current, q_node* rear)
{
	if (current == rear) //CLL has been gone all the way thru
	{
		current->display(); //Display details of current node

		throw 1; //Success
	}

	current->display(); //Displays current node to user

	return display_queue(current->next, rear); //Calls it self passing in next node in line for first arg, and rear again for second
}



//Allows client to peek the next todo item in the list by updating struct passed in
void queue::peek(front_todo& temp_todo)
{
	if (!rear) throw 0; //Nothing to peek

	rear->next->copy_node_to(temp_todo); //Copies nodes details to struct passed in

	throw 1; //Success
			 
	return;
}



