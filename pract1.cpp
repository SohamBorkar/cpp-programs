#include <iostream>
using namespace std;    

// Function to merge two sorted arrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;

    // Compare elements from left and right arrays and store in the original array
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    // Add remaining elements from left array
    while (i < leftSize)
    {
        arr[k++] = left[i++];
    }

    // Add remaining elements from right array
    while (j < rightSize)
    {
        arr[k++] = right[j++];
    }
}

// Function to divide the array into two parts
void mergeSort(int arr[], int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Copy elements to left and right arrays
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // Recursively sort left and right arrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge left and right arrays back into original array
    merge(arr, left, mid, right, size - mid);
}

int main()
{
    // Get user input
    int size;
    cout << {"index":0,"invalid_reason":"Malformed citation << \"Enter the number of elements: \";\n    cin >>"}; size;

    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Sort the array using merge sort
    mergeSort(arr, size);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}