#include <iostream>
#include <queue>
#include <omp.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);

#pragma omp parallel sections
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        cout << node->data << " ";

#pragma omp section
        if (node->left != nullptr)
        {
            q.push(node->left);
        }

#pragma omp section
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }
}

void dfs(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";

#pragma omp parallel sections
    {
        # pragma omp section
        dfs(root->left);

        # pragma omp setion
        dfs(root->right);
    }
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "BFS: ";
    bfs(root);
    cout << endl;

    cout << "DFS: ";
    dfs(root);
    cout << endl;

    return 0;
}