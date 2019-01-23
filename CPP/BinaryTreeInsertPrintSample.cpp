#include <iostream>
#include <queue>
using namespace std;

// node declaration
struct Node
{
    Node *left, *right;
    int data;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

int treeHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = treeHeight(root->left) + 1;
    int right = treeHeight(root->right) + 1;

    return max(left, right);
}

void printTreeLevelWise(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int countNode = q.size();
        while (countNode > 0)
        {
            Node *n = q.front();
            cout << n->data << " ";
            q.pop();

            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);

            countNode--;
        }
        cout << endl;
    }
}

// print (-> inorder traversal)
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// insert
Node *insert(Node *root, int newData)
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
            root = insert(root, a);
        else
            insert(root, a);
    }
    cout << "Inorder:: ";
    inorder(root);
    cout << "\n";
    cout << root->right->data << "\n";
    // cout << "Height == " << treeHeight(root) << " ";
    cout << "Level wise traversal:: ";
    printTreeLevelWise(root);
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