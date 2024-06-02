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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

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


Node *sort2(Node *&head)
{
 
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // Travese the orifginal
    Node *curr = head;

    while (curr != NULL)
    {
        if(curr->data==0){
            //take out the zeiro wali node
            Node*temp =  curr;
            curr= curr->next;
            temp->next= NULL;

            //append it to zero node
            zeroTail->next= temp;
            zeroTail=temp;
        }
         else if(curr->data==1){
             //take out the zeiro wali node
            Node*temp =  curr;
            curr= curr->next;
            temp->next= NULL;

            //append it to zero node
           oneTail->next= temp;
            oneTail=temp;
        }
       else  if(curr->data==2){
             //take out the zeiro wali node
            Node*temp =  curr;
            curr= curr->next;
            temp->next= NULL;

            //append it to zero node
           twoTail->next= temp;
            twoTail=temp;
        }
    }

    //ab yaha par zero one two teelo ready 
    //join krna h 
    //duplicate i.e -1, -1 , -1 remove kr den ah

    //modiyfy oone wai lislt
    Node *temp = oneHead;
    oneHead= oneHead->next;
    temp->next=NULL;
    delete temp;

    //modfiy tewo wali lsit
    temp= twoHead;
     twoHead= twoHead->next;
     temp->next=NULL;
     delete temp;

    // join list

    if(oneHead != NULL){
        zeroTail ->next = oneHead;

        if(twoHead !=NULL){
           oneTail->next= twoHead;
        }
    }
    else{
        if(twoHead !=NULL){
            zeroTail = twoHead;
        }
    }

    //remove zeroHeady dummy ndoe
    temp = zeroHead;
    zeroHead= zeroHead->next;

    temp->next=NULL;
    delete temp;

    return zeroHead;

}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(0);
    Node *fourth = new Node(1);
    Node *fifth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Printing sorted list"<<endl;
    
cout<<"INput LL";
print(head);
   head= sort2(head);
  cout<<"Printing sorted list"<<endl;
    print(head);

    return 0;
}