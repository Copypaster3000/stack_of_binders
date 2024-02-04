//binder.h
//Drake Wheeler
//CS163
//Program 3
//4/23/2023
//This file holds the header for the binder class. The binder class represents one binder. It holds all the info of 
//a binder and a pointer to the circle linked list of todo items for that binder. 

#include <cstring>
#include <cctype>
#include <iostream>
#include "queue.h"

class binder
{
		public:
			binder(void); //Sets pointers to nullptr;
			binder(front_binder& temp_binder); //Sets members to info passed in by struct
			~binder(void);
			void set_binder(front_binder& temp_binder); //Pass in struct with binder info to set binder members dynamically	
			void display(void); //Displays data members of binder to user
			void set_arg(front_binder& temp_binder); //Sets members of struct passed in to those of binder
			void set_todo_list(queue* ptr); //Set's binder's q_object pointer to queue passed in
			int empty_q(); //returns 1 if q_object is nullptr, return 0 if it's not
			void get_q(queue*& q_ptr); //Sets pointer passed in to q_object
			
		private:
			void set_dynamic_member(char temp_struct_member[], char*& actual_member); //Pass in variable to be used to set second arg to dynamically allocated array
			char* subject; //Binder info 
			char* status;
			char* description;
			char* difficulty;

			queue* q_object;
};



	



