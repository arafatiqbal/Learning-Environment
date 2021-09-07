//Arafat Iqbal
//April 17, 2020
//Karla Fant
//Program 1

//For this program the main objective is to create a all in one system
//That stores all data from different learning management systems
//And tries to organize it into one single one. 
//There will be 5 classes that focus on storing different items like emails, calendar, grades etc.
//The data structure used for this program will be a linear linked list of arrays.
//This is a good data structure which can keep everythign fairly organized. 
//I implimented insert, display, search, and remove for all 3 of my classes.
//Remove function sometimes has hickups but works fairly well.

#include "environment.h"

using namespace std;
const int MAX = 100;

int main()
{
	clear(); //Random function to make program look nicer, just clears the screen using endl;
	environment my_environment; //environment object
	email my_email; //email object
	calendar my_calendar; //calendar object
	assignments my_assignments; //assignments object

	//Assignment class insert temps 
	char theAssignment[MAX];
	float theScore;
	
	//Calendar class insert temps
	char theMonth[MAX];
	int theDay;

	//Email class insert temps
	char theSubject[MAX];
	char theMail[MAX];
	
	//To compare 
	char  * to_compare;
	char temp[MAX];	
	//Option for menue
	int option = 0;
		
	cout << "Welcome to the ULTIMATE Learning Environment!" << endl;	
	cout << "Below are some options regarding your classes!" << endl;

	do
	{
		clear();
		cout << "Choose from the following menue: " << endl << endl;
		cout << "\t1. Add a New Assignment Description and Date Due" << endl;
		cout << "\t2. Send an Email about Assignment" << endl;
		cout << "\t3. Display All" << endl;
		cout << "\t4. Clear Screen" << endl;
		cout << "\t5. Search" << endl;
		cout << "\t6. Delete" << endl;
		cout << "\t7. Exit" << endl;
			
		cout << "\t\tSelect: ";
		cin >> option;		
		cin.ignore(100,'\n');

		clear();

		if(option == 1)
		{
			//Get assignment info into variables
			cout << "Whats the assignment description: ";
			cin.get(theAssignment,100,'\n');
			cin.ignore(100,'\n');

			clear();

			cout << "Whats the grade of the assignment (1-100)? ";
			cin >> theScore;
			cin.ignore(100,'\n');
		
			//Pass those variables to dynamically allocate	
			my_assignments.read(theAssignment,theScore);
			//Pass the object inot insert function in evnronment class 	
			my_environment.insert_assignment(my_assignments);

			clear();
			
			//Get calendar info into variables
			cout << "Whats the due date of the assignments? " << endl;
			cout << "Month(Jan - Dec): ";
			cin.get(theMonth,100,'\n');
			cin.ignore(100,'\n');

			cout << "Whats the Day (1-31): ";
			cin >> theDay;
			cin.ignore(100,'\n');

			//Pass those variables to dynamically allocate	
			my_calendar.read(theMonth,theDay);
			//Pass the object inot insert function in evnronment class 
			my_environment.insert_calendar(my_calendar);			

		}
		//Send an email 
		if(option == 2)
		{ 

			cout << "What's the email subject: ";
			cin.get(theSubject,100,'\n');
			cin.ignore(100,'\n');

			cout << "What's the email body: ";
			cin.get(theMail,100,'\n');
			cin.ignore(100,'\n');

			//Pass those variables to dynamically allocate		
			my_email.read(theSubject,theMail); 

			//Pass the object inot insert function in evnronment class 	
			my_environment.insert_mail(my_email);


		}
		//Calls the display all function
		if(option == 3)
		{
			//Function to display form environment
			my_environment.display();
		}

		//Function to clear the screen for easier read
		if(option == 4)
		{
			for(int i=0; i<20; ++i)
			{
			clear();
			}
		}

		if(option == 5)
		{
			//Reset the to_compare back to NULL;
			to_compare = NULL;

			cout << "What do you need to find? (Assignment, Date (month), Email(subject): ";
			cin.get(temp,100,'\n');
			cin.ignore(100,'\n');
			
			//Dynamically allocate
			to_compare = new char[strlen(temp)+1];
			strcpy(to_compare,temp);
		
			my_environment.retrieve(to_compare);	

		}
		if(option == 6)
		{
			//Reset to NULL
			to_compare = NULL;
				
			cout << "What do you need to delete? (Assignment, Date (month), Email(subject): ";
			cin.get(temp,100,'\n');
			cin.ignore(100,'\n');
			
			//Dynamically allocate
			to_compare = new char[strlen(temp)+1];
			strcpy(to_compare,temp);
		
			my_environment.remove(to_compare);
		}

	}while(option!=7);

	delete [] to_compare;

	return 0;
}
