// Recusion using linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node with value:" << this->data << "deleted" << endl;
    }
};

void printLL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << ",  ";

    printLL(head->next);

    // cout << head->data << ",  ";
}

void printKthLast(Node *head, int &k)
{
    if (head == NULL)
    {
        return;
    }

    // cout << head->data << " , ";

    printKthLast(head->next, k);

    k--;
    if (k == 0)
    {
        cout << "Kth node from end " << head->data << endl;
    }
}

Node *reverse(Node *&first)
{

    // base case
    if (first == NULL || first->next == NULL)
    {
        return first;
    }

    cout << "Inside reverse  "
         << ",";

    Node *chotaHead = reverse(first->next);
    first->next->next = first;
    first->next = NULL;

    return chotaHead;
}

Node *reverseIterator(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node *ReverseKthNode(Node *head, int k)
{

    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *forward;

    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // check next is not null

    if (forward != NULL)
    {
        head->next = ReverseKthNode(forward, k);
    }

    return prev;
}

int main()
{

    Node *first = new Node(11);
    Node *second = new Node(12);
    Node *third = new Node(13);
    Node *fourth = new Node(14);
    Node *fifth = new Node(15);
    Node *sixth = new Node(22);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    // printLL(first);

    // printLL(first);

    // cout << endl;
    // int k = 3;
    // printKthLast(first, k);
    // first = reverse(first);
    // printLL(first);

    // first = reverseIterator(first);
    // printLL(first);

    printLL(first);
    cout << endl
         << " ";
    first = ReverseKthNode(first, 3);
    printLL(first);
    cout << endl;
    return 0;
}