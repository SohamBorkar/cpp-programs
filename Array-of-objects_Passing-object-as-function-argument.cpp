#include<iostream>
using namespace std;

class complex{
    int a;
    int b;

    public: 
         void setData(int v1, int v2){
            a = v1;
            b = v2;
                // Here value of a and b is set as v1 and v2
        }

        void setDataBySum(complex o1, complex o2){
            a = o1.a + o2.a;
            b = o1.b + o2.b;
                    // Here value of a becomes addition of c1's a and c2's a i.e. 2 + 4 and
                    // value of b becomes addition of c1's b and c2's b i.e. 1 + 3
        }

        void printNumber(){
            cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

int main(){
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    c3.setDataBySum(c1, c2);
    c3.printNumber();
    return 0;
}


// #include <iostream>
// using namespace std;

// class Employee
// {
//     int id;
//     int salary;

// public:
//     void setId(void)
//     {
//         salary = 122;
//         cout << "Enter the id of employee" << endl;
//         cin >> id;
//     }

//     void getId(void)
//     {
//         cout << "The id of this employee is " << id << endl;
//     }
// };

// int main()
// {
//     // Employee harry, rohan, lovish, shruti;
//     // harry.setId();
//     // harry.getId();
//     Employee fb[4];
//     for (int i = 0; i < 4; i++)
//     {
//         fb[i].setId();
//         fb[i].getId();
//     }

//     return 0;
// }
