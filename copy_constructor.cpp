#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string name;
        int roll;
        bool male;
    
    public:
        // Paramaterized Constructor declearation
        Student(string name, int roll, bool male){
            this->name = name;
            this->roll = roll;
            this->male = male;
        }

        // Copy constructor decleration
        // Do not forgot to make it constant using const keyword as it will prevent modifications to the object being copied
        Student(const Student &s){
            this->name = s.name;
            this->roll = s.roll;
            this->male = s.male;
            // OR
            // name = s.name;
            // roll = s.roll;
            // male = s.male;
        }

        void display_detials(){
            cout << "Name: " << name << endl;
            cout << "Roll: " << roll << endl;
            cout << "Male: " << male << endl;
        }
};

int main(){
    string name = "Soham";
    int roll = 36;
    bool male = true;

    Student s1(name, roll, male);
    s1.display_detials();

    Student s2 = s1;
    s2.display_detials();
    return 0;
}