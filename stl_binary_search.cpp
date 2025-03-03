#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // time compleixty of the binary_search is O(logn) and it is applicable only on sorted containers
    // O(logn) is the time complexity for the lower_bound and upper_bound as well

    // binary_search returns a boolean value
    cout << binary_search(v.begin(), v.end(), 5) << endl;
    bool found = binary_search(v.begin(), v.end(), 10);
    cout << found << endl;
    cout << endl;

    // lower_bound returns an iterator to the first element that found or immediate greater than the value
    auto it = lower_bound(v.begin(), v.end(), 5) - 1;
    cout << *it << endl;

    auto it2 = lower_bound(v.begin(), v.end(), 10);
    // cout << *it2 << endl;
    if(it2 == v.end()){
        cout << "Not found" << endl;
    }   
    int i = lower_bound(v.begin(), v.end(), 5) - v.begin();
    cout << i << endl;
    cout << lower_bound(v.begin(), v.end(), 10) - v.begin() << endl;
    if(lower_bound(v.begin(), v.end(), 10) == v.end()){
        cout << "Not found" << endl;
    }
    cout << endl;

    // upper_bound returns an iterator to the first element that is greater than the value
    auto it3 = upper_bound(v.begin(), v.end(), 5);
    cout << *it3 << endl;
    auto it4 = upper_bound(v.begin(), v.end(), 10);
    if(it4 == v.end()){
        cout << "Not found" << endl;
    }
    cout << endl;

    cout << "Now lower_bound and upper_bound questions" << endl;
    cout << endl;

    int tofind = 4;

    // Q. Find the first occurrence of sorted array. If it does not exists in the array then print -1.
    int ind = lower_bound(v.begin(), v.end(), tofind) - v.begin();
    cout << "ind of lower_bound is: " << ind << endl;
    if(ind != v.size() && v[ind] == tofind){
        cout << ind << endl;
    }
    else{
        cout << -1 << endl;
    }
    cout << endl;

    // Q. Find the last occurrence of an element in the sorted array. If it does not exists in the array then print -1.
    int ind2 = upper_bound(v.begin(), v.end(), tofind) - v.begin() - 1;
    // we are substracting 1 because upper_bound returns the first element that is always 1 greater than the value
    cout << "ind of upper_bound is: " << ind2 << endl;
    if(ind2 >= v.size() && v[ind2] == tofind){
        cout << ind2 << endl;
    }
    else{
        cout << -1 << endl;
    }
    cout << endl;

    // Q. Find the largest number smaller than X in a sorted array. If no number exists print —1.
    int ind3 = lower_bound(v.begin(), v.end(), tofind) - v.begin() - 1;
    cout << "ind of lower_bound is: " << ind3 << endl;
    if(ind3 >= 0){
        cout << v[ind3] << endl;
    }
    else{
        cout << -1 << endl;
    }
    cout << endl;   

    // Q. Find the smallest number greater than X in a sorted array. If no number exists print —1.
    int ind4 = upper_bound(v.begin(), v.end(), tofind) - v.begin();
    cout << "ind of upper_bound is: " << ind4 << endl;
    if(ind4 < v.size()){
        cout << v[ind4] << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}