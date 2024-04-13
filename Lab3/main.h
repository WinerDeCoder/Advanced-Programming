#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace  std;

class Student{ //(1)
private:
    string name;
    double score;
public:
    Student(string name, double score){ // Constructor
        this->name = name;
        this->score = score;
    }
    ~Student(){   // Destructor
        cout<<"Student has been deleted"<<endl;
    }

    void show(int i){

        cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<i+1<<setw(2)<<left<<":"<<setw(27)<<left<<this->name;
        cout<<left<<"Score: "<<(this->score)<<endl;

    }

    string namee(){  // get name
        return this->name  ;
    }

    double score_of_student(){  // get score
        return this->score;
    }

    /*  void add_name(string name,double score,int *count){
          (student_list[*count]) = name;
          (score_list[*count]) = score;
          (*count)++;
          cout<<name<<" has been added to the list."<<endl;
      }

      void show(int count){
         if(count ==0){
             cout<<"The list is empty"<<endl;
             return;
         }
          for(int i=0;i<count;i++){
              cout<<setw(1)<<left<<"Student "<<setw(2)<<left<<i+1<<setw(2)<<left<<":"<<setw(27)<<left<<(student_list[i]);
              cout<<left<<"Score: "<<(score_list[i])<<endl;
          }
      }

      void best_student(int count){
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
      }*/

};