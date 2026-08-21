/**
 * \file
 * \brief A C++ program to demonstrate common Binary Heap Operations
 */
#include <climits>
#include <iostream>
#include <utility>

/** A class for Min Heap */
class MinHeap {
    int *harr;      ///< pointer to array of elements in heap
    int capacity;   ///< maximum possible size of min heap
    int heap_size;  ///< Current number of elements in min heap

 public:
    /** Constructor: Builds a heap from a given array a[] of given size
     * \param[in] capacity initial heap capacity
     */
    explicit MinHeap(int cap) {
		std::cerr << ">>> Entering MinHeap(cap=" << cap << ")" << std::endl;
		std::cerr << "MinHeap(cap=" << cap << "): harr → " << harr << std::endl;
		std::cerr << "MinHeap(cap=" << cap << "): capacity → " << capacity << std::endl;
		std::cerr << "MinHeap(cap=" << cap << "): heap_size → " << heap_size << std::endl;
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    /** to heapify a subtree with the root at given index */
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }

    /** to get index of left child of node at index i */
    int left(int i) { return (2 * i + 1); }

    /** to get index of right child of node at index i */
    int right(int i) { return (2 * i + 2); }

    /** to extract the root which is the minimum element */
    int extractMin();

    /** Decreases key value of key at index i to new_val */
    void decreaseKey(int i, int new_val);

    /** Returns the minimum key (key at root) from min heap */
    int getMin() { return harr[0]; }

    /** Deletes a key stored at index i */
    void deleteKey(int i);

    /** Inserts a new key 'k' */
    void insertKey(int k);

    ~MinHeap() { delete[] harr; }
};

// Inserts a new key 'k'
void MinHeap::insertKey(int k) {
	std::cerr << ">>> Entering MinHeap::insertKey(k=" << k << ")" << std::endl;
    if (heap_size == capacity) {
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
	std::cerr << "<<< Exiting MinHeap::insertKey(k=" << k << ")" << std::endl;
}

/** Decreases value of key at index 'i' to new_val.  It is assumed that new_val
 * is smaller than harr[i].
 */
void MinHeap::decreaseKey(int i, int new_val) {
	std::cerr << ">>> Entering MinHeap::decreaseKey(i=" << i << ",new_val=" << new_val << ")" << std::endl;
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
	std::cerr << "<<< Exiting MinHeap::decreaseKey(i=" << i << ",new_val=" << new_val << ")" << std::endl;
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
	std::cerr << ">>> Entering MinHeap::extractMin()" << std::endl;
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

	std::cerr << "<<< Exiting MinHeap::extractMin()" << std::endl;
    return root;
}

/** This function deletes key at index i. It first reduced value to minus
 * infinite, then calls extractMin()
 */
void MinHeap::deleteKey(int i) {
	std::cerr << ">>> Entering MinHeap::deleteKey(i=" << i << ")" << std::endl;
    decreaseKey(i, INT_MIN);
    extractMin();
	std::cerr << "<<< Exiting MinHeap::deleteKey(i=" << i << ")" << std::endl;
}

/** A recursive method to heapify a subtree with the root at given index
 *  This method assumes that the subtrees are already heapified
 */
void MinHeap::MinHeapify(int i) {
	std::cerr << ">>> Entering MinHeap::MinHeapify(i=" << i << ")" << std::endl;
    int l = left(i);
    int r = right(i);
	std::cerr << "MinHeap::MinHeapify(i=" << i << "): r → " << r << std::endl;
	std::cerr << "MinHeap::MinHeapify(i=" << i << "): l → " << l << std::endl;
    int smallest = i;
	std::cerr << "MinHeap::MinHeapify(i=" << i << "): smallest → " << smallest << std::endl;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        std::swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
	std::cerr << "<<< Exiting MinHeap::MinHeapify(i=" << i << ")" << std::endl;
}

// Driver program to test above functions
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    std::cout << h.extractMin() << " ";
    std::cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    std::cout << h.getMin();
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
