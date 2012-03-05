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


using namespace std;

class StudentRec
	{
	private:
		string name_full;
		string name_first; // in the format of "Last name, First Name"
		string name_last;
		string M_number;
		double gpa; 
		
	public:
		void setNameFirst(string name){
			name_first = name;
			}
		void setNameLast(string name){
			name_last = name;
			}
		void setNameFull(string name){
			name_full = name;
			}
		void setID(string i){
			M_number = i;
			}
		void setGPA(double i){
			gpa = i;
			}
		string getFirstName() const {
			return name_first;
			}
		string getLastName() const {
			return name_last;
			}
		void SetRecord(string StuName, string StuID, double StuGPA){
			name_full = StuName;
			M_number = StuID;
			gpa = StuGPA;
			}
		string getID() const {
			return M_number;
			}
		double getGPA() const {
			return gpa;
			}
		void getRecord(string &StuName, string &StuID, double &StuGPA) const {
			StuName = name_full;
			StuID = M_number;
			StuGPA = gpa;
			}
		// takes int i as index number of record being printed.
		void displayRecord() const {
			cout << 
				setw(COLW) << name_full <<
				setw(COLW) << M_number <<
				setw(COLW) << gpa <<
				endl;
			}
		void displayRecordWithIndex(int i) const {
			cout << 
				setw(COLW) << (i + 1) <<
				setw(COLW) << name_full <<
				setw(COLW) << M_number <<
				setw(COLW) << gpa <<
				endl;
			}
		// hmm maybe this should be something that 
		// pulls out the first name from the full name using a delimiter.
	};

