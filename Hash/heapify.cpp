#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
};

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{

    int index = n;

    while (n != 1)
    {
        swap(arr[1], arr[index]);
        index--;
        n--;
        heapify(arr, n, 1);
    }
}
int main()
{

    int arr[] = {-1,
                 12,
                 15,
                 13,
                 11,
                 14};
    int n = 6;
    buildHeap(arr, n);

    cout << "Printing the heap" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing the heap Sort" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "HEllo WOrld";
    return 0;
}