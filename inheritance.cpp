#include <iostream>
#include <string>
using namespace std;

class Person
{   
    public:
        string name;
        int age;

        Person()
        {
            cout<<"Person constructor called" << endl;
        }

        ~Person(){
            cout << "Person destructor called" << endl;
        }
};

class Student : public Person
{
    public:
        int roll;

        // manually calling the base class constructor, it can be called automatically also.
        Student(string name, int age, int roll) : Person(string name, int age)
        {
            cout<<"Student constructor called" << endl;
            this -> name = name;
            this -> age = age;
            this -> roll = roll;
        }        

        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Roll: " << roll << endl;
        }

        ~Student(){
            cout << "Student destructor called" << endl;
        }
};

int main()
{
    Student soham;
    soham.name = "Soham";
    soham.age = 20;
    soham.roll = 36;
    soham.display();
    return 0;
}

/*
Base class constructor is called first and then derived class constructor is called.
*/