// #include<bits/stdc++.h>
// using namespace std;

// struct MinHeapNode{
// 	char data;
// 	int freq;
// 	MinHeapNode* left, *right;
// 	MinHeapNode(char data, int freq){
// 		left=right=nullptr;
// 		this->data = data;
// 		this->freq = freq;
// 	}
// };


// void printCodes(struct MinHeapNode* root, string str){
// 	if(root == nullptr){
// 		return;
// 	}
// 	if(root->data != '$'){
// 		cout << root->data << ": " << str << endl;
// 	}
// 	printCodes(root->left, str + "0");
// 	printCodes(root->right, str + "1");
// }

// struct compare{
// 	bool operator()(MinHeapNode* a, MinHeapNode* b){
// 		return (a->freq > b->freq);
// 	}
// };

// void HuffmanCode(char data[], int freq[], int size){
// 	struct 	MinHeapNode *left, *right, *temp;
	
// 	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	
// 	for(int i = 0; i < size; i++){
// 		minHeap.push(new MinHeapNode(data[i], freq[i]));
// 	}
	
// 	while(minHeap.size() != 1){
// 		left = minHeap.top();
// 		minHeap.pop();
// 		right = minHeap.top();
// 		minHeap.pop();
// 		temp = new MinHeapNode('$', left->freq + right->freq);
// 		temp->left = left;
// 		temp->right = right;
// 		minHeap.push(temp);
// 	}
// 	printCodes(minHeap.top(), "");
// }


// int main(){
// 	char data[] = {'A', 'B', 'C', 'D'};
// 	int freq[] = {23,12,34,10};
// 	HuffmanCode(data, freq, 4);
// 	return 0;
// }

// /*
// Huffman Coding :
// Time complexity: O(nlogn) where n is the number of unique characters.
// If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
// */


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
