#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

template <typename T>
class BinaryHeap {
private:
    std::vector<T> heap;
    
    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int index);
    void heapifyDown(int index);
    
public:
    BinaryHeap() {}
    
    // Core operations
    void insert(const T& key);
    T extractMin();
    T getMin() const;
    void decreaseKey(int index, const T& newKey);
    bool isEmpty() const { return heap.empty(); }
    int size() const { return heap.size(); }
    
    // For testing
    void print() const;
};

template <typename T>
void BinaryHeap<T>::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] > heap[index]) {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

template <typename T>
void BinaryHeap<T>::heapifyDown(int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap.size() && heap[left] < heap[minIndex])
        minIndex = left;
    
    if (right < heap.size() && heap[right] < heap[minIndex])
        minIndex = right;
    
    if (index != minIndex) {
        std::swap(heap[index], heap[minIndex]);
        heapifyDown(minIndex);
    }
}

template <typename T>
void BinaryHeap<T>::insert(const T& key) {
    heap.push_back(key);
    heapifyUp(heap.size() - 1);
}

template <typename T>
T BinaryHeap<T>::extractMin() {
    if (isEmpty())
        throw std::runtime_error("Heap is empty");
    
    T minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!isEmpty())
        heapifyDown(0);
    
    return minValue;
}

template <typename T>
T BinaryHeap<T>::getMin() const {
    if (isEmpty())
        throw std::runtime_error("Heap is empty");
    return heap[0];
}

template <typename T>
void BinaryHeap<T>::decreaseKey(int index, const T& newKey) {
    if (index >= heap.size())
        throw std::out_of_range("Index out of range");
    
    if (newKey > heap[index])
        throw std::invalid_argument("New key is greater than current key");
    
    heap[index] = newKey;
    heapifyUp(index);
}

template <typename T>
void BinaryHeap<T>::print() const {
    for (const auto& val : heap)
        std::cout << val << " ";
    std::cout << std::endl;
}

#endif
