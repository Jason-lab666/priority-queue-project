#include <iostream>
#include "BinaryHeap.h"

using namespace std;

void testBinaryHeap() {
    cout << "\n=== Testing Binary Heap ===" << endl;
    BinaryHeap<int> heap;
    
    cout << "Inserting: 5, 3, 7, 1, 9, 2, 4, 8, 6" << endl;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(9);
    heap.insert(2);
    heap.insert(4);
    heap.insert(8);
    heap.insert(6);

    cout << "Heap size: " << heap.size() << endl;

    cout << "Min element: " << heap.getMin() << endl;

    cout << "Extracting elements in sorted order: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;
    
    cout << "After extraction, heap is empty: " << (heap.isEmpty() ? "Yes" : "No") << endl;
}

void testLargeData() {
    cout << "\n=== Testing with Larger Dataset ===" << endl;
    BinaryHeap<int> heap;

    cout << "Inserting 100 random integers..." << endl;
    for (int i = 0; i < 100; i++) {
        heap.insert(rand() % 1000);
    }
    
    cout << "Heap size: " << heap.size() << endl;
    cout << "Minimum element: " << heap.getMin() << endl;
  
    cout << "First 10 minimum elements: ";
    for (int i = 0; i < 10 && !heap.isEmpty(); i++) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;
    
    cout << "Remaining elements in heap: " << heap.size() << endl;
}

void testEdgeCases() {
    cout << "\n=== Testing Edge Cases ===" << endl;
    BinaryHeap<int> heap;

    cout << "Empty heap test:" << endl;
    cout << "  Is empty? " << (heap.isEmpty() ? "Yes" : "No") << endl;
    
    try {
        heap.getMin();
        cout << "  ERROR: Should have thrown exception!" << endl;
    } catch (const runtime_error& e) {
        cout << "  Correctly threw exception: " << e.what() << endl;
    }
  
    cout << "\nSingle element test:" << endl;
    heap.insert(42);
    cout << "  Min: " << heap.getMin() << endl;
    cout << "  Extract: " << heap.extractMin() << endl;
    cout << "  Is empty? " << (heap.isEmpty() ? "Yes" : "No") << endl;
  
    cout << "\nDuplicate elements test:" << endl;
    heap.insert(5);
    heap.insert(5);
    heap.insert(5);
    heap.insert(3);
    heap.insert(3);
    cout << "  Inserted: 5, 5, 5, 3, 3" << endl;
    cout << "  Extracting: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;
}

int main() {
    cout << "Binary Heap Implementation Tests\n" << endl;
    
    testBinaryHeap();
    testLargeData();
    testEdgeCases();
    
    cout << "\n=== All tests completed successfully! ===" << endl;
    
    return 0;
}
