/**
 * \file
 * \brief A C++ program to demonstrate common Binary Heap Operations
 */
#include <climits>
#include <iostream>
#include <utility>

// @slice: 最小堆实现
/** A class for Min Heap */
class MinHeap {
    int *harr;      ///< pointer to array of elements in heap // @slice: 最小堆实现数组的指针
    int capacity;   ///< maximum possible size of min heap // @slice: 最小堆最大容量
    int heap_size;  ///< Current number of elements in min heap // @slice: 最小堆当前容量

 public:
    /** Constructor: Builds a heap from a given array a[] of given size
     * \param[in] capacity initial heap capacity
     */
    explicit MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    /** to heapify a subtree with the root at given index */
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }

    /** to get index of left child of node at index i */
    int left(int i) { return (2 * i + 1); } // @slice: 左子结点 = 2i + 1

    /** to get index of right child of node at index i */
    int right(int i) { return (2 * i + 2); } // @slice: 右子结点 = 2i + 2

    /** to extract the root which is the minimum element */
    int extractMin();

    /** Decreases key value of key at index i to new_val */
    void decreaseKey(int i, int new_val);

    /** Returns the minimum key (key at root) from min heap */
    int getMin() { return harr[0]; } // @slice: 最小堆最小值 = 数组头部指针

    /** Deletes a key stored at index i */
    void deleteKey(int i);

    /** Inserts a new key 'k' */
    void insertKey(int k);

    ~MinHeap() { delete[] harr; }
};

// Inserts a new key 'k'
void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k; // @slice: 新key插入数组尾

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) { // @slice: 如果新值小 则向其父节点调整
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// @slice: 将目标key的value 赋值为更小的新value
/** Decreases value of key at index 'i' to new_val.  It is assumed that new_val
 * is smaller than harr[i].
 */
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
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

    return root;
}

/** This function deletes key at index i. It first reduced value to minus
 * infinite, then calls extractMin()
 */
void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

// @slice: 递归最小堆化函数
/** A recursive method to heapify a subtree with the root at given index
 *  This method assumes that the subtrees are already heapified
 */
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i; // @slice: 记录子结点最小值
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        std::swap(harr[i], harr[smallest]);
        MinHeapify(smallest); // @slice: 向下递归
    }
}

// Driver program to test above functions
int main() {
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
    return 0;
}
