#include <iostream>
// #include <Heap>

using namespace std;

class Heap
{
public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {

        // value insert kro end me

        size = size + 1;
        int index = size;
        arr[index] = value;

        // is value to shi position pe lagana padega

        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // int delete()
    // {
    //     int ans=arr[1];
    //     // replace root node valuye with last node data
    //     arr[1] = arr[size];
    //     size--;

    //     // palce root node ka data on its correct position
    //     int index = 1;
    //     while (index < size)
    //     {
    //         int left = 2 * index;
    //         int right = 2 * index + 1;

    //         int largest = index;

    //         if (left < size && arr[largest] < arr[left])
    //         {
    //             largest = left;
    //         }

    //         if (right < size && arr[largest] < arr[right])
    //         {
    //             largest = right;
    //         }

    //         if (largest == index)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             swap(arr[index], arr[largest]);
    //             index = largest;
    //         }
    //     }
    //     return ans;
    // }



    
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    h.insert(110);
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}