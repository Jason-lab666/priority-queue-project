#include <iostream>
using namespace std;

struct BinomialNode {
    int key, degree;
    BinomialNode *parent, *child, *sibling;

    BinomialNode(int k) {
        key = k;
        degree = 0;
        parent = child = sibling = nullptr;
    }
};

class BinomialHeap {
private:
    BinomialNode* head;

    BinomialNode* mergeTrees(BinomialNode* b1, BinomialNode* b2) {
        if (b1->key > b2->key)
            swap(b1, b2);

        b2->parent = b1;
        b2->sibling = b1->child;
        b1->child = b2;
        b1->degree++;

        return b1;
    }

public:
    BinomialHeap() { head = nullptr; }

    void insert(int key) {
        BinomialHeap temp;
        temp.head = new BinomialNode(key);
        merge(temp);
    }

    void merge(BinomialHeap& other) {
        if (!head) {
            head = other.head;
            return;
        }
        BinomialNode* curr = head;
        while (curr->sibling)
            curr = curr->sibling;
        curr->sibling = other.head;
    }
};
