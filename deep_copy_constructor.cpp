#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        
    public:
        string name;
        double* cgpaPtr;
        // double * cgpaPtr = new double;

        Student(string name, double cgpa){
            this -> name = name;
            cgpaPtr = new double;
            *cgpaPtr = cgpa;
            // this -> cgpaPtr = new double;
        }

        // copy constructor edited from shallow copy constructor
        Student(Student &s){
            name = s.name;
            cgpaPtr = new double;   // creating new memory location for cgpaPtr
            *cgpaPtr = *s.cgpaPtr;
        }

        void print_info(){
            cout << "Name: " << name << endl;
            cout << "CGPA: " << *cgpaPtr << endl;   // * to print the value itself
        }

        // destructor
        ~Student(){
            delete cgpaPtr;
            cout << "Destructor called" << endl;
        }
};

int main(){
    string name = "Soham";
    double cgpa = 8.64;

    Student soham(name, cgpa);
    soham.print_info();

    Student pratik(soham);
    pratik.name = "Pratik";
    *pratik.cgpaPtr = 9.0;
    pratik.print_info();

    soham.print_info();
    return 0;
}