#include <iostream>
#include "main.h"
#include <string>
using namespace  std;

// Name: Nguyen Phuoc Nguyen Phuc
// SI: 2053342

int main() {
    int num_students;
    cout<<"Type the number of student that you want to store: "; //
    cin>>num_students;

    string list[num_students];    // create an array of string
    int count =0;
    int u=-1;
    Manager student; // create Student object
    while( u != 4){
        cout<<endl;
        cout<<"Type \"1\" if you want to add a student into the list,"<<endl;  // options
        cout<<"Type \"2\" if you want to display the list of student,"<<endl;
        cout<<"Type \"3\" if you want to delete a student out of the list,"<<endl;
        cout<<"Otherwise, stop the process."<<endl;
        cout<<"Your choice is: ";
        cin>>u;
        cout<<endl;
        cin.ignore(32767, '\n');
        if(u ==1){   // add a student
            if(count >= num_students){
                cout<<"The list reaches the maximum number of student. You can't add more."<<endl;
                continue;
            }
            string new_student;
            cout<<"You chose \"1\", input a new student: ";
            getline(cin,new_student);
            student.add_name(list,new_student,&count);
        }
        else if(u==2){  // show the list
            student.show(list,count);
        }
        else if(u==3){   // delete a student
            string name;
            cout<<"You chose \"3\", Who do you want to delete : ";
            getline(cin,name);
            student.delete_name(list,name,&count);
        }
        else{  //stop while loop
            cout<<"Process finished."<<endl;
            break;
        }
    }
}
