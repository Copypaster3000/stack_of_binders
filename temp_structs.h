//temp_structs.h
//Drake Wheeler
//CS163
//Program 3
//4/23/2023
//This file holds temporary structs used by the front class to pass data to the ADTs

const int MAX_CHARS {333};

struct front_binder
{
	char subject[MAX_CHARS];
	char status[MAX_CHARS];
	char description[MAX_CHARS];
	char difficulty[MAX_CHARS];
};



struct front_todo
{
	char name[MAX_CHARS];
	char description[MAX_CHARS];
	char link[MAX_CHARS];
	char fun[MAX_CHARS];
};
