#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;


struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};


struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (!root) return;

    if (root->data != '\0') {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Huffman Coding function
void huffmanCodes(string characters, int freq[], int size) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    // Create priority queue of nodes
    for (int i = 0; i < size; ++i) {
        pq.push(new Node(characters[i], freq[i]));
    }

    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sumFreq = left->freq + right->freq;
        Node *newNode = new Node('\0', sumFreq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    map<char, string> codes;
    generateCodes(root, "", codes);

    // Print Huffman codes in preorder traversal
    cout << "Huffman codes: " << endl;
    for (auto it = codes.begin(); it != codes.end(); ++it) {
        cout << "  " << it->first << " : " << it->second << endl;
    }
}

int main() {
    string characters = "abcdef";
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    huffmanCodes(characters, freq, size);

    return 0;
}
