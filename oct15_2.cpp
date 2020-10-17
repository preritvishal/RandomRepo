#include <iostream>
#include <cstdlib>
#include <string>

#define MAX 100
#define TAB "\t"
#define PAUSE cin.ignore();
#define CLEAR system("clear");

static short index(-1);

using namespace std;

class Patient_DB{

    string p_name[MAX];
    char p_sex[MAX];
    short p_age[MAX];
    short p_bed_number[MAX];
    short p_ward_number[MAX];
    string p_nature_of_sickness[MAX];
    struct date{
        short day;
        short month;
        int year;
    } p_admission[MAX];

    public :

    void MasterTable(){

        for(short i(0); i<= 80; ++i)
            cout << "=" ;
        cout << endl;

        cout << "Ward   Bed \t Name  \t Age   Sex   Sickness type\t  Date" << endl ;

        for(short i(0); i<= 80; ++i)
        cout << "=" ;
        cout << endl;
        

        for(short i(0); i<= index; ++i){
            cout << p_ward_number[i] << TAB << p_bed_number[i] << TAB << p_name[i] << TAB
                 << p_age[i] << TAB << p_sex[i] << TAB << p_nature_of_sickness[i] << TAB << p_admission[i].day <<
                 "-" << p_admission[i].month << "-" << p_admission[i].year << endl ;
        }

        for(short i(0); i<= 80; ++i)
            cout << "=" ;
        cout << endl;
    }

    void listOne(short b_num,short w_num){
        if(b_num == 0 || w_num == 0)
            cout << "Error : Invalid request" << endl ;
            
        for(short i(0); i<=index; ++i){

            if(b_num == p_bed_number[i] && w_num == p_ward_number[i]){

                for(short i(0); i<= 80; ++i)
                cout << "=" ;
                cout << endl;

                cout << "Ward   Bed \t Name  \t Age   Sex   Sickness type\t  Date" << endl ;

                for(short i(0); i<= 80; ++i)
                cout << "=" ;
                cout << endl;
                
                cout << p_ward_number[i] << TAB << p_bed_number[i] << TAB << p_name[i] << TAB
                        << p_age[i] << TAB << p_sex[i] << TAB << p_nature_of_sickness[i] << TAB << p_admission[i].day <<
                        "-" << p_admission[i].month << "-" << p_admission[i].year << endl ;
                
                for(short i(0); i<= 80; ++i)
                cout << "=" ;
                cout << endl;
            }
            else
                cout << "Error : Requested Entry not found " << endl ;
        }
    }

    void newEntry(){
        ++index;

        cout << "Enter the name of Patient : " ;
        cin >> p_name[index];
        cout << "Enter sex [M/F/O] : ";
        cin >> p_sex[index];
        cout << "Enter Age : " ;
        cin >> p_age[index];
        cout << "Nature of sickess [Mild/Critical/Severe] : " ;
        cin >> p_nature_of_sickness[index];
        cout << "Enter ward number : " ;
        cin >> p_ward_number[index];
        cout << "Ennter bed number : " ;
        cin >> p_bed_number[index] ;
        cout << "Enter date " << endl;
        cout << "\tDay [1-31] : ";
        cin >> p_admission[index].day;
        cout << "\tMonth [1-12] : " ;
        cin >> p_admission[index].month;
        cout << "\tYear [2000-THIS_YEAR] : ";
        cin >> p_admission[index].year ;
        cout << endl << endl ;
        cout << "Patient named " << p_name[index] << " has been admitted." << endl;
        // cout << "Ward number : " << rand()%9 * 10 ;
    }

