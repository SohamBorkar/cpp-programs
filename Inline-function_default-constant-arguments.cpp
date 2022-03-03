#include<iostream>
using namespace std;

//  Static variable is the thing that:
//  Below is the code as like for loop, so it runs multiple times, so as like in for loop value of 'c' (c is c++ used in for loop) it remains increasing, as like this, how much time our program runs that much time static holds the value. (value gained before use it again as like for loop)
inline int product(int a, int b){
    // Not recommended to use below lines with inline functions of static variables.
    // static int c=0; // This executes only once
    // c = c + 1; // Next time this function is run, the value of c will be retained (remains as it is)
    return a*b;
}

//  Default Arguments:
float moneyReceived(int currentMoney, float factor=1.04){
    return currentMoney * factor;
}
  
//Constant Arguments: it is like constants as like we use it at starting of coding as pi = 3.14  Here it is work used for variable with scope only upto the function. 
// int strlen(const char *p){

// }
int main(){
    int a, b;
    // cout<<"Enter the value of a and b"<<endl;
    // cin>>a>>b;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    int money = 100000;
    cout<<"If you have "<<money<<" Rs in your bank account, you will recive "<<moneyReceived(money)<< "Rs after 1 year"<<endl;
    cout<<"For VIP: If you have "<<money<<" Rs in your bank account, you will recive "<<moneyReceived(money, 1.1)<< " Rs after 1 year";
    //  In Default Arguments, it take default argument given in default function (as here it is given 'factor=1.04') otherwise it takes argument that we given. (here for VIP it is 1.1)
    return 0;
}