#include <iostream>

using namespace std;

// node declaration
struct Node
{
    Node *left, *right;
    int data;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// print (-> inorder traversal)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// insert

Node *
insert(Node *root, int newData)
{

    if (root == NULL)
    {
        Node *newNode = new Node(newData);
        return newNode;
    }
    if (newData < root->data)
    {
        root->left = insert(root->left, newData);
    }
    else
    {
        root->right = insert(root->right, newData);
    }
    return root;
}

// input
void solve()
{

    int N;
    cin >> N;
    struct Node *root = NULL;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            root = insert(root, a);
        }
        else
        {
            insert(root, a);
        }
    }
    inorder(root);
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "input.txt",
            "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "output.txt",
            "w", stdout);

    solve();
    return 0;
}