class StudentList
	{
	private:
		// Define the student record VECTOR here;
		// Also define other data members here
		vector<StudentRec> record_list;
		
	public:
		void LoadDatabase(string fn){
			ifstream inpfile;
			inpfile.open(fn.c_str());
			
			string  fname, lname, tempInp, previousRecName;
			double tempInpDbl;
			
			StudentRec tempRec;
			
			while(inpfile){
				// get first name
				inpfile >> fname;
				tempRec.setNameFirst(fname);
				// get last name
				inpfile >> lname;
				tempRec.setNameLast(lname);
				// get M number
				inpfile >> tempInp;
				tempRec.setID(tempInp);
				// get gpa
				inpfile >> tempInpDbl;
				tempRec.setGPA(tempInpDbl);
				// concat first and last name, store in full name
				tempInp = lname + ", " + fname;
				tempRec.setNameFull(tempInp);
				// add to vector
				record_list.push_back(tempRec);
				
				// for some reason it duplicates on EOF????
				if(previousRecName.compare(fname) == 0){
					record_list.pop_back();
					break;
					}
				previousRecName = fname;
				}
			inpfile.close();
			}
		//void SaveDatabase(string Filename) const;  
		void DisplayAllRecords(){
			int size, i;
			size = record_list.size();
			
			cout << "\tAll Student Records:\n";
					cout << 
						setw(COLW) << "Position" <<
						setw(COLW) << "Name" <<
						setw(COLW) << "M #" <<
						setw(COLW) << "GPA" <<
						endl;
			
			for(i =0; i < size; i++){
				StudentRec recArr;
				recArr = record_list[i];
				recArr.displayRecordWithIndex(i);
				}
			}
		
		// giving a student ID, search the list. Return true if found and false if not
		// found. Also return the matching record if found
		void searchListByIndex(){
			int size = record_list.size(), indexpos;
			cout << "There are " << size << " records in the DB. Enter the number to view...\n";
			cin >> indexpos;
			
			if(indexpos > size || indexpos < 0){
				cout << "Sorry, that was out of range\n";
				return;
				}
			
			StudentRec temprec;
			temprec = record_list[(indexpos - 1)];
			temprec.displayRecordWithIndex((indexpos - 1));
			} 
		
		void searchList(){
			string inpID;
			cout << "Enter the student ID of the student you want to search for:\n";
			cin >> inpID;
			int size = record_list.size();
			
			for(int i = 0; i < size; i++){
				StudentRec tempRec;
				tempRec = record_list[i];
				string tempID = tempRec.getID();
				if(tempID.compare(inpID) == 0){
					cout << "Found, record " << (i + 1) << " matches id\n";
					tempRec.displayRecordWithIndex(i);
					}
				}
			}
		
		void searchList2(){
			int size = record_list.size();
			string fnameInp, lnameInp, fnameTmp, lnameTmp;
			cout << "Please input student name:\n";
			cin >> fnameInp;
			cin >> lnameInp;
			
			bool flag = false;
			
			for(int i = 0; i < size; i++){
				StudentRec stu;
				stu = record_list[i];
				fnameTmp = stu.getFirstName();
				lnameTmp = stu.getLastName();
				
				if(fnameTmp.compare(fnameInp) == 0 && lnameTmp.compare(lnameInp) == 0){
					//cout << "fname:"<<fnameTmp<<"lname:"<<lnameTmp<<"fnametmp:"<<fnameInp<<"lnametmp:"<<lnameInp<<endl;
					// this means that the first name and last name matched the record.
					flag = true;
					stu.displayRecord();
					break;
					}
				}
			// if there is a match, this block fires:
			if(flag != true)
				cout << "Sorry this record could not be found.\n";
				
			}
		
		void addARecord(){
			StudentRec temprec;
			string fname, lname, tstr;
			double gpa;
			
			cout << "What is the student's first name?\n";
			cin >> fname;
			temprec.setNameFirst(fname);
			
			cout << "What is the student's last name?\n";
			cin >> lname;
			temprec.setNameLast(lname);
			
			cout << "What is the student's M# \n";
			cin >> tstr;
			temprec.setID(tstr);
			
			cout << "What is the student's GPA\n";
			cin >> gpa;
			temprec.setGPA(gpa);
			
			// aditionally, record the fullname:
			tstr = lname + ", " + fname;
			temprec.setNameFull(tstr);
			
			record_list.push_back(temprec);	
			}
			
		void addARecord2(){
			StudentRec temprec;
			string fullname, fname, lname, tstr;
			double gpa;
			
			// this will work if separated by spaces
			cout << "Please input student name:\n";
			cin >> fname;
			cin >> lname;
			
			cout << "Please input student ID:\n";
			cin >> tstr;
			temprec.setID(tstr);

			cout << "Please input student GPA:\n";
			cin >> gpa;
			temprec.setGPA(gpa);
			
			// aditionally, record the fullname:
			/*
			int pos, len;
			pos = fullname.find(" ",0);
			len = fullname.length() - 1;
			fname = fullname.substr(0, len - pos);
			lname = fullname.substr(len - pos, len);
			
			cout << fname << endl;
			cout << lname << endl;
			cout << fullname << endl;
			*/
			tstr = lname + ", " + fname;
			temprec.setNameFull(tstr);
			temprec.setNameFirst(fname);
			temprec.setNameLast(lname);
			
			record_list.push_back(temprec);	
			}
			
			
		void deleteARecord(){
			int size = record_list.size(), indexpos;
			cout << "There are " << size << " records in the DB. Enter the number to DELETE!...\n";
			
			cin >> indexpos;
			
			if(indexpos > size || indexpos < 0){
				cout << "Sorry, that was out of range\n";
				return;
				}
			// make a new temporary student record vector
			vector<StudentRec> tempVec;
			for(int i = 0; i < size;i++){
				if(i != (indexpos - 1)){
					tempVec.push_back(record_list[i]);
					}
				}
			// overwrite the old one with the shorter one
			record_list.swap(tempVec);
			}
		
		
		void deleteARecord2(){
			int size = record_list.size();
			string fnameInp, lnameInp, fnameTmp, lnameTmp;
			
			cout << "Please input student name:\n";
			cin >> fnameInp;
			cin >> lnameInp;
			int i, bingo;
			bool flag = false;
			
			for(int i = 0; i < size; i++){
				StudentRec stu;
				stu = record_list[i];
				fnameTmp = stu.getFirstName();
				lnameTmp = stu.getLastName();
				
				
				if(fnameTmp.compare(fnameInp) == 0 && lnameTmp.compare(lnameInp) == 0){
					//cout << "fname:"<<fnameTmp<<"lname:"<<lnameTmp<<"fnametmp:"<<fnameInp<<"lnametmp:"<<lnameInp<<endl;
					// this means that the first name and last name matched the record.
					flag = true;
					cout << "Success, " << fnameTmp << " " << lnameTmp << " was removed from the database.\n";
					bingo = i;
					// only want to delete one record
					break;
					}
				}
			
			vector<StudentRec> tmpVec;
			// if there is a match, this block fires:
			if(flag == true){
				//cout << "swapping " << bingo << " bingo\n";
				// make a new temporary student record vector
				for(i = 0; i < size; i++){
					// skip this one
					if(i != bingo){
						// otherwise copy over.
						tmpVec.push_back(record_list[i]);
						}
					}
				// overwrite the old one with the shorter one
				record_list.swap(tmpVec);	
				}
			else{
				cout << "Sorry this record could not be found.\n";
				}
			}
		
		void exitAndSave(string fn){
			ofstream outfile;
			outfile.open(fn.c_str());
			
			// getlength of records:
			int len = record_list.size(), i = 0;
			for( ; i < len; i++){
				StudentRec stu;
				stu = record_list[i];
				outfile << stu.getFirstName();
				outfile << " ";
				outfile << stu.getLastName();
				outfile << " ";
				outfile << stu.getID();
				outfile << " ";
				outfile << stu.getGPA();
				outfile << "\n";
				}
			outfile.close();
			}
		
	};
	
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
