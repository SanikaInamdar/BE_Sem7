
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Node structure for Huffman Tree
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison struct for priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Function to build Huffman Tree
HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare>& minHeap) {
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Function to generate Huffman codes and print the codes
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to perform Huffman Encoding
string huffmanEncode(string input) {
    unordered_map<char, unsigned> frequencyMap;
    for (char ch : input) {
        frequencyMap[ch]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;
    for (auto& pair : frequencyMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    HuffmanNode* root = buildHuffmanTree(minHeap);

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    string encoded = "";
    for (char ch : input) {
        encoded += huffmanCodes[ch];
    }

    return encoded;
}

int main() {
    string input;
    cout << "Enter the input string: ";
    getline(cin, input);

    string encoded = huffmanEncode(input);

    cout << "Huffman Encoded Data: " << encoded << endl;

    return 0;
}
