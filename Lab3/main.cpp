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

    Student* students[999];  // (2) Use C++ dynamic array data structure using pointers to store a list of all the student objects.

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
            students[count] = new Student(new_student,score);
            count++;
        }
        else if(u==2){  // (4) show the list
            // student.show(/*&student_list,&score_list,*/count
            if(count==0){
                cout<<"The list is empty."<<endl;
            }
            else {
                for (int i = 0; i < count; i++) {
                    students[i]->show(i);
                }
            }
        }
        else if(u==3){   // (5) show the best student
            if(count ==0){  // empty list
                cout<<"The list is empty."<<endl;
            }
            else{
                cout<<"Best student(s) in the class: "<<endl;
                double max = students[0]->score_of_student();
                for(int i=1;i<count;i++){   // find the highest score
                    if(students[i]->score_of_student()>max){
                        max = students[i]->score_of_student();
                    }
                }

                for(int i=0;i<count;i++){  // find every student with the highest scores
                    if((students[i]->score_of_student()) == max){
                        cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<setw(27)<<left<<students[i]->namee();
                        cout<<left<<"Score: "<<(students[i]->score_of_student())<<endl;
                    }
                }
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
                    if(students[num]->namee()==name_to_delete){
                        if(num==count-1){  // if it is the last student
                            delete students[num];
                            count--;
                            number++;
                        }
                        else {  // else,  move every student behind forward 1 unit, decrease the number of students by 1
                            delete students[num];
                            for (int j = num; j < count; j++) {

                                students[j] = students[j + 1];
                            }
                            count--;
                            number++;
                        }
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

    for(int i=0;i<count;i++){  // free memory
        delete students[i];
    }
    return 0;
}