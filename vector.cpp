#include<iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> arr = {1,2,3,4};
    
    cout<<" Size of array is:  "<<arr.size() <<endl;
    cout<<" Capacity of array is: "<<arr.capacity()<<endl;

    arr.push_back(5);
    cout<<" Capacity of array is: "<<arr.capacity()<<endl;

    for (int i = 0; i < arr.size(); i++)
        cout<<" "<<arr[i]<<" ";
    cout<<endl;

    arr.pop_back();
    for (int i = 0; i < arr.size(); i++)
        cout<<" "<<arr[i]<<" ";

    cout<<endl;
       
    // fill constructor:
    vector<int> arrr(10, 7);    // array of 10 element having same element as 7 in whole array

    // printing vector array using for each loop:
    for(int x: arrr)
        cout<< x <<", ";

    // 2D Vector:

    vector< vector<int> > aarr = {
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12} };
    
    aarr[0][0] += 10;   // incrementing by 10

    // printing 2d vector using for each loop
    for (int i = 0; i < aarr.size(); i++)
    {
        for (int number:aarr[i])
            cout << number<< ", ";
        cout << endl;        
    }
    

    return 0;
}



// Sort an array containing N integers:
// sort(arr, arr +n)

// Sort an vector containing N integers:
// sort(arr.begin(), arr.end())


/*Some problems may require the use of a sorting algorithm, and I hope you are already familiar with basic sorting algorithms like Bubble Sort, Selection Sort, Insertion Sort which have O(n^2) complexity. Better algorithms include Merge Sort, Quick Sort and Heap Sort which have O(nLogn) complexity.

For most array problems we can use the inbuilt sort function which also offers O(nlogn) complexity. This is how you can use the inbuilt sort function in case you are not aware of. Also depending upon the data in the problem, you may also require Counting Sort, or Bucket Sort or Radix Sort sometimes.  We will discuss more problems in Sorting & Searching section.*/