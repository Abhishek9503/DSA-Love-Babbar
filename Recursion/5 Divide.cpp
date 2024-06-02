// in this file code for merge sort and binary search using recusrion is present

#include <iostream>

using namespace std;

void merge(int arr[], int s, int mid, int e)
{

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int i = 0;
    for (int index = s; index <= mid; index++)
    {
        first[i] = arr[index];
        i++;
    }
    int j = 0;
    for (int index = mid + 1; index <= e; index++)
    {
        second[j] = arr[index];
        j++;
    }

    // merge these 2 array into the orginal array

    int originalArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {

        if (first[index1] < second[index2])
        {

            arr[originalArrayIndex] = first[index1];
            index1++;
            originalArrayIndex++;
        }
        else
        {
            arr[originalArrayIndex] = second[index2];
            index2++;
            originalArrayIndex++;
        }
    }

    while (index1 < len1)
    {
        arr[originalArrayIndex] = first[index1];
        index1++;
        originalArrayIndex++;
    }

    while (index2 < len2)
    {
        arr[originalArrayIndex] = second[index2];
        index2++;
        originalArrayIndex++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // left part

    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}

// binary search

bool binarySearch(int *arr, int s, int e, int target)
{
    if (s > e)
    {
        return false;
    }

    int mid = s + (e - s) / 2;

    if (target == arr[mid])
    {
        return true;
    }

    else if (target < arr[mid])
    {
        return binarySearch(arr, s, mid - 1, target);
    }
    else
    {
        return binarySearch(arr, mid, e, target);
    }
}

int main()
{
    // int arr[] = {3, 4, 1, 5, 6, 2, 7};
    // int size = 7;

    // mergeSort(arr, 0, size - 1);

    // cout << "Printing the sorted array using mege sort : " << endl;

    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int arr[] = {3, 6, 9, 12, 15, 17, 19};
    int size = 7;

    cout << "Ans is " << binarySearch(arr, 0, size - 1, 2) << endl;
    return 0;
}
