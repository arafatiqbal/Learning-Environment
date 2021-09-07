//Arafat Iqbal
//April 17, 2020
//Karla Fant
//Program 1

//The classes implimented in this file are going to be 
//Assignemnts
//Modules
//Calendar
//These three are related in some way so I decided to put them in this file together

#include<iostream>
#include<cctype>
#include<cstring>

#ifndef NODE
#define NODE

class node
{
	public:
		node();
		virtual	~node(); //Having virttual destructor is necesary for virtual functions
		virtual void display();	//Virtual display function that calls all other ones	
		virtual int retrieve(char * to_compare);

		node *& go_next();	

	protected:
		
		node * next;

};

//Holds information about Calendar information
class calendar:public node
{
	public:
		calendar();
		calendar(char * month, int day);
		calendar(const calendar & to_copy);
		~calendar();
	
		//Functions for Calendar Class
		void read(char * month, int day);
		void display();
		int retrieve(char * to_compare);
	protected:

		//Data Members for Calendar Class
		char * month;
		int day;

};
//Holds information about assignments and grades
class assignments:public calendar
{
	public:
		assignments(); //assignments constructor
		assignments(char * an_assignment, float mark); //Copy constructor
		assignments(const assignments & to_copy);
		~assignments();
		
		//Funtions for Assignments Class
		void read(char * an_assignmnet,float score);
		void find_assignment(char * to_compare);
		void display();
		int retrieve(char * to_compare);

	protected:

		//Data Members for Assignment Class
		char * an_assignment;
		float score;
};
//Holds information about the calendar and assignments + more
class email:public node
{
	public:

		email(); //email constructor	
		email(char * subject, char * mail);
		email(const email & to_copy);
		~email();

		//Functions for Email Class
		void read(char * subject, char * mail);
		void display();
		int retrieve(char * to_compare);
			
	protected:
		char * subject;
		char * mail;

};
#endif 

