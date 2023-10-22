#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>a, int k) {
    int n = a.size();

    k=k%n;

    vector<int>l;

    for(int i=0;i<n-k;i++)

    {
        l.push_back(a[k+i]);
    }

    for(int i=0;i<k;i++)

    {
        l.push_back(a[i]);
    }

    return l;         
}

int main(){
    vector<int> a={1,2,3,4,5};
    cout << rotateArray(a,2)<<endl;
    return 0;
}