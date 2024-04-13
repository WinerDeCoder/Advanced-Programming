#include <iostream>
#include "main.h"
#include <string>
#include <vector>
using namespace std;

// Name: Nguyen Phuoc Nguyen Phuc
// SI: 2053342

int main() {
    cout<<"Student's name: Nguyen Phuoc Nguyen Phuc"<<endl;
    cout<<"Student's ID: 2053342"<<endl;

    University uni_stus;

    int count_uni =0;
    int count_college = 0;
    int u=-1;
    while( u != 5){  // While Loop  (7)
        cout<<endl;
        cout<<"Type \"1\" if you want to add a student and his/her score into the list,"<<endl;  // options
        cout<<"Type \"2\" if you want to display the list of student,"<<endl;
        cout<<"Type \"3\" if you want to see best student(s) in class,"<<endl;
        cout<<"Type \"4\" if you want to delete a student from the list,"<<endl;
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
                cout<<"Input his/her Assignments,Tests,Exam Scores in order."<<endl;
                Uni_Semester stu[8];   // class diem uni
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
                    stu[i-1].get_assignments(a,b,c);
                    stu[i-1].get_tests(d,e);
                    stu[i-1].get_exam(f);
                }
                uni_stus.add_Uni_student(stu, name, date, school, course,count_uni);  // call add func
                count_uni++;

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
                cout<<"Input his/her Assignment(s),Test(s),Exam Scores in order."<<endl;
                College_Semester college[4];
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
                    college[i-1].get_assignments(a);
                    college[i-1].get_tests(b);
                    college[i-1].get_exam(c);
                }
                uni_stus.add_College_student(college, name, date, school, course,count_college);
                count_college++;

            }

        }
        else if(u==2){  // (4) show the list
            if(count_uni==0){
                cout<<"The Uni list is empty."<<endl<<endl;
            }
            else {

                    uni_stus.show_list_Uni(count_uni);

            }

            if(count_college ==0){
                cout<<"The College list is empty"<<endl<<endl;
            }
            else {

                    uni_stus.show_list_College(count_college);

            }

        }
        else if(u==3){   // (5) show the best student
            if(count_uni==0){  // empty list
                cout<<"The Uni list is empty."<<endl<<endl;
            }
            else{
                uni_stus.best_Uni_student(count_uni);
            }

            if(count_college==0){  // empty list
                cout<<"The College list is empty."<<endl<<endl;
            }
            else{
                uni_stus.best_College_student(count_college);
            }

        }
        else if(u ==4){  // (6) delete student
            int choice;
            cout<<"Type \"1\" if you want to delete a Uni_student. Else, College_student (number only)."<<endl;
            cin>>choice;
            cout<<endl;
            cin.ignore(32767, '\n');
            if(choice==1) {
                if (count_uni == 0) {
                    cout << "The Uni list is empty." << endl<<endl;
                } else {
                    //  cin.ignore(32767, '\n');
                    cout << "Who do you want to remove from the Uni list: ";
                    string name_to_delete;
                    getline(cin, name_to_delete);
                    //   cin.ignore(32767, '\n');
                    bool exist = true;
                    int num = 0;
                    int inital = count_uni;
                    int number = 0;
                    while (exist) {
                        if (num == count_uni) {  // Reach last element
                            if (count_uni == inital) {   // No one has been deleted
                                cout << "This name is not in the list." << endl;
                            } else {
                                cout << number << " studen(s), who have this name, have been removed from the list."
                                     << endl;
                            }
                            break;
                        }
                        if (uni_stus.get_Uni_name(num) == name_to_delete) {
                            uni_stus.delete_Uni_stu(&num, &count_uni, &number);
                        } else {
                            num++;
                        }
                    }

                }
            }
            else{
                if (count_college == 0) {
                    cout << "The College list is empty." << endl<<endl;
                } else {
                    //  cin.ignore(32767, '\n');
                    cout << "Who do you want to remove from the College list: ";
                    string name_to_delete;
                    getline(cin, name_to_delete);
                    //   cin.ignore(32767, '\n');
                    bool exist = true;
                    int num = 0;
                    int inital = count_college;
                    int number = 0;
                    while (exist) {
                        if (num == count_college) {  // Reach last element
                            if (count_college == inital) {   // No one has been deleted
                                cout << "This name is not in the list." << endl;
                            } else {
                                cout << number << " studen(s), who have this name, have been removed from the list."
                                     << endl;
                            }
                            break;
                        }
                        if (uni_stus.get_Coolege_name(num) == name_to_delete) {
                            uni_stus.delete_College_stu(&num, &count_college, &number);
                        } else {
                            num++;
                        }
                    }

                }
            }
        }
        else{  //stop while loop
            cout<<"Process finished."<<endl;
            break;
        }
    }

    uni_stus.delete_all(count_uni,count_college); // free memory

    return 0;
}
