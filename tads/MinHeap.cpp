#include <cassert>
#include <iostream>

#include "Heap.h"
#ifndef MIN_HEAP
#define MIN_HEAP
using namespace std;

template <class T>
class MinHeap: public Heap<T> {
private:
    int size;
    int nextIndex;
    T* elements;
    bool isFull () {
        return this->nextIndex > this->size;
    }

    int getLeftChild(int parentIndex) {
        return  2 * parentIndex + 1;
    }

    int getRightChild(int parentIndex) {
        return  2 * parentIndex + 2;
    }

    void swap(int parentIndex, int childIndex) {
        T aux = this->elements[parentIndex];
        this->elements[parentIndex] = this->elements[childIndex];
        this->elements[childIndex] = aux;
    }

public:
    MinHeap(int size) {
        this->elements = new T[size];
        this->size = size;
        this->nextIndex = 0;
    }

    bool empty () {
        return this->nextIndex == 0;
    }

    int getParentIndex(int childIndex) {
        return  (childIndex -1 ) / 2;
    }

    void bubbleUp(int index) {
        if (index > 0) {
            int parentIndex = this->getParentIndex(index);
            T parent = this->elements[parentIndex];
            T child = this->elements[index];
            if (child < parent) {
                this->swap(parentIndex, index);
                this->bubbleUp(parentIndex);
            }
        }
    }

    void bubbleDown(int index)
    {
        int minimum = index;
        int leftIndex = this->getLeftChild(index);
        if (leftIndex < this->nextIndex) {
            if (this->elements[leftIndex] < this->elements[minimum]) {
                minimum = leftIndex;
            }

            int rightIndex = this->getRightChild(index);
            if (rightIndex < this->nextIndex && this->elements[rightIndex] < this->elements[minimum]) {
                minimum = rightIndex;
            }

            if (minimum != index) {
                this->swap(index, minimum);
                this->bubbleDown(index);
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
        int rootIndex = 0;
        T value = this->elements[0];
        this->swap(rootIndex, this->nextIndex - 1);
        --this->nextIndex;
        this->bubbleDown(rootIndex);
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

    void showHeap()  {
        cout << "showHeap" << endl;
        // while (this->nextIndex > 0) {
        //     T removed = this->remove();
        //     removed.toString();
        // }
        for (int i = 0; i < this->nextIndex; ++i) {
            cout << this->elements[i].id << " " << this->elements[i].priority << " " << (this->elements[i].takeAway ? "true" : "false") <<  " " << this->elements[i].items << endl;
        }
    }
};

#endif