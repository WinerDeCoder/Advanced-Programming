#include <iostream>
#include <string>
#include <array>
using namespace  std;

class Manager{
public:
    void add_name(string list[],string name,int *count){
        list[*count] = name;
        (*count)++;
        cout<<name<<" has been added to the list."<<endl;
    }

    void show(string list[],int count){
        for(int i=0;i<count;i++){
            cout<<"Student "<<i+1<<":"<<list[i]<<endl;
        }
    }

    void delete_name(string list[],string name,int *count){
        for(int i=0;i<= *count;i++){
            if(list[i] == name){
                for(int j = i;j < *count;j++){
                    list[j] = list[j+1];
                }
                (*count)--;
                cout<<name<<" has been removed from the list."<<endl;
                return;
            }
        }
        cout<<"This name doesn't exist in the list"<<endl;
    }
};
