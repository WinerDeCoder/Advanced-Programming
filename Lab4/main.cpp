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

    int count =0;
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
            string new_student;
            cout<<"You chose \"1\", input a new student:";
            getline(cin,new_student);
            cout<<"His/her score: ";
            double score;
            cin>>score;
            cin.ignore(32767, '\n');
            uni_stus.add_student(new_student,score,count);
            count++;
        }
        else if(u==2){  // (4) show the list
            if(count==0){
                cout<<"The list is empty."<<endl;
            }
            else {
                for (int i = 0; i < count; i++) {
                    uni_stus.show_list(i);
                }
            }
        }
        else if(u==3){   // (5) show the best student
            if(count ==0){  // empty list
                cout<<"The list is empty."<<endl;
            }
            else{
                uni_stus.best_student(count);
            }

        }
        else if(u ==4){  // (6) delete student
            if(count==0){
                cout<<"The list is empty."<<endl;
            }
            else{
                //  cin.ignore(32767, '\n');
                cout<<"Who do you want to remove from the list: ";
                string name_to_delete;
                getline(cin,name_to_delete);
                //   cin.ignore(32767, '\n');
                bool exist=true;
                int num =0;
                int inital = count;
                int number=0;
                while(exist){
                    if(num==count){  // Reach last element
                        if(count == inital){   // No one has been deleted
                            cout<<"This name is not in the list."<<endl;
                        }
                        else{
                            cout<<number<<" studen(s), who have this name, have been removed from the list."<<endl;
                        }
                        break;
                    }
                    if(uni_stus.get_name(num)==name_to_delete){
                        uni_stus.delete_stu( &num,&count,&number);
                    }
                    else {
                        num++;
                    }
                }

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
