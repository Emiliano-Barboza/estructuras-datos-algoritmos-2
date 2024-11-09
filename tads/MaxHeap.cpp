#include <cassert>

#include "Heap.h"
#ifndef MAX_HEAP
#define MAX_HEAP
using namespace std;

template <class T>
class MaxHeap: public Heap<T> {
private:
    int size;
    int lastElement;
    T* elements;
    bool isFull () {
        return this->lastElement > this->size;
    }

    bool empty () {
        return this->lastElement == 0;
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
    MaxHeap(int size) {
        this->elements = new T[size];
        this->size = size;
        this->lastElement = 0;
    }

    int getParentIndex(int childIndex) {
        return  (childIndex -1 ) / 2;
    }

    void bubbleUp(int index) {
        if (index > 0) {
            int parentIndex = this->getParentIndex(index);
            T parent = this->elements[parentIndex];
            T child = this->elements[index];
            if (child > parent) {
                this->swap(parentIndex, index);
                this->bubbleUp(parentIndex);
            }
        }
    }

    void bubbleDown(int currentIndex, int parentIndex)
    {
        int maximum = parentIndex;
        int rightIndex = this->getRightChild(parentIndex);
        int leftIndex = this->getLeftChild(parentIndex);

        if (leftIndex < currentIndex && this->elements[leftIndex] > this->elements[maximum]) {
            maximum = leftIndex;
        }

        if (rightIndex < currentIndex && this->elements[rightIndex] > this->elements[maximum]) {
            maximum = rightIndex;
        }

        if (maximum != parentIndex) {
            this->swap(parentIndex, maximum);
            this->bubbleDown(currentIndex, maximum);
        }
    }

    void insert(T value) override {
        assert(!this->isFull());
        this->elements[this->lastElement] = value;
        this->bubbleUp(this->lastElement);
        ++this->lastElement;
    };

    T top() override {
        assert(!this->empty());
        return this->elements[0];
    }

    T remove() override {
        assert(!this->empty());
        T value = this->elements[0];
        this->swap(0, this->lastElement - 1);
        --this->lastElement;
        this->bubbleDown(0, 0);// TODO CHECK THIS
        return value;
    }

    bool exists(T value) override {
        bool exists = false;
        for (int i = 0; i < this->lastElement && !exists; ++i) {
            exists = this->elements[i] == value;
        }
        return exists;
    }

    int indexOf(T value) override {
        int index = -1;
        for (int i = 0; i < this->lastElement && index < 0; ++i) {
            if (this->elements[i] == value) {
                index = i;
            }
        }
        return index;
    }

    T& get(int index) override {
        assert(index >= 0 && index < this->lastElement);
        return this->elements[index];
    }

    void showHeap()  {
        cout << "showHeap" << endl;
        for (int i = 0; i < this->lastElement; ++i) {
            cout << "ID:" << this->elements[i].id << " Priority: " << this->elements[i].priority << endl;
        }
    }
};

#endif