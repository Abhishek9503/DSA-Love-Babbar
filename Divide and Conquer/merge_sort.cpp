#include <iostream>
using namespace std;

void jod_Do(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Assuem krke chalo ki 2 array create kre len1 and len2 lwngth k

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

    // merge ka logic lilkh dnege ab

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }

        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    while (leftIndex < len1)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    while (rightIndex < len2)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // todo delete left and right wla newly creaeted array
}

void mergerSort(int *arr, int s, int e)
{
    // base case
    if (s == e)
        return;
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // left part sort krado recursion bahiyua
    mergerSort(arr, s, mid);

    // right part solve krdo recursion bhaiya
    mergerSort(arr, mid + 1, e);

    // now merge two sorted array

    jod_Do(arr, s, e);
}

int main()
{
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;

    int s = 0;
    int e = n - 1;
    mergerSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}