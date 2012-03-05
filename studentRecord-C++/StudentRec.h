#ifndef STUDENTREC
#define STUDENTREC

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

#endif
