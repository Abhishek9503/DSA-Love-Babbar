#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    // step1: choose pivot index

    int pivotIndex = s;
    int pivotElement = arr[s];

    // step 2 : Find right position for pivot element

    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }
    // jab me loop se bhr aya to mere pas pivot ki right positon ka indexa ready

    int rightIndex = s + count;

    swap(arr[pivotIndex], arr[rightIndex]);

    pivotIndex = rightIndex;

    // step3  left me chote and right me bd index krne

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }

        while (arr[j] > pivotElement)
        {
            j--;
        }

        // ab yha par 2 case ho skte h ->
        // A-> you found  the element to swap
        // B-> no need to swap

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partition logic, return pivot index
    int p = partition(arr, s, e);

    // recursive call

    // pivot element ->left
    quickSort(arr, s, p - 1);

    // ivot element ->right
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 3, 6, 3, 8, 9, 2, 4, 20, 50, 30};
    int n = 12;

    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}