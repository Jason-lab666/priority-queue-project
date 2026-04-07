#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// ===== Binary Heap =====
class BinaryHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] <= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }
};

// ===== Test =====
vector<int> generateData(int n) {
    vector<int> data;
    for (int i = 0; i < n; i++) {
        data.push_back(rand());
    }
    return data;
}

void test(int n) {
    BinaryHeap h;
    auto data = generateData(n);

    auto start = high_resolution_clock::now();
    for (int x : data) h.insert(x);
    auto end = high_resolution_clock::now();

    cout << "Binary Heap Insert " << n << ": "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";
}

int main() {
    vector<int> sizes = {1000, 10000, 50000};

    for (int n : sizes) {
        test(n);
    }

    return 0;
}
