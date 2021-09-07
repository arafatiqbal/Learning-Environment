//Arafat Iqbal
//Program 1
//April 17, 2020
//Karla Fant

//Functions for the environment, node

#include "environment.h"
#include "3types.h"

using namespace std;

//Functions for menue to clear
void clear()
{
	for(int i = 0; i<3; ++i)
	{
		cout<<endl;
	}
	return;
}

//ENvironment constructors and destructor below
environment::environment():head(NULL)
{
	array_size = 4;
	head = new node * [array_size];

	for(int i = 0; i < array_size; ++i)
	{
		head[i] = NULL;
	}
	
}
environment::~environment()
{
	for(int i = 0; i< array_size; ++i)
	{
		remove_all_recursive(head[i]);
	}
	delete [] head;
}

void environment::remove_all_recursive(node *& head)
{
	if(!head) return;

	remove_all_recursive(head->go_next());

	delete head;
	head = NULL;
}

//Envrionemtn functions below
//Insert assignment into the data structure into the 0 index
int environment::insert_assignment(const assignments & to_add)
{
	int index = 0;
	
	if(!head[index])
	{
		node * object = new assignments(to_add);
		head[index] = object;		
	}
	else
	{
		node * temp = new assignments(to_add);
		node * current = head[index];	
		while(current->go_next())
		{
			current = current->go_next();
		}
		current->go_next() = temp;
		temp->go_next() = NULL;

		return 1;
	}

	return 1; 

}
//Insert calendar into the data structure into the 1st index
int environment::insert_calendar(const calendar & to_add)
{
	int index = 1;
	
	if(!head[index])
	{
		node * object = new calendar(to_add);
		head[index] = object;		
	}
	else
	{
		node * temp = new calendar(to_add);
		node * current = head[index];	
		while(current->go_next())
		{
			current = current->go_next();
		}
		current->go_next() = temp;
		temp->go_next() = NULL;

		return 1;
	}
	return 1; 
}
//Insert mail into the data structure into the 2nd index
int environment::insert_mail(const email & to_add)
{
	int index = 2;
	
	if(!head[index])
	{
		node * object = new email(to_add);
		head[index] = object;		
	}
	else
	{
		node * temp = new email(to_add);
		node * current = head[index];	
		while(current->go_next())
		{
			current = current->go_next();
		}
		current->go_next() = temp;
		temp->go_next() = NULL;

		return 1;
	}
	return 1; 
}
//Function that display everyting in the data structure
void environment::display()
{
	//Set size to less than 1 so it doesn't go and display memeory that
	//Doesnt exist
	int size = array_size - 1;
	
	//If there is nothing in the list
	if(!head)
	{
		cout << "NO DATA CAN BE DISPLAYED" << endl; return;
	}
	for(int i = 0; i<size; ++i)
	{ 
		//cout << "Index: " << i << endl; for testing purposes to see what index it was
		display(head[i]);
	}
	return;
}
void environment::display(node * head)
{
	if(!head) return;

	head->display();	
	cout << endl;
	display(head->go_next());

	return;
}
void environment::retrieve(char * to_compare)
{
	int size = array_size - 1;
	if(!head)
	{
		cout  << "NO DATA TO SEARCH" << endl;
	}	
	for(int i = 0; i<size; ++i)
	{
		retrieve(head[i],to_compare);
	}
	return;		
}
void environment::retrieve(node * head, char * to_compare)
{
	if(!head) return;
	if(head->retrieve(to_compare)==1)
	{
		head->display();
		retrieve(head->go_next(),to_compare);
	}

	return;
}
//Remove function wrapper
void environment::remove(char * to_compare)
{
	return remove(head,to_compare);

}
//Remove function
void environment::remove(node **& head, char * to_compare)
{
	int size = array_size - 1;
	node * prev = NULL;

	if(!head) return;
		
	for(int i =0; i < size; ++i)
	{
		if(!head[i]) continue;
	
		else if(!head[i]->go_next())
		{
			if((*head)->retrieve(to_compare)==1)
			{
				delete head[i];
				head[i] = NULL;
				cout << "Index: " << i << " Is Empty" << endl; //Testing purposes
				return;
			}
		}
		while(head[i])
		{

			if((*head)->retrieve(to_compare)==1)
 			{

				if(!prev)
				{
					head[i] = head[i]->go_next();
				}
				else
				{
					prev->go_next() = head[i]->go_next();	
				}	

				head[i]->go_next() = NULL;
				delete head[i];
			}
			prev = head[i];
			head[i] = head[i]->go_next();
		}
	}
	return;
}
	
