#include <iostream>

using namespace std;

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
};

void choosecond(int i, int * arr, int size, int pivot, int second){
    while (arr[i] < size)
    {
        if (arr[i] > pivot)
        {
            second = arr[i];
            break;
        }
    }
};

void mergesort(int *arr, int first, int size){
    int pivot = arr[size];
    int second;
    int temp;
    //cout << pivot;
    
    // while (second < size)
    // {
    //     if (arr[second] > pivot)
    //     {
    //         second = arr[second];
    //         break;
    //     }
    //     second++;
    // }

    // 8, 7, 6, 1, 0, 9, 2

    for (int i = 0; i <= size; i++)
    {
        // if(arr[i] > pivot){
        //     second = arr[i];
        //     continue;
        // }

        choosecond(i, arr, size, pivot, second);

        if(arr[i] < pivot)
        {
            temp = arr[i];
            arr[i] = second;
            second = temp;
        }
    }
    
};

int main(){
    int arr[] = {8,7,6,1,0,9,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    //cout << size << endl;
    printArray(arr, size);

    mergesort(arr, 0, size - 1);

    printArray(arr, size);
    return 0;
}