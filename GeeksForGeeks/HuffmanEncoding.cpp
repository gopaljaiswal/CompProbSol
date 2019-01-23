#include "limits.h"
#include "unordered_map"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MAX 26

using namespace std;

struct Node
{
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
    Node(char data, int freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

struct compare
{
    bool operator()(Node *left, Node *right) { return left->freq > right->freq; }
};

void printHuffman(Node *root, string s)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
    {
        // cout << root->data << " " << s << "\n";
        cout << s << " ";
    }
    printHuffman(root->left, s + "0");
    printHuffman(root->right, s + "1");
}

void prepareHuffmanEncoding(string data, int freq[], int size)
{
    Node *left, *right, *top;
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printHuffman(minHeap.top(), "");
}

void solve()
{

    int T;
    cin >> T;
    while (T--)
    {
        string arr;
        cin >> arr;
        int size = arr.length();
        int freq[size];
        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            freq[i] = a;
        }
        prepareHuffmanEncoding(arr, freq, size);
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
