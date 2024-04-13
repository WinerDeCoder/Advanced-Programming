#include <iostream>
#include "main.h"
#include <string>
#include <vector>
using namespace std;

// Name: Nguyen Phuoc Nguyen Phuc
// SI: 2053342


// Lab 6: The polymorphism method is shown in main.h. In function add_Uni and add_College, I set the programme to automatically call these functions.



int main() {
    cout<<"Student's name: Nguyen Phuoc Nguyen Phuc"<<endl;
    cout<<"Student's ID: 2053342"<<endl;

    University uni_stus;   // Call main class University


    int count =0;
    int u=-1;
    while( u != 6){  // While Loop  (7)
        cout<<endl;
        cout<<"Type \"1\" if you want to add a student and his/her score into the list,"<<endl;  // options
        cout<<"Type \"2\" if you want to display the list of student,"<<endl;
        cout<<"Type \"3\" if you want to see best student(s) in class,"<<endl;
        cout<<"Type \"4\" if you want to delete a student from the list,"<<endl;
        cout<<"Type \"5\" if you want to randomly assign scores for a selected student."<<endl;
        cout<<"Otherwise, stop the process."<<endl;
        cout<<"Your choice is: ";
        cin>>u;
        cout<<endl;
        cin.ignore(32767, '\n');
        if(u ==1){   // (3) add a student
            int choice;
            cout<<"Type \"1\" if he/she is a Uni_student. Otherwise, he/she is a College_student (number only)."<<endl;
            cin>>choice;
            cout<<endl;
            cin.ignore(32767, '\n');
            if(choice ==1) {    // add uni student
                cout<<"You chose to add a new Uni_Student."<<endl;
                cout<<"His/her name: ";    // take input
                string name;
                getline(cin, name);
                cout<<endl;
                cout<<"His/her date of birth ( Date/Month/Year ): ";
                string date;
                cin>>date;
                cin.ignore(32767, '\n');
                cout<<endl;
                cout<<"His/her University: ";
                string school;
                getline(cin, school);
                cout<<endl;
                cout<<"His/her course: ";
                string course;
                getline(cin, course);
                cout<<endl;
                cout << "There are 8 semesters in his/her course and each semester has 3 assignments, 2 tests and 1 exam. "<<endl;
               // cout<<"These scores will be randomly assign for each student."<<endl;
              /*  Uni_Semester stu[8];   // class diem uni
                for( int i =1; i<=8;i++){
                    cout<<"Semester "<<i<<":"<<endl;
                    double a,b,c,d,e,f;
                    cout<<"-Assignment 1: ";
                    cin>>a;
                    cout<<endl;
                    cout<<"Assignment 2: ";
                    cin>>b;
                    cout<<endl;
                    cout<<"Assignment 3: ";
                    cin>>c;
                    cout<<endl;
                    cout<<"Tets 1: ";
                    cin>>d;
                    cout<<endl;
                    cout<<"Tets 1: ";
                    cin>>e;
                    cout<<endl;
                    cout<<"Exam: ";
                    cin>>f;
                    cout<<endl;
                    // save scores

                }*/
                uni_stus.add_Uni_student( name,"Uni student", date, school, course,count);  // call add func
                count++;
            }
            else{   // add college stu
                cout<<"You chose to add a new College_Student."<<endl;
                cout<<"His/her name: ";
                string name;
                getline(cin, name);
                cout<<endl;
                cout<<"His/her date of birth ( Date/Month/Year ): ";
                string date;
                cin>>date;
                cin.ignore(32767, '\n');
                cout<<endl;
                cout<<"His/her College: ";
                string school;
                getline(cin, school);
                cout<<endl;
                cout<<"His/her course: ";
                string course;
                getline(cin, course);
                cout<<endl;
                cout << "There are 4 semesters in his/her course and each semester has an assignment, a test and an exam. "<<endl;
             //   cout<<"These scores will be randomly assign for each student."<<endl;
               /* College_Semester college[4];
                for( int i =1; i<=4;i++){
                    cout<<"Semester "<<i<<":"<<endl;
                    double a,b,c;
                    cout<<"Assignment: ";
                    cin>>a;
                    cout<<endl;
                    cout<<"Test: ";
                    cin>>b;
                    cout<<endl;
                    cout<<"Exam: ";
                    cin>>c;
                    cout<<endl;
                } */
                uni_stus.add_College_student(name,"College student", date, school, course,count);
                count++;
            }
        }
        else if(u==2){  // (4) show the list
            if(count==0){
                cout<<"The list is empty."<<endl<<endl;
            }
            else {
                    uni_stus.show_list(count);
            }
        }
        else if(u==3){   // (5) show the best student
            if(count==0){  // empty list
                cout<<"The Uni list is empty."<<endl<<endl;
            }
            else{
                uni_stus.best_student(count);
            }
        }
        else if(u ==4) {  // (6) delete student
            if (count == 0) {
                cout << "The Uni list is empty." << endl << endl;
            } else {
                //  cin.ignore(32767, '\n');
                cout << "Who do you want to remove from the list: ";
                string name_to_delete;
                getline(cin, name_to_delete);
                //   cin.ignore(32767, '\n');
                bool exist = true;
                int num = 0;
                int inital = count;
                int number = 0;
                while (exist) {
                    if (num == count) {  // Reach last element
                        if (count == inital) {   // No one has been deleted
                            cout << "This name is not in the list." << endl;
                        } else {
                            cout << number << " studen(s), who have this name, have been removed from the list."
                                 << endl;
                        }
                        break;
                    }
                    if (uni_stus.get_name(num) == name_to_delete) {
                        uni_stus.delete_stu(&num, &count, &number);
                    } else {
                        num++;
                    }
                }
            }
        }
        else if(u ==5){  // call Lab 6's functions
            if (count == 0) {
                cout << "The Uni list is empty." << endl << endl;
            } else {
                cout<<"Which student do you want to randomly assign scores ( type his/her order in the list ) ? :";
                int choi;  // order of that student
                cin>>choi;
                uni_stus.random_scores(choi-1);
            }
        }
        else{  //stop while loop
            cout<<"Process finished."<<endl;
            break;
        }
    }
    uni_stus.delete_all(count); // free memory
    return 0;
}
