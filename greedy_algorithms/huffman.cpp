// C++ program for Huffman Coding
#include <iostream>
#include <queue>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    MinHeapNode *left, *right;

	std::cerr << ">>> Entering MinHeapNode(data=" << data << ",freq=" << freq << ")" << std::endl;
	std::cerr << "MinHeapNode(data=" << data << ",freq=" << freq << "): left → " << left << std::endl;
	std::cerr << "<<< Exiting MinHeapNode(data=" << data << ",freq=" << freq << ")" << std::endl;
    MinHeapNode(char data, unsigned freq)

    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

void deleteAll(const MinHeapNode* const root) {
	std::cerr << ">>> Entering deleteAll(root=" << root << ")" << std::endl;
    if (root) {
        deleteAll(root->left);
        deleteAll(root->right);
        delete root;
    }
	std::cerr << "<<< Exiting deleteAll(root=" << root << ")" << std::endl;
}

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
    bool operator()(const MinHeapNode* const l,
                    const MinHeapNode* const r) const {
        return l->freq > r->freq;
    }
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, const string& str) {
	std::cerr << ">>> Entering printCodes(root=" << root << ",str=" << str << ")" << std::endl;
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
	std::cerr << "<<< Exiting printCodes(root=" << root << ",str=" << str << ")" << std::endl;
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(const char data[], const int freq[], int size) {
	std::cerr << ">>> Entering HuffmanCodes(data=" << data << ",freq=" << freq << ",size=" << size << ")" << std::endl;
    struct MinHeapNode *left, *right;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
		std::cerr << "HuffmanCodes(data=" << data << ",freq=" << freq << ",size=" << size << "): left → " << left << std::endl;
        minHeap.pop();

        right = minHeap.top();
		std::cerr << "HuffmanCodes(data=" << data << ",freq=" << freq << ",size=" << size << "): right → " << right << std::endl;
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        auto* const top = new MinHeapNode('$', left->freq + right->freq);
		std::cerr << "HuffmanCodes(data=" << data << ",freq=" << freq << ",size=" << size << "): top → " << top << std::endl;

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
    deleteAll(minHeap.top());
	std::cerr << "<<< Exiting HuffmanCodes(data=" << data << ",freq=" << freq << ",size=" << size << ")" << std::endl;
}

// Driver program to test above functions
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);
	std::cerr << "main(): size → " << size << std::endl;

    HuffmanCodes(arr, freq, size);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
