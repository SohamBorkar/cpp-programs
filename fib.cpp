#include <iostream>
#include <cmath>
using namespace std;

int fib(long n){
    return pow((1+sqrt(5))/2,n)/sqrt(5) + 1e-9;
};

int main(int argc, char const *argv[])
{
    long n = 50;
    cout << fib(n);
    return 0;
}

