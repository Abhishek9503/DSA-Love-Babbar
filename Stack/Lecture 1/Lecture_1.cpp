// #include <iostream>
// #include <stack>
// using namespace std;

// // int main()
// // {

// //     // creation
// //     stack<int> st;

// //     // insertion
// //     st.push(10);
// //     st.push(15);
// //     st.push(12);
// //     st.push(11);

// //     // st.pop();

// //     // // remove

// //     // cout << "Elements on the top is " << st.top() << endl;

// //     // // size
// //     // cout << "Size of the stack is:" << st.size() << st.size() << endl;

// //     // if (st.empty())
// //     //     cout << "Stack is empty" << endl;

// //     // else
// //     //     cout << "Stack is notempty" << endl;

// //     while (!st.empty())
// //     {
// //         cout << st.top() << " ";
// //         st.pop();
// //     }
// //     cout << endl;
// //     return 0;

// // }

// class Stack
// {

// public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size)
//     {
//         arr = new int[size];
//         this->size = size;
//         top = -1;
//     }

//     void push(int data)
//     {
//         if (size - top > 1)
//         {
//             // space availabel
//             top++;
//             arr[top] = data;
//         }
//         else
//         {
//             // space not avaible
//             cout << "Stack Overflow" << endl;
//         }
//     }

//     void pop()
//     {

//         if (top == -1)
//         {
//             // Stack is empty
//             cout << "Stack underflow, can delete element" << endl;
//         }
//         else
//         {

//             top--;
//         }
//     }

//     int getTop()
//     {
//         if (top == -1)
//         {
//             cout << "There is not element in stack" << endl;
//         }

//         return arr[top];
//     }
//     int getSize()
//     {
//         return top + 1;
//     }

//     bool isEmpty()
//     {
//         if (top == -1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

// int main()
// {
//     // cout << "Hello World!" << endl;

//     Stack s(10);

//     // insertion
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);

//     while (!s.isEmpty())
//     {
//         cout << s.getTop() << " ";
//         s.pop();
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // functions

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            // space avaialbe
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Underflow condition in the  stack 1" << endl;
        }
        else
        {
            top1--;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Underflow condition in the  stack" << endl;
        }
        else
        {
            top2++;
        }
    }

    void print()
    {

        cout << "Top1  " << top1 << endl;
        cout << "Top2  " << top2 << endl;
        for (int i = 0 ; i < size; i++)
        {
            cout << arr[i] << " ";
            // cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();

    s.push1(20);
    s.print();

    s.push1(30);
    s.print();

    s.push1(40);
    s.print();

    s.push1(50);
    s.print();

    //

    s.push2(100);
    s.print();

    s.push2(110);
    s.print();

    s.push2(120);
    s.print();

    return 0;
}