
// C++(STL) program for Huffman Coding with STL
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// A Huffman tree node
class MinHeapNode
{
public:
	// One of the input characters
	char data;
	// Frequency of the character
	int freq;
	// Left child
	MinHeapNode *left;
	// Right child
	MinHeapNode *right;

	MinHeapNode(char data, int freq)
	{
		left=NULL;
		right=NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of two heap nodes (needed in min heap)
class compare
{
public:
	bool operator()(MinHeapNode *l, MinHeapNode *r)
	{
		return (l->freq > r->freq);
	}
};

// Prints Huffman codes from the root of Huffman Tree.
void printCodes(MinHeapNode *root, string str)
{
	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(vector<char> data, vector<int> freq)
{
	MinHeapNode *left, *right, *top;

	// Create a min heap & insert all characters of data[]
	priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap; 

	for (int i = 0; i < data.size(); ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while the size of the heap doesn't become 1
	while (minHeap.size() != 1)
	{
		// Extract the two minimum freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes' frequencies. Make the
		// two extracted nodes left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver Code
int main()
{
	vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'};
	vector<int> freq = {5, 9, 12, 13, 16, 45};

	HuffmanCodes(arr, freq);

	return 0;
}

// Best Case Time Complexity: O(n)
// Average Case Time Complexity: O(n log n)
// Worst Case Time Complexity: O(n log n)
// Space Complexity: O(n)
