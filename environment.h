//Arafat Iqbal
//April 17, 2020
//Karla Fant
//Program 1

//Base class file for the learning environment
//This stores information about head poitners and inserts
//This also has recursive fucntions tod isplay all, search, and remove

#include"3types.h"

#ifndef ENVIRONMENT
#define ENVIRONMENT

void clear(); // function to add endl to  make the menue nicer lookign. 

//Class for learning environment

class environment
{
	public:
		environment(); // COnstructor
		~environment();	 //Destructor
	
		//Functions to insert into a linked list
		int insert_calendar(const calendar & to_add);	
		int insert_mail(const email & to_add);
		int insert_assignment(const assignments & to_add);
			
		//Display function that displays all		
		void display();
		//Function to retrieve info
		void retrieve(char * to_compare);
		//Function to remove
		void remove(char * to_compare);

	protected:
		
		//Recursive function calls
 		void display(node * head);
		void remove_all_recursive(node *& head);	
		void retrieve(node * head, char * to_compare);
		void remove(node **& head, char * to_compare);

		node ** head; //Array of head pointers	

		//Data Members of Environment Class
		int array_size;

};

#endif
