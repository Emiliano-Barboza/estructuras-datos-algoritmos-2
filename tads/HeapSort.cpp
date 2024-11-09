#include <cassert>
#include "MaxHeap.cpp"
#include "Heap.h"
#ifndef HEAP_SORT
#define HEAP_SORT
using namespace std;

template <class T>
class HeapSort: public Heap<T> {
private:
    MaxHeap<T> heap;
    int size;

public:
    HeapSort(int size) : heap(size) {
        this->size = size;
    }

    void insert(T value) override {
        this->heap.insert(value);
    };

    T top() override {
        return this->heap.top();
    }

    T remove() override {
        return this->heap.remove();
    }

    bool exists(T value) override {
        return this->heap.exists(value);
    }

    int indexOf(T value) override {
        return this->heap.indexOf(value);
    }

    T & get(int index) override {
        return this->heap.get(index);
    }

    T* sort() {
        assert(!this->heap.empty());
        T* sorted = new T[this->size];
        for (int i = this->size - 1; i >= 0; i--) {
            sorted[i] = this->heap.remove();
        }
        return sorted;
    }
};

#endif