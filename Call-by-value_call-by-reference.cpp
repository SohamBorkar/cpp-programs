#include<iostream>
using namespace std;

int sum(int a, int b){
    int c = a + b;
    return c;
}

// This will not swap a and b
void swap(int a, int b){ //temp a b
    int temp = a;        //4   4  5   
    a = b;               //4   5  5
    b = temp;            //4   5  4 
}

// Call by reference using pointers
void swapPointer(int* a, int* b){ //temp a b
    int temp = *a;          //4   4  5   
    *a = *b;               //4   5  5
    *b = temp;            //4   5  4 
}

// Call by reference using C++ reference Variables
// int & 
//  Code below is used for swapping by using reference variables.
void swapReferenceVar(int &a, int &b){ //temp a b
    int temp = a;          //4   4  5   
    a = b;               //4   5  5
    b = temp;            //4   5  4 
    // return a;
}

// Code below is Return by reference:
// int* swapReferenceVar(int &a, int &b){ //temp a b
//     int temp = a;          //4   4  5   
//     a = b;               //4   5  5
//     b = temp;            //4   5  4 
//     return a;
// } 

//  Code below is used when we are not using reference variables and using pointers insted.
// void swapPointer(int* a, int* b){ //temp a b
//     int temp = *a;          //4   4  5   
//     *a = *b;               //4   5  5
//     *b = temp;            //4   5  4 
//     // return temp used if function type was another than void.
// }

int main(){
    int x =4, y=5;
    // cout<<"The sum of 4 and 5 is "<<sum(a, b);
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    // swap(x, y); // This will not swap a and b
    // swapPointer(&x, &y); //This will swap a and b using pointer reference
    swapReferenceVar(x, y); //This will swap a and b using reference variables
    // swapReferenceVar(x, y) = 766; // Return by reference     //This will swap a and b using reference variables
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    return 0;
}
