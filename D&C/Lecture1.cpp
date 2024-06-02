#include <iostream>

using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // do part me divide krenge
    int len1 = mid - s + 1;

    int len2 = e - mid;

    // assume to create arrays

    int *left = new int[len1];
    int *right = new int[len2];

    // copy values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftindex = 0;
    int rightindex = 0;
    int mainArrayIndex = s;

    while (leftindex < len1 && rightindex < len2)
    {

        if (left[leftindex] < right[rightindex])
        {
            arr[mainArrayIndex] = left[leftindex];
            mainArrayIndex++;
            leftindex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightindex];
            mainArrayIndex++;
            rightindex++;
        }
    }

    // copy logic of left arrya

    while (leftindex < len1)
    {
        arr[mainArrayIndex] = left[leftindex];
        mainArrayIndex++;
        leftindex++;
    }

    while (rightindex < len2)
    {
        arr[mainArrayIndex] = right[rightindex];
        mainArrayIndex++;
        rightindex++;
    }
}
void mergeSort(int *arr, int s, int e)
{

    // base case

    // s==e -> single element
    // s>e inavlid case

    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left part sort krdo recursion bhaiya
    mergeSort(arr, s, mid);

    // right part solve krdo recuriosn bahiye
    mergeSort(arr, mid + 1, e);

    // now merge two sorted arrya

    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;

    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}