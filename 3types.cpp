//Arafat Iqbal
//April 17, 2020
//Karla Fant
//Program 1

//File for functions from the module .h class
//Functions included are for the calendar, assignment, email classes
//April 17, 2020
#include "environment.h"

using namespace std;

//Node constructor
node::node()
{
	next = NULL;
}
//Node destructor
node::~node()
{
	next = NULL;
}
//Function that goes next since next is private
node *& node::go_next()
{
	return next;	
}
//Calendar constructors and destructor below
calendar::calendar(char * initial_month, int initial_day):day(initial_day)
{
	month = new char [strlen(initial_month)+1];
	strcpy(month,initial_month);
}
calendar::calendar():month(nullptr), day(0)
{
	

}
calendar::calendar(const calendar & to_copy)
{
	this->month = new char [strlen(to_copy.month)+1];
	strcpy(this->month, to_copy.month);
	
	this->day = to_copy.day;

}
calendar::~calendar()
{
	delete [] month;
	month = NULL;
	day = 0;
}

//Assignment Constructors and destructor below
assignments::assignments(char * initial_assignment, float initial_score):score(initial_score)
{
	an_assignment = new char[strlen(initial_assignment)+1];
	strcpy(an_assignment,initial_assignment);

}
assignments::assignments():an_assignment(nullptr),score(0)
{


}
assignments::assignments(const assignments & to_copy)
{
	this->an_assignment = new char [strlen(to_copy.an_assignment)+1];
	strcpy(this->an_assignment, to_copy.an_assignment);

	this->score = to_copy.score;	
	
}

assignments::~assignments()
{
	an_assignment = NULL;
	score = 0;
}

//Email constructors and destructor below
email::email(char * initial_subject, char * initial_mail)
{
	subject = new char[strlen(initial_subject)+1];
	strcpy(subject,initial_subject);

	mail = new char[strlen(initial_mail)+1];
	strcpy(mail,initial_mail);

}
email::email():subject(nullptr), mail(nullptr)
{


}
email::email(const email & to_copy)
{
	this->subject = new char[strlen(to_copy.subject)+1];
	strcpy(this->subject,to_copy.subject);
	
	this->mail = new char[strlen(to_copy.mail)+1];
	strcpy(this->mail,to_copy.mail);

}
email::~email()
{
	subject = NULL;
	mail = NULL;

}

//Virtual Node Class Display that calls all the other ones
void node::display()
{

}
int node::retrieve(char * to_compare)
{
	return 1;
}
//All calendar functions below
void calendar::read(char * theMonth,int theDay)
{
	this->month = new char[strlen(theMonth)+1];
	strcpy(this->month,theMonth);
	
	this->day = theDay; 

	return;
}
void calendar::display() 
{
	cout << "The date for this assignment is: ";
	cout << month << " / " << day << endl;

	return;
}
int calendar::retrieve(char * to_compare)
{
	if(strcmp(month,to_compare)==0)
	{
		return 1;
	}
	else return 0;
}
//ALL assignments functions below
void assignments::read(char * theAssignment,float theScore)
{
	
	this->an_assignment = new char[strlen(theAssignment)+1];
	strcpy(this->an_assignment,theAssignment);
	
	this->score = theScore; 
	
//	assignments(theAssignment,theScore);

	return;
}
void assignments::display() 
{
	cout << "Assignment Description: ";
	cout << an_assignment << endl;

	cout << "Grade: ";
	cout << score << endl;

	return;
}

int assignments::retrieve(char * to_compare)
{
	if(strcmp(an_assignment,to_compare)==0)
	{
		return 1;
	}
	else return 0;
}
void email::read(char * theSubject,char * theMail)
{
	this->subject = new char[strlen(theSubject)+1];
	strcpy(this->subject,theSubject);

	this->mail = new char[strlen(theMail)+1];
	strcpy(this->mail,theMail);
	
	return;
}
//All Email functions below
void email::display()
{
	cout << "Email Sent: ";
	cout << "Subject: " << subject << endl;
	cout << "Body: " << mail << endl;
	return;
}
int email::retrieve(char * to_compare)
{
	if(strcmp(subject,to_compare)==0)
	{
		return 1;
	}
	else return 0;
}
