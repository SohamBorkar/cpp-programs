#include<iostream>
using namespace std;

int brutforce(int n){
    int cnt = 0;
    // while bits are present in the input, loops goes through 
    while (n > 0)
    {
        if(n & 1 == 1) cnt++; // doing '&' between 'n' and '1' to check last bit is set or not, 
                              //if yes then cnt will be increased
        n >>= 1;    // Removing the last bit from the n by right shifting means division by two.
    }
    return cnt;
}

int brian_kaningham(int n){
    int cnt = 0;
    while(n > 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    int n = 84;

    cout<< brutforce(n) << endl;

    cout << brian_kaningham(n) << endl;    
    
    // built in function for counting number of set bits in the number
    cout << __builtin_popcount(n) << endl;  
    
    return 0;
}