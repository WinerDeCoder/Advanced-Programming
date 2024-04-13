#include <iostream>
#include <string>
using namespace std;

class Uni_Semester{  // class to contain Uni semester scores
protected:
    double assignment[3] = {0,0,0};   // 3 assignments
    double tests[2] = {0,0};   // 2 tests
    double exam = 0;   // 1 exam
public:

    void get_assignments(double a, double b, double c){  // take input
        this->assignment[0] = a;
        this->assignment[1] = b;
        this->assignment[2] = c;
    }

    void get_tests(double a, double b){
        this->tests[0] = a;
        this->tests[1] = b;
    }

    void get_exam(double a){
        this->exam = a;
    }

    double get_average_score(){
        double average = (this->assignment[0] + this->assignment[1] + this->assignment[2] + this->tests[0] + this->tests[1] + this->exam)/6;
        return average;
    }
};

class College_Semester{  // for College semester score
protected:
    double assignment = 0;
    double tests = 0;
    double exam = 0;
public:
    void get_assignments(double a){
        this->assignment = a;
    }

    void get_tests(double a){
        this->tests = a;
    }

    void get_exam(double a){
        this->exam = a;
    }

    double get_average_score(){
        double average = (this->assignment + this->tests + this->exam)/3;
        return average;
    }
};


class Student{ //(1)
protected:
    string name;
    string date_of_birth;
    string school_name;
    string courses_name;
    double score=0;
public:
    Student(string name, string date, string school, string course, double score){ // Constructor
        this->name = name;
        this->date_of_birth = date;
        this->school_name = school;
        this->courses_name = course;
        this->score = score;
    }

    ~Student(){   // Destructor
        cout<<"Student has been deleted"<<endl;
    }

    string namee(){  // get name
        return this->name  ;
    }

    string birthday(){  // get birthday
        return this->date_of_birth;
    }

    string school(){   // get school
        return this->school_name;
    }

    string course(){   // get course
        return this->courses_name;
    }

};

class Uni_student : public Student{    // Uni students class
private:
    Uni_Semester semesters[8];   // each course has 8 semesters
    double average=0;  //average score
public:
    Uni_student(string name, string date, string school, string course, Uni_Semester semester[8]): Student(name,date,school,course,this->average) {
        for( int i =0;i<8;i++){
            semesters[i] = semester[i];
        }

        double average1;
        for( int i=0;i<8;i++){
            average1 += semesters[i].get_average_score();
        }
        average1 = average1/8;
        this->average = average1;
    }

    double Average(){
        return this->average;
    }
};

class College_student : public Student{
private:
    College_Semester semesters[4];
    double average=0;
public:
    College_student(string name, string date, string school, string course, College_Semester semester[4]): Student(name,date,school,course,this->average) {
        for( int i =0;i<4;i++){
            semesters[i] = semester[i];
        }

        double average1;
        for( int i=0;i<4;i++){
            average1 += semesters[i].get_average_score();
        }
        average1 = average1/4;
        this->average = average1;
    }

    double Average(){
        return this->average;
    }

};


