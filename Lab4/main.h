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
    Student *students[999];  // max 999 students

public:

    string get_name(int order){  // get name of selected student
        return (students[order])->namee();
    }

    // Methods below are all features form lab 3

    void add_student(string name,double score,int count){  //add new student into the list
        students[count] = new Student(name,score);
    }

    void show_list(int i){  // show list of students
        (students[i])->show(i);
    }

    void best_student(int count){  // find the best student(s)
        cout<<"Best student(s) in the class: "<<endl;
        double max = (students[0])->score_of_student();
        for(int i=1;i<count;i++){   // find the highest score
            if(students[i]->score_of_student()>max){
                max = students[i]->score_of_student();
            }
        }

        for(int i=0;i<count;i++){  // find every student with the highest scores
            if(((students[i])->score_of_student()) == max){
                cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<setw(27)<<left<<students[i]->namee();
                cout<<left<<"Score: "<<((students[i])->score_of_student())<<endl;
            }
        }
    }

    void delete_stu(int *num,int *count,int *number){   // delete student(s)
        if(num==count-1){  // if it is the last student
            delete students[*num];
            (*count)--;
            (*number)++;
        }
        else {  // else,  move every student behind forward 1 unit, decrease the number of students by 1
            delete students[*num];
            for (int j = *num; j < *count; j++) {

                students[j] = students[j + 1];
            }
            (*count)--;
            (*number)++;
        }
    }

    void delete_all(int count){
        for(int i=0;i<count;i++){  // free memory
            delete students[i];
        }
    }


};
