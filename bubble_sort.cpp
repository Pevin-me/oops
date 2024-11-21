1. Write a C++ program to implement the Bubble Sort algorithm. Include 
functionality to print the array before and after sorting. 
Code: 
#include <iostream> 
using namespace std; 
int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    cout << "Array before sorting: "; 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j + 1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
    cout << "Array after sorting: "; 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
    return 0; 
} 
