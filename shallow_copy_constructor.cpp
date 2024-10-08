#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        
    public:
        string name;
        // double* cgpaPtr;
        double * cgpaPtr = new double;

        Student(string name, double cgpa){
            this -> name = name;
            *cgpaPtr = cgpa;
            // this -> cgpaPtr = new double;
        }

        // copy constructor
        Student(Student &s){
            name = s.name;
            cgpaPtr = s.cgpaPtr;
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
    *pratik.cgpaPtr = 9.0;
    pratik.print_info();

    soham.print_info();
    return 0;
}


/*
output will be:

Name: Soham
CGPA: 8.64
Name: Soham
CGPA: 9
Name: Soham
CGPA: 9

So you can see that we have stored the address in the pointer and as we changed the value of the cgpaPtr for pratik object, the value of cgpaPtr for soham object also changed. This is because we have stored the address in the pointer and not the value itself. So this problem we face wehn we do the shallow copy. 
Note: if you don't explicitly define a copy constructor, the compiler will provide a default copy constructor which will do the shallow copy.
You have to define deep copy constructor manually to overcome problem of shallow copy constructor.
*/