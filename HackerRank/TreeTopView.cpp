#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

void iorder(Node *root)
{
    if (root == NULL)
        return;
    iorder(root->left);
    cout << root->data << " ";
    iorder(root->right);
}

void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, vector<int>> map;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        Node *n = front.first;
        int hd = front.second;
        q.pop();

        if (map.count(hd))
        {
            vector<int> vc = map[hd];
            vc.push_back(n->data);
            map[hd] = vc;
        }
        else
        {
            vector<int> vc;
            vc.push_back(n->data);
            map[hd] = vc;
        }
        if (n->left != NULL)
            q.push(make_pair(n->left, hd - 1));
        if (n->right != NULL)
            q.push(make_pair(n->right, hd + 1));
    }

    for (auto const &pair : map)
    {
        vector<int> v = pair.second;
        cout << v[0] << " ";
    }
}

Node *insert(Node *root, int a)
{
    if (root == NULL)
        return new Node(a);

    if (a < root->data)
        root->left = insert(root->left, a);
    else
        root->right = insert(root->right, a);

    return root;
}

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
    // iorder(root);
    cout << "\n";
    topView(root);
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