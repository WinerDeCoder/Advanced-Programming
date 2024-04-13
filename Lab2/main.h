#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace  std;

class Manager{
private:
    string *student_list = new string[9999];    // contain students
    double *score_list = new double[9999];     // contain scores
public:
   // Manager();
    ~Manager(){
        delete[] student_list;
        delete[] score_list;
    }
    void add_name(/*string *student_list[],double *score_list[],*/string name,double score,int *count){
        (student_list[*count]) = name;
        (score_list[*count]) = score;
        (*count)++;
        cout<<name<<" has been added to the list."<<endl;
    }

    void show(/*string *student[],double *score_list[],*/int count){
       if(count ==0){
           cout<<"The list is empty"<<endl;
           return;
       }
        for(int i=0;i<count;i++){
            cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<i+1<<setw(2)<<left<<":"<<setw(27)<<left<<(student_list[i]);
            cout<<left<<"Score: "<<(score_list[i])<<endl;
        }
    }

    void best_student(/*string *student[],double * score_list[],*/int count){
        if(count ==0){
            cout<<"The list is empty"<<endl;
            return;
        }
        double max = (score_list[0]);
        for(int i=1;i<=count;i++){
            if(max < (score_list[i])){
                max = (score_list[i]);
            }
        }
        cout<<"Best student(s) in class: "<<endl;
        for(int i =0;i<=count;i++){
            if((score_list[i]) == max){
                cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<":"<<setw(27)<<left<<(student_list[i]);
                cout<<left<<"Score: "<<(score_list[i])<<endl;
            }
        }
    }
};