    void delEntry(short b_num,short w_num){
        if(b_num == 0 || w_num == 0)
        cout << "Error : Invlid Bed/Ward number " ;
        else{
            for(short i(0); i<=index; ++i){
                if(b_num == p_bed_number[i] && w_num == p_ward_number[index]){

                    p_name[i] = "Deleted Entry" ;
                    p_sex[i] = '-' ;
                    p_age[i] = 0 ;
                    p_bed_number[i] = 0 ;
                    p_ward_number[i] = 0 ;
                    p_nature_of_sickness[i] = "N/A" ;
                    p_admission[i].day = 0 ;
                    p_admission[i].month = 0 ;
                    p_admission[i].year = 0 ;

                    cout << "Success : Entry Deleted sucessfully" << endl ;
                }
                else
                    cout << "Error : Can't find matching entry" << endl ;
            }
        }
    }

    void editEntry(short b_num,short w_num){

        if(b_num == 0 || w_num == 0)
        cout << "Error : Invlid Bed/Ward number " ;
        else{
            for(short i(0); i<=index; ++i){
                if(b_num == p_bed_number[i] && w_num == p_ward_number[index]){

                    cout << "Enter the name of Patient : " ;
                    cin >> p_name[i];
                    cout << "Enter sex [M/F/O] : ";
                    cin >> p_sex[i];
                    cout << "Enter Age : " ;
                    cin >> p_age[i];
                    cout << "Nature of sickess [Mild/Critical/Severe] : " ;
                    cin >> p_nature_of_sickness[i];
                    cout << "Enter ward number : " ;
                    cin >> p_ward_number[i];
                    cout << "Ennter bed number : " ;
                    cin >> p_bed_number[i] ;
                    cout << "Enter date " << endl;
                    cout << "\tDay [1-31] : ";
                    cin >> p_admission[i].day;
                    cout << "\tMonth [1-12] : " ;
                    cin >> p_admission[i].month;
                    cout << "\tYear [2000-THIS_YEAR] : ";
                    cin >> p_admission[i].year ;
                    cout << endl << endl ;

                    cout << "Success : Entry edited sucessfully" << endl ;
                }
                else
                    cout << "Error : Can't find matching entry" << endl ;
            }
        }
    }

    void searchEntry(string name){
            
    }

    void searchEntry(short num){
        
    }
    
};

int main(){
    Patient_DB obj;
    
    short num_input1(0) ;
    short num_input2(0) ;
    string alpha_input ;

    do{
        cout << "\n\n\t\tWelcome to Patient DBMS \n\n" ;
        cout << "What do you want to do ?" << endl ;
        cout << "1. Admit a patient" << endl ; 
        cout << "2. Edit patient details" << endl ; 
        cout << "3. Delete patient detail" << endl ; 
        cout << "4. See/visit a patient" << endl ; 
        cout << "5. See/visit all patient" << endl ; 
        cout << "6. Search a patient" << endl ; 
        cout << "0. exit" << endl ; 

        cout << "Enter your choice :" ;
        cin >> num_input1 ;

        switch(num_input1){

            case 0 : CLEAR
                     exit(0);

            case 1 : CLEAR
                     obj.newEntry();
                     break;

            case 2 : CLEAR
                     cout << "Enter the bed number of patient : ";
                     cin >> num_input1 ;
                     cout << "Enter the ward number of patient : ";
                     cin >> num_input2 ;
                     obj.editEntry(num_input1,num_input2);
                     break;
            
            case 3 : CLEAR
                     cout << "Enter the bed number of patient : ";
                     cin >> num_input1 ;
                     cout << "Enter the ward number of patient : ";
                     cin >> num_input2 ;
                     obj.delEntry(num_input1,num_input2);
                     break;
            
            case 4 : CLEAR
                     cout << "Enter the bed number of patient : ";
                     cin >> num_input1 ;
                     cout << "Enter the ward number of patient : ";
                     cin >> num_input2 ;
                     obj.listOne(num_input1,num_input2);
                     break;

            case 5 : CLEAR
                     obj.MasterTable();
                     break;

            case 6 : CLEAR
                     cout << "Hold on : Work under Progress \n Acche din aane wale hai " << endl ;
                     
                     

        }
    }
    while(num_input1);
    return 0;
}