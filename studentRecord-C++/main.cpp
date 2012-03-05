//Aaron Decker
//012, Dr. Purdy, Purushotham Kolla
//Lab 8b
//03/04/12

/* What is this? -
 * 	-This program will pull in a list of students and their stats, then
 * gives menu options on adding more students, displaying them, or deleting
 * entries 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

// these must be defined before the includes that require them
#define LEN 100
#define COLW 16
#define FILENAME "StudentRecords.txt"

// my own defined includes
#include "StudentRec.h"
#include "StudentList.h"

using namespace std;
	
int main(){
	int choice;
	
	// make an instance of the BD tool
	StudentList epicListThing;
	epicListThing.LoadDatabase(FILENAME);
	
	//start menu loop:
	while(1)
		{
		cout << "Please choose:\n";
		cout << 
				"(1) Add a student record\n" <<
				"(2) Delete a student record\n" <<
				"(3) Find a student's information\n" <<
				"(4) Display all information in the database\n" <<
				"(5) Exit Program\n";
				
		//cout << "$.>";
		cin >> choice;
		
		// call StudentList member functions upon choice.
		if(choice == 1) epicListThing.addARecord2();
		else if(choice == 2) epicListThing.deleteARecord2();
		else if(choice == 3) epicListThing.searchList2();
		else if(choice == 4) epicListThing.DisplayAllRecords();
		else if(choice == 5) {
			epicListThing.exitAndSave(FILENAME);
			break;
			}
		else break;
		}
	
	return 0;
	}
