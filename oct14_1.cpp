#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 100
#define TAB "\t"
using namespace std;

static short index(-1);

class Employee_DB{

	string em_name[MAX] ;
	long em_code[MAX] ;
	string em_designation[MAX] ;
	short em_year_o_exp[MAX] ;
	short em_age[MAX] ;

	public:

	void MasterTable(void){
		cout << "Code \t Name \t    Designation   age \t Years of exp " << endl ;
		for(short i(0); i<76; ++i)
			cout << "=" ;
		cout << endl ;

		for (short i(0); i <= index; ++i)
			cout << em_code[i] << TAB << em_name[i] << TAB << em_designation[i]
				 << "\t   " << em_age[i] << TAB << em_year_o_exp[i] << endl ;
		
		for(short i(0); i<76; ++i)
			cout << "=" ;
		cout << endl ;
	}

	void listOne(long code){
		if(code == 0)
		cout << "Error : Deleted entry can't be shown" << endl ;
		else{
		
			for(short i(0); i<= index ; ++i)

				if(code == em_code[i]){

					cout << "Code \t Name \t    Designation   age \t Years of exp " << endl ;
					for(short i(0); i<76; ++i)
						cout << "=" ;
					cout << endl ;
						cout << em_code[i] << TAB << em_name[i] << TAB << em_designation[i]
							<< "\t   " << em_age[i] << TAB << em_year_o_exp[i] << endl ;
					for(short i(0); i<76; ++i)
						cout << "=" ;
					cout << endl ;
				}
				else
					cout << "Error : Entry not found " << endl ;
		}
	}

	void newEntry(){
		++index;
		
		cout << "Enter Name : " ;
		getline(cin,em_name[index]);
		// cin.ignore();
		// cin >> em_name[index];
		cout << "Enter Designation : " ;
		// cin.ignore();
		// cin >> em_designation[index];
		getline(cin,em_designation[index]);
		
		cout << "Enter Employee code : ";
		cin >> em_code[index] ;
		cout << "Enter Age (as on 01-01-THIS-YEAR) : " ;
		cin >> em_age[index] ;
		cout << "Enter Years of experience : " ;
		cin >> em_year_o_exp[index] ;
	}

	void delEntry(long code){

		for(short i(0); i<= index ; ++i)
			if(code == em_code[i]){
				em_name[i] = "Deleted Entry";
				em_designation[i] = "NULL";
				em_code[i] = 0;
				em_age[i] = 0;
				em_year_o_exp[i] = 0;
				cout << "Entry Has been deleted" << endl ;
			}
			else
			cout << "Error : Entered Code didn't matched any entry" << endl ;

	}

	void editEntry(long code){
		for(short i(0); i<= index ; ++i)
			if(code==0)
			cout << "Error : Deleted entries can't be edited" << endl ;
			else if(code == em_code[i]){

				cout << "Editing entry : " << em_code[i] << endl << endl ;

				cout << "Enter Name : " ;
				cin >> em_name[i];
				// cin.ignore();
				cout << "Enter Designation : " ;
				cin >> em_designation[i];
				// cin.ignore();
				cout << "Enter Age (as on 01-01-THIS-YEAR) : " ;
				cin >> em_age[i] ;
				cout << "Enter Years of experience : " ;
				cin >> em_year_o_exp[i] ;

			}
			else
				cout << "Error : Entered Code didn't matched any entry" << endl ;		
	}

	void searchEntry(long code){
		for(short i(0); i<= index ; ++i)
			if(code == em_code[i])
				cout << "Success : Entry found \n Goto Show entry option to view it" << endl;
			else
				cout << "Error : Entry not found" << endl;
	}
};


int main(){

	Employee_DB obj;
	long input(0);
	string dummy;
	
	do{
		cout << endl << endl << TAB << "Welcome to Employee DBMS"<< endl << endl;
		cout << "What do you want to do ?" << endl ;
		cout << "1. Add New entries" << endl ;
		cout << "2. Edit an entry" << endl ;
		cout << "3. Delete an entry" << endl ;
		cout << "4. Search an entry" << endl;
		cout << "5. Show an entry" << endl;
		cout << "6. Show all entries" << endl;
		cout << "0. Exit" << endl;

		cin >> input ;

		switch(input){
			case 0 : 	exit(0);

			case 1 : 	system("clear");
						cout << "Enter the number of Entries you want to make : ";
						cin >> input ;
						getline(cin,dummy);
						for(short i(0); i<input; ++i)
							obj.newEntry();
						break;

			case 2 : 	system("clear");
						cout << "Enter the code to edit an entry: ";
						cin >> input ;
						obj.editEntry(input);
						break;

			case 3 : 	system("clear");
						cout << "Enter the code to delete an entry: ";
						cin >> input ;
						obj.delEntry(input);
						break;

			case 4 :	system("clear");
						cout << "Enter the code to search an entry: ";
						cin >> input ;
						obj.searchEntry(input);
						break;

			case 5 :	system("clear");
						cout << "Enter the code to show an entry: ";
						cin >> input ;
						obj.listOne(input);
						break;

			case 6 : 	system("clear");
						cout << "Showing all entries" << endl << endl ;
						obj.MasterTable();
						break;
		}

	}
	while(input);
	


	return 0;
}