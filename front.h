//front.h
//Drake Wheeler
//CS163
//Program 2
//4/23/2023
//This file holds the the header file for the front class. The front class will call all the
//other functions to test them. This class is what interacts directly with the user.

#include <iostream>
#include <cstring>
#include <cctype>

#include "stack.h"


class front
{
		public:
			front(void);
			~front(void);
			void welcome(void);
			int menu(void);
			void option_one(void);
			void option_two(void);
			void option_three(void);
			void option_four(void);
			void option_five(void);
			void option_six(void);

		private:
			void fill_temp_todo(front_todo& temp_todo);
			void fill_temp_binder(front_binder& temp_binder);
			void get_char_array(char member_name[], char actual_temp_member[]);
			int get_integer(void);

			stack_class pile; //Instance of stack class so that the functions can be called by this class to test them
};


