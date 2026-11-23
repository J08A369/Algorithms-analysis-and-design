#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int main()
{
    Node *root = new Node;
    Node *left = new Node;
    Node *right = new Node;

    root->data = 10;
    root->left = left;
    root->right = right;

    left->data = 20;
    left->left = NULL;
    left->right = NULL;

    right->data = 30;
    right->left = NULL;
    right->right = NULL;

    cout << "Root Node: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data;

    return 0;
}
