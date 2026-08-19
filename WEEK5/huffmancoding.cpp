#include <iostream>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};
Node* createNode(char ch, int freq) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void printCodes(Node* root, string code) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    char ch[20];
    int freq[20];
    for (int i = 0; i < n; i++) {
        cout << "Enter character and frequency: ";
        cin >> ch[i] >> freq[i];
    }
    Node* nodes[20];
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(ch[i], freq[i]);
    int count = n;
    while (count > 1) {
        int first = 0, second = 1;
        if (nodes[first]->freq > nodes[second]->freq)
            swap(first, second);
        for (int i = 2; i < count; i++) {
            if (nodes[i]->freq < nodes[first]->freq) {
                second = first;
                first = i;
            }
            else if (nodes[i]->freq < nodes[second]->freq) {
                second = i;
            }
        }
        Node* parent = createNode('$',
            nodes[first]->freq + nodes[second]->freq);
        parent->left = nodes[first];
        parent->right = nodes[second];
        if (first > second)
            swap(first, second);
        nodes[first] = parent;
        for (int i = second; i < count - 1; i++)
            nodes[i] = nodes[i + 1];
        count--;
    }
    cout << "\nHuffman Codes:\n";
    printCodes(nodes[0], "");
    int totalCharacters = 0;
    for (int i = 0; i < n; i++)
        totalCharacters += freq[i];
    int bitsPerCharacter = 0;
    int temp = n - 1;
    while (temp > 0) {
        bitsPerCharacter++;
        temp /= 2;
    }
    int originalBits = totalCharacters * bitsPerCharacter;
    int compressedBits = 0;
    for (int i = 0; i < n; i++) {
        string code = "";
        Node* current = nodes[0];
        while (current->left != NULL || current->right != NULL) {
            if (current->left != NULL &&
                current->left->ch == ch[i]) {
                code += "0";
                current = current->left;
                break;
            }
            if (current->right != NULL &&
                current->right->ch == ch[i]) {
                code += "1";
                current = current->right;
                break;
            }
            if (current->left != NULL)
                current = current->left;
            else
                current = current->right;
        }
        compressedBits += freq[i] * code.length();
    }
    cout << "\nOriginal bits: " << originalBits;
    cout << "\nCompressed bits: " << compressedBits;
    cout << "\nBits saved: " << originalBits - compressedBits;
    return 0;
}
