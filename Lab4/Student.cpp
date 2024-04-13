#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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

};
