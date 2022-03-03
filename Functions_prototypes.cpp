#include<iostream>
using namespace std;

//  Function prototype gives assurity(not guarrenty) to the main function that the xyz  function is available in the program.(It may be written below the main function)

// Functions : Main part of Top down structured programming.
// Function prototype : Is running the function rather than main if it is written below the main function.
// type function-name (arguments);
// int sum(int a, int b); //--> Acceptable
// int sum(int a, b); //--> Not Acceptable 
int sum(int, int); //--> Acceptable 
// void g(void); //--> Acceptable 
void g(); //--> Acceptable 

int main(){
    int num1, num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    // num1 and num2 are actual parameters
    cout<<"The sum is "<<sum(num1, num2);
    g();
    return 0;
}

// Actual parameters is value that we pass to the function.
//Note: Here name of actual parameters and formal parameters may be same as like a and b for both actual parameter and formal parameter, but for simplicity sake it is not given.
int sum(int a, int b){
    //Formal parameters are variables of function and Actual parameters are original value of formal parameters
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
    // parameters to which we given value is called formal parameters.
    int c = a+b;
    return c;
}

void g(){
    cout<<"\nHello, Good Morning";
}
