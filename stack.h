//stack.h
//Drake Wheeler
//CS163
//Program 3
//4/23/2023
//This file holds the header for the stack class. The class enables a user to push, pop, peek,
//and display elements in the data stack. It also holds the node of the data stack. Each node
//has an array of binders and a next pointer to the next node in the stack.

#include <iostream>
#include <cstring>
#include <cctype>
#include "binder.h"

const int MAX_B {3}; //Maximum number of binders held in each node of the stack

struct stack_node
{
	binder* binders; //Array of binders to be dynamically allocated. Elements of the stack

	stack_node* next; //Points to next node in stack
};


class stack_class
{
		public:
			stack_class(void); //Sets pointer to nullptr amd index to 0
			~stack_class(void); //Deletes all nodes in stack and releases all memory
			void push_binder(front_binder& temp_binder); //Adds binder to top of stack with info of struck passed in, sets queue pointer to queue object passed in, throws one if succesful
			void push_todo(queue* q_object); //Adds queue to stack by setting binder's q ptr to q passed in, throws 0 if no binder in pile to put queue in, 1 if binder already has queue, 2 for success
			void display_binders(void); //Displays the details of each binder in the stack to the user, throws a 0 if there are no binders in stack, 1 for success
			void pop(void); //Removes a binder from the top of the stack, throws 0 if no binders to pop, 1 for success
			void peek(front_binder& temp_binder, queue*& q_ptr); //Updates struct passed in with binder's info, sets pointer passed in to binder's queue, throws 0 if no binder to peek, throws 1 for success, sets q_ptr to nullptr if no queue in binder

		private:
			stack_node* stack_head; //Points to head node of stack
			int top_index;  //Index for stack elements, used for array of binders in each stack
			void set_dynamic_member(char temp_struct_member[], char*& actual_member); //Uses first arg passed in to set second arg passed in to dynamic char array
};

