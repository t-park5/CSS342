#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>
using namespace std;


//Bubble Sort
void BubbleSort(vector<int>& arr, int left, int right) 
{
    for (int i = left; i < right; i++) 
    {
        for (int j = left; j < right - i + left; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
};

//Insertion Sort
void InsertionSort(vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; i++) 
    {
        int value = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > value) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
};

//Merge Sort
void MergeSort(vector<int>& arr, int left, int right) 
{
   
    if (left >= right) return;

  
    int mid = left + (right - left) / 2;

    
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    
    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    
    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }

    
    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }

    
    for (int p = 0; p < k; p++) 
    {
        arr[left + p] = temp[p];
    }
};

//Iterative Merge Sort
void IterativeMergeSort(vector<int>& arr, int left, int right) 
{
    int n = right - left + 1;
    vector<int> temp(n);
    
    
    for (int i = 0; i < n; i++) {
        temp[i] = arr[left + i];
    }
    
   
    for (int size = 1; size < n; size *= 2) 
    {
        for (int leftStart = 0; leftStart < n; leftStart += 2 * size) 
        {
            int mid = min(leftStart + size, n);
            int rightEnd = min(leftStart + 2 * size, n);
            
            
            int i = leftStart, j = mid, k = leftStart;
            
            while (i < mid && j < rightEnd) 
            {
                if (temp[i] <= temp[j]) 
                {
                    arr[left + k] = temp[i];
                    i++;
                } 
                else 
                {
                    arr[left + k] = temp[j];
                    j++;
                }
                k++;
            }
            
            // copy remain
            while (i < mid) 
            {
                arr[left + k] = temp[i];
                i++;
                k++;
            }
            
            while (j < rightEnd) 
            {
                arr[left + k] = temp[j];
                j++;
                k++;
            }
            
            // data exchange between temp and array
            for (int p = leftStart; p < k; p++) 
            {
                temp[p] = arr[left + p];
            }
        }
    }
}

// Quick Sort
void QuickSort(vector<int>& arr, int left, int right) 
{
    if (left >= right) return;

   
    int pivot = arr[right];
    int i = left - 1;

    
    for (int j = left; j < right; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    
    swap(arr[i + 1], arr[right]);
    int pivotIndex = i + 1;

    
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
};

// Shell Sort
void ShellSort(vector<int>& arr, int left, int right) 
{
    int n = right - left + 1;
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = left + gap; i <= right; i++) 
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= left + gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
};



#endif