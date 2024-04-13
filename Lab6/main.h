#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include "Student.cpp"
using namespace  std;

class University{
private:
    // I don't understand why we need university name as private member of this class since the student object already holds it.
    // C++ dynamic array data structure using pointers to store a list of all the student objects.
    Student *Stu[999];  // max 999 students

public:

    string get_name(int order){  // get name of selected Uni student
        return (Stu[order])->namee();
    }

    // Methods below are all features form lab 4,3

    void add_Uni_student(string name,string type,string birthday,string school, string course, int count){  //add new Uni student into the list
        Stu[count] = new Uni_student(name, type ,birthday, school, course);
        cout<<"Do you want to randomly assign scores for this student by calling DoAssignment, TakeTest and TakeExam function?"<<endl;
        cout<<"If yes, type \"1\", else all the scores of this student will be 0. But you can always assign scores for students later :";
        int n;
        cin>>n;
        if(n==1) {
            Stu[count]->DoAssignment();   //automatically call random functions
            Stu[count]->TakeTest();        // this is for lab 6
            Stu[count]->TakeExam();
            Stu[count]->Average();
        }
    }

    void add_College_student(string name,string type,string birthday,string school, string course, int count){  //add new Uni student into the list
        Stu[count] = new College_student(name, type ,birthday, school, course );
        cout<<"Do you want to randomly assign scores for this student by calling DoAssignment, TakeTest and TakeExam function?"<<endl;
        cout<<"If yes, type \"1\", else all the scores of this student will be 0. But you can always assign scores for students later :";
        int n;
        cin>>n;
        if(n==1) {
            Stu[count]->DoAssignment();   //automatically call random functions
            Stu[count]->TakeTest();        // this is for lab 6
            Stu[count]->TakeExam();
            Stu[count]->Average();
        }
    }

    void random_scores(int count){ // lab 6's function
        Stu[count]->DoAssignment();   //automatically call random functions
        Stu[count]->TakeTest();        // this is for lab 6
        Stu[count]->TakeExam();
        Stu[count]->Average();
        cout<<"The scores for this student were randomly assigned."<<endl;
    }

    void show_list(int count){  // show list of Uni students     # can them type
        cout<<"List of Students: "<<endl;
        for(int i=0;i<count;i++) {
            cout<<i+1<<"."<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<Stu[i]->namee()<<endl;
            cout<<"    - Type of student: "<<Stu[i]->typee()<<endl;
            cout<<"    - Day of birth: "<<Stu[i]->birthday()<<endl;
            cout<<"    - University: "<<Stu[i]->school()<<endl;
            cout<<"    - Course: "<<Stu[i]->course()<<endl;
            cout<<"    - Average score: "<<Stu[i]->Average()<<endl;
        }
        cout<<endl;

    }

  /*  void show_list_College(int count_college){  // show list of Collegestudents

        cout<<"List of College Students: "<<endl;
        for(int i=0;i<count_college;i++) {
            cout<<i+1<<"."<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<College[i]->namee()<<endl;
            cout<<"    - Day of birth: "<<College[i]->birthday()<<endl;
            cout<<"    - College: "<<College[i]->school()<<endl;
            cout<<"    - Course: "<<College[i]->course()<<endl;
            cout<<"    - Average score: "<<College[i]->Average()<<endl;
        }
        cout<<endl;

    } */

    void best_student(int count_uni){  // find the best Uni student(s)
        cout<<"Best student(s) in the class: "<<endl;
        double max = (Stu[0])->Average();
        for(int i=1;i<count_uni;i++){   // find the highest score
            if(Stu[i]->Average()>max){
                max = Stu[i]->Average();
            }
        }

        for(int i=0;i<count_uni;i++){  // find every student with the highest scores
            if(Stu[i]->Average() == max){
                cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<Stu[i]->namee()<<endl;
                cout<<"    - Type of student: "<<Stu[i]->typee()<<endl;
                cout<<"    - Day of birth: "<<Stu[i]->birthday()<<endl;
                cout<<"    - University: "<<Stu[i]->school()<<endl;
                cout<<"    - Course: "<<Stu[i]->course()<<endl;
                cout<<"    - Average score: "<<Stu[i]->Average()<<endl;
            }
        }
        cout<<endl;
    }

  /*  void best_College_student(int count_college){  // find the best student(s)
        cout<<"Best student(s) in the College: "<<endl;
        double max = (College[0])->Average();
        for(int i=1;i<count_college;i++){   // find the highest score
            if(College[i]->Average()>max){
                max = College[i]->Average();
            }
        }

        for(int i=0;i<count_college;i++){  // find every student with the highest scores
            if(College[i]->Average() == max){
                cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<College[i]->namee()<<endl;
                cout<<"    - Day of birth: "<<College[i]->birthday()<<endl;
                cout<<"    - College: "<<College[i]->school()<<endl;
                cout<<"    - Course: "<<College[i]->course()<<endl;
                cout<<"    - Average score: "<<College[i]->Average()<<endl;
            }
        }
    }    */

    void delete_stu(int *num,int *count,int *number){   // delete Uni student(s)
        if(num==count-1){  // if it is the last student
            delete Stu[*num];
            (*count)--;
            (*number)++;
        }
        else {  // else,  move every student behind forward 1 unit, decrease the number of students by 1
            delete Stu[*num];
            for (int j = *num; j < *count; j++) {

                Stu[j] = Stu[j + 1];
            }
            (*count)--;
            (*number)++;
        }
    }

  /*  void delete_College_stu(int *num,int *count,int *number){   // delete student(s)
        if(num==count-1){  // if it is the last student
            delete College[*num];
            (*count)--;
            (*number)++;
        }
        else {  // else,  move every student behind forward 1 unit, decrease the number of students by 1
            delete College[*num];
            for (int j = *num; j < *count; j++) {

                College[j] = College[j + 1];
            }
            (*count)--;
            (*number)++;
        }
    }  */

    void delete_all(int count_uni){
        for(int i=0;i<count_uni;i++){  // free memory
            delete Stu[i];
        }

    }


};
