#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step A B and C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << "node" << endl;

    root->left = buildTree();

    cout << "Enter data for right part of " << data << "node" << endl;

    root->right = buildTree();

    return root;
}

void printTopView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // create map for storing HD ->topnode ->data
    map<int, int> topNode;

    // levelorder
    // we will start with a pair consisteing of Node and horizonatl dis

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance h uski value phle se h ki nhi map me

        if (topNode.find(hd) == topNode.end())
        {
            // create kr denge kyuki end tak agay nh mili
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    // ab apka answer pada hoga map me
    cout << "Printing the answer " << endl;

    for (auto it : topNode)
    {
        cout << it.first <<"-->"<<it.second <<endl;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;

    return 0;
}