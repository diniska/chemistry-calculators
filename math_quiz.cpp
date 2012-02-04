//Aaron Decker
//012, Dr. Purdy, Purushotham Kolla
//Lab 4b
//02/05/12

// MATH SKILL TESTING PROGRAM: 
	/*
	 * Input a file of your chosing in num1 \t num2 \t operator format.
	 * The program will then read this file and create arrays of these values
	 * with which to quiz the user and record answers. Finally the results 
	 * are displayed and the output is written to a file of your choosing
	 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>  // need for random

using namespace std;

// some conveniences
#define LOOP_LEN 20
#define ARRAY_LEN 5
#define NUM_VALUES 50
#define COL_WIDTH 15

// messages for a correct answer
string message_cor[] = {"Nice Job!", "Congrats!", "Yes, That was correct!", "Way to go!", "Awesome!"}; // 0-4
// messages for incorrect answer
string message_fal[] = {"Try Again", "Nope, I don't think that's right", "Let's try that one again", "Whoa, No way!", "That's Crazy!"}; // 0-2

// global arrays for the files
int array_a[NUM_VALUES];
int array_b[NUM_VALUES];
char array_opperator[NUM_VALUES];

// these get added later in pose_question()
int array_attempts[NUM_VALUES];
string array_correct[NUM_VALUES];


int get_problems()
	{
	int i = 0;	
	string filename;
	
	//get the filename
	cout << "Please enter a file name to the problems from" << endl;
	cin >> filename;
	ifstream inputfile;
	inputfile.open(filename.c_str());
	
	//for testing....
	//ifstream inputfile;
	//inputfile.open("input-4b.txt");	
	
	while(inputfile)
		{
		//write to arrays from the input file
		inputfile >> array_a[i];
		inputfile >> array_b[i];
		inputfile >> array_opperator[i];
		
		//break file if "0 0 0"
		if(array_a[i] == 0 && array_b[i] == 0 && array_opperator[i] == '0')
			{
			cout << "end of file .... \n"; 
			break;
			}
		else i++; //increment if no error!
		}
	
	// return the length of the array
	cout << "Finished reading files from " << filename << endl;
	return i;
	}
	
// error checking is important 
double error_check()
	{
	char user_entry[20]; // if more then 20 we have stack smash... how to fix?... a limit?
	double user_double;
	bool bad = true;
	
	// loop until good numerical input
	while(bad)
		{
		// reset result flag
		cin >> user_entry;
		user_double = atof(user_entry);
		
		// atof function will give zero if you dont have a number
		if(user_double == 0 && user_entry != 0)   
			{
			cout << "Oh no, I don't think that was a number!" << endl;
			bad = true;
			}
		else bad = false;
			
		}
	
	return user_double;
	}	
	
	
void question(int a, int b, char op)
	{
	// the question to output
	cout << "what is " << a << " " << op << " " << b << " ? \n";
	}
	
	
bool check_answer(double known, double guess )
	{
	// checks the answer
	if(int(known*10) == int(guess*10)) return true;
	else return false;
	}
	
void printmessage(bool correct)
	{
	// prints the success or the failure message
	int msg;
	msg = rand() % 4;
	if(correct == true) cout << message_cor[msg] << endl;
	else cout << message_fal[msg];
	}
	
bool find_answer(int a, int b, char op)
	{
	double response, z;
	bool correct;
	
	// test the value from the operator array
	// this could be cleaned up maybe
	if(op == '+') z = a + b;
	else if(op == '-')	z = a - b;	
	else if(op == '/')  z = float(a) / float(b);	
	else if(op == '*')  z = a * b;
	else
		{
		cout << "...hmm something was wrong with the operator! \n";
		return true;
		}
		
	// ask the question
	question(a,b,op);
	
	// get a response, and check for valid entry!!!
	response = error_check();
	
	// get the correct answer
	correct = check_answer(z, response);
	
	// print message if correct or wrong
	printmessage(correct);
	
	if(correct == true) return true;
	else return false;
	}
	
	
void pose_question(int len_array)
	{
	cout << "\n\nYou will now be asked " << len_array << " questions...";
	
	int i = 0;
	while(i < len_array)
		{
		cout << "\nYou are on question " << i << " out of " << len_array <<endl;
		
		// evaluates find answer, increments if correct
		if(find_answer(array_a[i], array_b[i], array_opperator[i]))	
			{
			//increment attempts for this question
			array_attempts[i]++;
			array_correct[i] = "yes";
			i++;
			}
		else 
			{
			//increment attempts on failure
			array_attempts[i]++;
			if(array_attempts[i] >= 5)
				{
				// if the attempts are more than five, skip
				cout << "Skipping this question! \n";
				array_correct[i] = "no";
				i++;
				}
			}
		}
	}
	
	
void display_results(int len_array)	
	{
	cout <<  "Yay, you have finished! Check your results!\n";
	
	//heading to display columns
	cout 
		<< setw(COL_WIDTH) << "Problem#" 
		<< setw(COL_WIDTH) << "A" 
		<< setw(COL_WIDTH) << "opperator" 
		<< setw(COL_WIDTH) << "B" 
		<< setw(COL_WIDTH) << "Correct?" 
		<< setw(COL_WIDTH) << "# Attempts" 
		<< endl;
		
	// loop through and display data	
	int i = 0;
	for( ; i < len_array; i++)
		{
		cout 
			<< setw(COL_WIDTH) << (i + 1) 
			<< setw(COL_WIDTH) << array_a[i] 
			<< setw(COL_WIDTH) << array_opperator[i] 
			<< setw(COL_WIDTH) << array_b[i] 
			<< setw(COL_WIDTH) << array_correct[i] 
			<< setw(COL_WIDTH) << array_attempts[i] 
			<< endl;
		}
	}
	
void write_results(int len_array)
	{
	string filename;

	//get a filename and make a file object
	cout << "Chose a name for the results file: \n";
	cin >> filename;
	ofstream outfile;
	outfile.open(filename.c_str());

	cout << "Writing file ........" <<endl;
	cout << "...";
	
	//heading to file
	outfile
		<< setw(COL_WIDTH) << "Problem#" 
		<< setw(COL_WIDTH) << "A" 
		<< setw(COL_WIDTH) << "opperator" 
		<< setw(COL_WIDTH) << "B" 
		<< setw(COL_WIDTH) << "Correct?" 
		<< setw(COL_WIDTH) << "# Attempts" 
		<< endl;
	
	//loop through and output results	
	int i = 0;	
	for( ; i < len_array; i++)
		{
		outfile
			<< setw(COL_WIDTH) << (i + 1) 
			<< setw(COL_WIDTH) << array_a[i] 
			<< setw(COL_WIDTH) << array_opperator[i] 
			<< setw(COL_WIDTH) << array_b[i] 
			<< setw(COL_WIDTH) << array_correct[i] 
			<< setw(COL_WIDTH) << array_attempts[i] 
			<< endl;
		}
	//close the file
	outfile.close();
	}

	
int main()
	{
	int len_array;
	
	// Welcome message
	cout << "Welcome to the math problem practice program \n \n";
	cout << "...";
	usleep(1000000);
	cout << "...";
	
	// read in file...
	len_array = get_problems();
	
	// ask questions
	pose_question(len_array);
	
	// display results
	display_results(len_array);
	
	// write results to a file
	write_results(len_array);
	
	return 0;
	}
