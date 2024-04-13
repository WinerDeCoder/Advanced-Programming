#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include "Student.cpp"
using namespace  std;

class University{
private:
    // I dont understand why we need university name as private member of this class since the student object already holds it.
    // but i still have it here just to follow your
    string uni_name;
    // C++ dynamic array data structure using pointers to store a list of all the student objects.
    Uni_student *Uni[99];  // max 99 Uni_students
    College_student *College[99]; // college stu

public:

    string get_Uni_name(int order){  // get name of selected Uni student
        return (Uni[order])->namee();
    }

    string get_Coolege_name(int order){  // get name of selected College student
        return (College[order])->namee();
    }

    // Methods below are all features form lab 4,3

    void add_Uni_student(Uni_Semester semester[],string name,string birthday,string school, string course, int count){  //add new Uni student into the list
        Uni[count] = new Uni_student(name, birthday, school, course, semester );
    }

    void add_College_student(College_Semester semester[],string name,string birthday,string school, string course, int count){  //add new College student into the list
        College[count] = new College_student(name, birthday, school, course, semester );
    }

    void show_list_Uni(int count_uni){  // show list of Uni students
        cout<<"List of Uni Students: "<<endl;
        for(int i=0;i<count_uni;i++) {
            cout<<i+1<<"."<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<Uni[i]->namee()<<endl;
            cout<<"    - Day of birth: "<<Uni[i]->birthday()<<endl;
            cout<<"    - University: "<<Uni[i]->school()<<endl;
            cout<<"    - Course: "<<Uni[i]->course()<<endl;
            cout<<"    - Average score: "<<Uni[i]->Average()<<endl;
        }
        cout<<endl;

    }

    void show_list_College(int count_college){  // show list of Collegestudents

        cout<<"List of College Students: "<<endl;
        for(int i=0;i<count_college;i++) {
            cout<<i+1<<"."<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<College[i]->namee()<<endl;
            cout<<"    - Day of birth: "<<College[i]->birthday()<<endl;
            cout<<"    - College: "<<College[i]->school()<<endl;
            cout<<"    - Course: "<<College[i]->course()<<endl;
            cout<<"    - Average score: "<<College[i]->Average()<<endl;
        }
        cout<<endl;

    }

    void best_Uni_student(int count_uni){  // find the best Uni student(s)
        cout<<"Best student(s) in the Uni: "<<endl;
        double max = (Uni[0])->Average();
        for(int i=1;i<count_uni;i++){   // find the highest score
            if(Uni[i]->Average()>max){
                max = Uni[i]->Average();
            }
        }

        for(int i=0;i<count_uni;i++){  // find every student with the highest scores
            if(Uni[i]->Average() == max){
                cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<Uni[i]->namee()<<endl;
                cout<<"    - Day of birth: "<<Uni[i]->birthday()<<endl;
                cout<<"    - University: "<<Uni[i]->school()<<endl;
                cout<<"    - Course: "<<Uni[i]->course()<<endl;
                cout<<"    - Average score: "<<Uni[i]->Average()<<endl;
            }
        }
        cout<<endl;
    }

    void best_College_student(int count_college){  // find the best student(s)
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
    }

    void delete_Uni_stu(int *num,int *count,int *number){   // delete Uni student(s)
        if(num==count-1){  // if it is the last student
            delete Uni[*num];
            (*count)--;
            (*number)++;
        }
        else {  // else,  move every student behind forward 1 unit, decrease the number of students by 1
            delete Uni[*num];
            for (int j = *num; j < *count; j++) {

                Uni[j] = Uni[j + 1];
            }
            (*count)--;
            (*number)++;
        }
    }

    void delete_College_stu(int *num,int *count,int *number){   // delete student(s)
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
    }

    void delete_all(int count_uni,int count_college){
        for(int i=0;i<count_uni;i++){  // free memory
            delete Uni[i];
        }

        for(int i=0;i<count_college;i++){  // free memory
            delete College[i];
        }
    }


};
