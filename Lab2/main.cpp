#include <iostream>
#include "main.h"
#include <string>
using namespace  std;

// Name: Nguyen Phuoc Nguyen Phuc
// SI: 2053342

int main() {
    cout<<"Student's name: Nguyen Phuoc Nguyen Phuc"<<endl;
    cout<<"Student's ID: 2053342"<<endl;
   // int num_students = 9999;
   // cout<<"Type the number of student that you want to store: "; //
 //  cin>>num_students;

  //  string *student_list = new string[99];    // create an array of string
 //   double *score_list = new double[99];
    int count =0;
    int u=-1;
    Manager student; // create Student object
    while( u != 4){
        cout<<endl;
        cout<<"Type \"1\" if you want to add a student and his/her score into the list,"<<endl;  // options
        cout<<"Type \"2\" if you want to display the list of student,"<<endl;
        cout<<"Type \"3\" if you want to see best student(s) in class,"<<endl;
        cout<<"Otherwise, stop the process."<<endl;
        cout<<"Your choice is: ";
        cin>>u;
        cout<<endl;
        cin.ignore(32767, '\n');
        if(u ==1){   // add a student
          /*  if(count >= num_students){
                cout<<"The list reaches the maximum number of student. You can't add more."<<endl;
                continue;
            }*/
            string new_student;
            cout<<"You chose \"1\", input a new student:";
            getline(cin,new_student);
            cout<<"His/her score: ";
            double score;
            cin>>score;
            cin.ignore(32767, '\n');
            student.add_name(/*&student_list,&score_list,*/new_student,score,&count);
        }
        else if(u==2){  // show the list
            student.show(/*&student_list,&score_list,*/count);
        }
        else if(u==3){   // delete a student
          //  string name;
          //  cout<<"You chose \"3\"";
          //  getline(cin,name);
            student.best_student(/*&student_list,&score_list,*/count);
        }
        else{  //stop while loop
            cout<<"Process finished."<<endl;
            break;
        }
    }
    return 0;
  //  delete student;
  //  delete[] student_list;
  //  delete[] score_list;
}
