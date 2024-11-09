#include "PriorityQueue.h"
#include "MinHeap.cpp"

template <class T, class V>
class ExtendedPriorityQueue: PriorityQueue<T> {
private:
    MinHeap<T> heap;
public:
    ExtendedPriorityQueue(int size) : heap(size) {}

    virtual ~ExtendedPriorityQueue() = default;

    void enqueue(T value) override {
        this->heap.insert(value);
    };

    T dequeue() override {
        return this->heap.remove();
    }

    T peek() override {
        return this->heap.top();
    }

    /**
     * Changes the value priority in the queue.
     * @pre: the value must be in the queue.
     */
    void changePriority(const T& value) {
        int index = this->heap.indexOf(value);
        assert(index >= 0);
        T& valueToUpdate = this->heap.get(index);
        valueToUpdate.takeAway = true;
        this->heap.bubbleUp(index);
    };

    /**
     * Deletes a specific value from the queue.
     * @pre: the value must be in the queue.
     */
    void deleteElement(const T& value) {
        int index = this->heap.indexOf(value);
        assert(index >= 0);
        if (index > 0) {
            T top = this->heap.top();
            T& newTop = this->heap.get(index);
            newTop.priority = top.priority - 1;
            this->heap.bubbleUp(index);
        }
        T removed = this->heap.remove();
    };

    bool empty () {
        return this->heap.empty();
    }
};
