#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return minVal;
    }

    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};
