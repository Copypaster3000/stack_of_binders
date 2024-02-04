//stack.cpp
//Drake Wheeler
//CS163
//Program 3
//4/23/2023
//This file holds the definitions for the stack class which interacts with the data stack

#include "stack.h"

//Constructor
stack_class::stack_class(void)
{
	stack_head = nullptr;
	top_index = 0;

	return;
}



//Desctructor, loops through each node of stack, releases all memory
stack_class::~stack_class(void)
{
	while (stack_head) //While there are still nodes
	{
		stack_node* hold = stack_head; //Holds node to be deleted
		stack_head = stack_head->next; //Sets head to next node
		delete[] hold->binders; //Deletes array of binders
		delete hold; //Deletes node
	}

	return;
}



//Adds a binder to top of digital pile of binders w/ binder info passed in by struct. Sets this elements queue poiner to queue object passed in
void stack_class::push_binder(front_binder& temp_binder)
{
	if (!stack_head || (top_index == MAX_B)) //If there are no stack nodes or array of binders in node is full
	{
		stack_node* new_node = new stack_node; 
		new_node->next = stack_head;
		stack_head = new_node;
		stack_head->binders = new binder[MAX_B]; //Dynamically creates array of binders in node (3 binders long)
		top_index = 0; //Sets array index to zero because no binders have been logged in the new array of binders
	}

	stack_head->binders[top_index].set_binder(temp_binder); //Sets new binders data members to the binder details passed in by struct
	++top_index; //Adds to index because there's a new binder on the pile
	
	throw 1; //Throws 1 for successful push	

	return;
}



//This adds a todo list to the binder, pass in the q_object pointer and it will be pointer to by the queue pointer in the binder on the top of the pile
void stack_class::push_todo(queue* q_object)
{
	if (!stack_head) throw 0; //There is no binder in the pile for the list to be added to
							  
	if (!stack_head->binders[top_index - 1].empty_q()) throw 1; //There's already a to-do list in this binder

	stack_head->binders[top_index - 1].set_todo_list(q_object); //Sets binders queue pointer to queue passed in

	throw 2; //success

	return;
}



//Displays all binder's to user in the stack
void stack_class::display_binders(void)
{
	if (!stack_head) throw 0; //If there are no binder's to display
							  
	int display_index = top_index; //Sets new index to current top index that can be edited and used to go thru array
	stack_node* current = stack_head; //Creates current pointer and sets it to first node in stack
	
	while (current != nullptr) //Loop through stack until end of stack
	{
		--display_index; //Subtracts 1 from index to go through array 
		current->binders[display_index].display(); //Displays current node's binder of the current index

		if (display_index <= 0) //If at the bottom of array of binder's resets index to top of array of binder's
		{
			display_index = MAX_B; //Reset index
			current = current->next; //Goes to next node in stack
		}
	}

	throw 1; //Success

	return;
}



//Removes one binder from the stack
void stack_class::pop(void)
{
	if (!stack_head) throw 0; //If there are no binder's to pop

	if (top_index == 1) //If it's the last binder in this node
	{
		stack_node* hold = stack_head;
		stack_head = stack_head->next;
		delete[] hold->binders; //Release memory for array of binders
		delete hold; //delete node
		top_index = MAX_B; //Set index to top for next node
	}
	else
		--top_index; //subracts index by ones so top binder is now the one below

	throw 1; //Succesful pop
			 
	return;
}



//Displays binder on the top of the stack to user
void stack_class::peek(front_binder& temp_binder, queue*& q_ptr)
{
	if (!stack_head) throw 0; //No binder's to display

	stack_head->binders[top_index - 1].set_arg(temp_binder); //Displays binder's details to user

	stack_head->binders[top_index - 1].get_q(q_ptr); //Sets pointer passed in to binder's queue

	throw 1; //Success

	return;
}







