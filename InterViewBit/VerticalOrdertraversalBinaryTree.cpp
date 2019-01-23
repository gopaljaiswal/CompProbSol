#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// print inorder
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// print LevelWise Traversal
vector<vector<int>> printLevelWisetreeTrversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    map<int, vector<int>> map;
    int leftMost = INT_MAX;
    int rightMost = INT_MIN;

    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        int hd = front.second;
        Node *n = front.first;

        if (map.count(hd))
        {
            vector<int> tmp = map[hd];
            tmp.push_back(n->data);
            map[hd] = tmp;
        }
        else
        {
            vector<int> tmp;
            tmp.push_back(n->data);
            map[hd] = tmp;
        }

        q.pop();

        if (n->left != NULL)
        {
            q.push(make_pair(n->left, hd - 1));
        }

        if (n->right != NULL)
        {

            q.push(make_pair(n->right, hd + 1));
        }
    }

    // cout << leftMost << "  " << rightMost << "\n";

    for (auto const &pair : map)
    {
        // cout << pair.first << " :: ";
        vector<int> vc;
        for (int i = 0; i < pair.second.size(); i++)
        {
            vc.push_back(pair.second[i]);
            // cout << pair.second[i] << " ";
        }
        ans.push_back(vc);
        // cout << "\n";
    }

    return ans;
}

// insert
Node *insert(Node *root, int newData)
{
    if (root == NULL)
        return new Node(newData);

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
    // cout << "Inorder:: ";
    // inorder(root);
    cout << "\n";
    vector<vector<int>> ans = printLevelWisetreeTrversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
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
