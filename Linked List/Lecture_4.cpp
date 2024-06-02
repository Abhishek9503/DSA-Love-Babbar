#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;

    Node(int data)
    {

        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrone(Node*&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return true;
    }

    

    if (head->next == NULL)
    {
        // only 1
        return true;
    }

    // step A find middle node
    Node *slow = head;
    Node *fast = head->next;

    while (fast!= NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // Slow pointer is pointing to the middle node

    // Step2 reverse linkedlist after middle node

    Node *reverseLinkedlist = reverse(slow->next);
    slow->next = reverseLinkedlist;

    // Step 3 Start comparison

    Node *temp1 = head;
    Node *temp2 = reverseLinkedlist;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(10);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    bool isPalindrone = checkPalindrone(head);

    if (isPalindrone)
    {
        cout << "LINkedin list palindrome";
    }
    else
    {
        cout << "NOt plaindrome";
    }

    return 0;
}