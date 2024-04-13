#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

/*
class Uni_Semester{  // class to contain Uni semester scores
protected:
    int assignment[3] = {0,0,0};   // 3 assignments
    int tests[2] = {0,0};   // 2 tests
    int exam = 0;   // 1 exam
public:

    void random_Assignment(){  // take input
        this->assignment[0] = rand() % (10-1+1)+1;
        this->assignment[1] = rand() % (10-1+1)+1;
        this->assignment[2] = rand() % (10-1+1)+1;
    }

    void random_Test(){
        this->tests[0] = rand() % (10-1+1)+1;
        this->tests[1] = rand() % (10-1+1)+1;
    }

    void random_Exam(){
        this->exam = rand() % (10-1+1)+1;
    }


    int get_average_score(){
        double average = (this->assignment[0] + this->assignment[1] + this->assignment[2] + this->tests[0] + this->tests[1] + this->exam)/6;
        return average;
    }
};

class College_Semester{  // for College semester score
protected:
    int assignment = 0;
    int tests = 0;
    int exam = 0;
public:
    void random_Assignment(){
        this->assignment = rand() % (10-1+1)+1;
    }

    void random_Test(){
        this->tests = rand() % (10-1+1)+1;
    }

    void random_Exam(){
        this->exam = rand() % (10-1+1)+1;
    }

    int get_average_score(){
        double average = (this->assignment + this->tests + this->exam)/3;
        return average;
    }
};
*/

class Student{ //(1)   // class Student
protected:
    string name;
    string type;
    string date_of_birth;
    string school_name;
    string courses_name;
    double score;
public:

    Student(string name, string type, string date, string school, string course){ // Constructor
        this->name = name;
        this->type = type;
        this->date_of_birth = date;
        this->school_name = school;
        this->courses_name = course;
    }

    virtual void DoAssignment(){
        this->score = 0;
    }

    virtual void TakeTest(){
        this->score = 0;
    }

    virtual void TakeExam(){
        this->score = 0;
    }

    ~Student(){   // Destructor
        cout<<"Student has been deleted"<<endl;
    }

    string namee(){  // get name
        return this->name  ;
    }

    string typee(){
        return this->type;
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

    virtual double Average(){   // virtual method - polymorphism
        return this->score;
    }

};

class Uni_student : public Student{    // Uni students class   ( child class of Student)
private:
 //   Uni_Semester semesters[8];   // each course has 8 semesters
    double average=0;  //average score
    double assignment[3] = {0,0,0};   // 3 assignments
    double tests[2] = {0,0};   // 2 tests
    double exam = 0;   // 1 exam
public:

    Uni_student(string name, string type, string date, string school, string course): Student(name,type,date,school,course) {
       /* double average1;
        for( int i=0;i<8;i++){
            average1 += semesters[i].get_average_score();
        }
        average1 = average1/8;
        this->average = average1;
        Student::get_ave(average1);  */
    }

    void DoAssignment(){  // take input
        srand(time(nullptr));
        this->assignment[0] = rand() % (10-1+1)+1;
        this->assignment[1] = rand() % (10-1+1)+1;
        this->assignment[2] = rand() % (10-1+1)+1;
    }

    void TakeTest(){
        srand(time(nullptr));
        this->tests[0] = rand() % (10-1+1)+1;
        this->tests[1] = rand() % (10-1+1)+1;
    }

    void TakeExam(){
        srand(time(nullptr));
        this->exam = rand() % (10-1+1)+1;
    }

    double Average(){  // polymorphism
        double average = (this->assignment[0] + this->assignment[1] + this->assignment[2] + this->tests[0] + this->tests[1] + this->exam)/6;
        this->average =average;
        return average;
    }
};

class College_student : public Student{  // College_Class ( child class of Student )
private:
   // College_Semester semesters[4];
    double average = 0;
    double assignment = 0;
    double tests = 0;
    double exam = 0;
public:

    College_student(string name, string type, string date, string school, string course):Student(name,type,date,school,course) {
        /*
        int average1;
        for( int i=0;i<4;i++){
            average1 += semesters[i].get_average_score();
        }
        average1 = average1/4;
        this->average = average1;   */
    }

    void DoAssignment(){
        srand(time(nullptr));
        this->assignment = rand() % (10-1+1)+1;
    }

    void TakeTest(){
        srand(time(nullptr));
        this->tests = rand() % (10-1+1)+1;
    }

    void TakeExam(){
        srand(time(nullptr));
        this->exam = rand() % (10-1+1)+1;
    }

    double Average(){   // polymorphism
        double average = (this->assignment + this->tests + this->exam)/3;
        this->average = average;
        return average;
    }

};


