//queue.h
//Drake Wheeler
//CS163
//Program 2
//4/26/2023
//This file holds the q_node class header which acts as the nodes for the CLL of todo lists.
//It also holds the queue class header which edits and does stuff with the circular linked list. 

#include "temp_structs.h"

class q_node
{
	public:
		q_node(void); //Sets all pointer members to nullptr
		~q_node(void); //Releases all memory
		void set(front_todo& temp_todo); //Sets q_node data members dynamically with info passed in thru struct
		void display(void); //Displays to-do item details to user
		void copy_node_to(front_todo& todo_info); //Copies front node in the list to struct passed in

		q_node* next; //Points to next node in CLL

	private:
	    void set_dynamic_member(char temp_struct_member[], char*& actual_member); //Uses first arg passed in to set second arg to dynamic char array
		char* name; //To-do item info
		char* description;
		char* link;
		char* fun;
};




class queue
{
	public:
		queue(void); //Sets pointer member to nullptr
		~queue(void); //Releases all memory
		void enqueue(front_todo& temp_todo); //Adds a node to the to-do list CLL with info passed in by struct, throws 1 for success
		void dequeue(void); //Removes an item from the list (first in, first out), Throws 0 if nothing to remove, 1 for success
		void display_queue(void); //Wrapper funciton displays entire CLL, throws 0 if there's nothing to display, 1 for sucess
		void display_queue(q_node* current, q_node* rear); //^ Pass in rear->next, and rear  
		void peek(front_todo& temp_todo); //Let's clinet peek node in CLL by updating struct they pass in. Throws 0 if no nodes to peek, 1 for success

	private:
		q_node* rear; //Points to rear of CLL of to-do items

};
