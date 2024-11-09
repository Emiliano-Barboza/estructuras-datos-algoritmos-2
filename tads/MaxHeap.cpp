#include <cassert>

#include "Heap.h"
#ifndef MAX_HEAP
#define MAX_HEAP
using namespace std;

template <class T>
class MaxHeap: public Heap<T> {
private:
    int size;
    int nextIndex;
    T* elements;
    int rootIndex = 0;

    bool isFull () {
        return this->nextIndex > this->size;
    }

    int getLeftChild(int parentIndex) {
        return  2 * parentIndex + 1;
    }

    int getRightChild(int parentIndex) {
        return  2 * parentIndex + 2;
    }

    int getParentIndex(int childIndex) {
        return  (childIndex -1 ) / 2;
    }

public:
    MaxHeap(int size) {
        this->elements = new T[size];
        this->size = size;
        this->nextIndex = 0;
    }

    bool empty () {
        return this->nextIndex == 0;
    }

    void swap(int parentIndex, int childIndex) {
        T aux = this->elements[parentIndex];
        this->elements[parentIndex] = this->elements[childIndex];
        this->elements[childIndex] = aux;
    }

    void bubbleUp(int index) {
        if (index > this->rootIndex) {
            int parentIndex = this->getParentIndex(index);
            T parent = this->elements[parentIndex];
            T child = this->elements[index];
            if (child > parent) {
                this->swap(parentIndex, index);
                this->bubbleUp(parentIndex);
            }
        }
    }

    void bubbleDown(int index)
    {
        int maximum = index;
        int leftIndex = this->getLeftChild(index);
        if (leftIndex < this->nextIndex) {
            if (this->elements[leftIndex] > this->elements[maximum]) {
                maximum = leftIndex;
            }
            int rightIndex = this->getRightChild(index);
            if (rightIndex < this->nextIndex && this->elements[rightIndex] > this->elements[maximum]) {
                maximum = rightIndex;
            }

            if (maximum != index) {
                this->swap(index, maximum);
                this->bubbleDown(maximum);
            }
        }
    }

    void insert(T value) override {
        assert(!this->isFull());
        this->elements[this->nextIndex] = value;
        this->bubbleUp(this->nextIndex);
        ++this->nextIndex;
    };

    T top() override {
        assert(!this->empty());
        return this->elements[0];
    }

    T remove() override {
        assert(!this->empty());
        T value = this->elements[0];
        this->swap(this->rootIndex, this->nextIndex - 1);
        --this->nextIndex;
        this->bubbleDown(this->rootIndex);
        return value;
    }

    bool exists(T value) override {
        bool exists = false;
        for (int i = 0; i < this->nextIndex && !exists; ++i) {
            exists = this->elements[i] == value;
        }
        return exists;
    }

    int indexOf(T value) override {
        int index = -1;
        for (int i = 0; i < this->nextIndex && index < 0; ++i) {
            if (this->elements[i] == value) {
                index = i;
            }
        }
        return index;
    }

    T& get(int index) override {
        assert(index >= 0 && index < this->nextIndex);
        return this->elements[index];
    }
};

#endif