#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
 
// Build tree from level-order input, -1 = no child
Node* buildTree() {
    int rootVal;
    cout << "Enter root value: ";
    cin >> rootVal;
    if (rootVal == -1) return nullptr;
 
    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        int leftVal, rightVal;
 
        cout << "Enter left child of " << curr->val << " (-1 if none): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
 
        cout << "Enter right child of " << curr->val << " (-1 if none): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}
 
void preorder(Node* r)  { if (!r) return; cout << r->val << " "; preorder(r->left);  preorder(r->right); }
void inorder(Node* r)   { if (!r) return; inorder(r->left);   cout << r->val << " "; inorder(r->right); }
void postorder(Node* r) { if (!r) return; postorder(r->left); postorder(r->right); cout << r->val << " "; }
 
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); q.pop();
