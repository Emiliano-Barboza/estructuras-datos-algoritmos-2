#include "PriorityQueue.h"
#include "MinHeap.cpp"

template <class T, class V>
class ExtendedPriorityQueue: PriorityQueue<T> {
private:
    MinHeap<T> maxHeap;
public:
    ExtendedPriorityQueue(int size) : maxHeap(size) {}

    virtual ~ExtendedPriorityQueue() = default;

    void enqueue(T value) override {
        this->maxHeap.insert(value);
    };

    T dequeue() override {
        return this->maxHeap.remove();
    }

    T peek() override {
        return this->maxHeap.top();
    }

    /**
     * Changes the value priority in the queue.
     * @pre: the value must be in the queue.
     */
    void changePriority(const T& value, V newPriority) {
        int index = this->maxHeap.indexOf(value);
        assert(index >= 0);
        T valueToUpdate = this->maxHeap.get(index);
        V previousPriority = valueToUpdate.getPriority();
        if (newPriority != previousPriority) {
            //valueToUpdate.setPriority(newPriority);
            if (newPriority > previousPriority) {
                this->maxHeap.bubbleUp(index);
            } else {
                int parentIndex = this->maxHeap.getParentIndex(index);
                //this->maxHeap.bubbleDown(index, parentIndex);
            }
        }
    };

    /**
     * Deletes a specific value from the queue.
     * @pre: the value must be in the queue.
     */
    void deleteElement(const T& value) {
        int index = this->maxHeap.indexOf(value);
        assert(index >= 0);
        if (index > 0) {
            T top = this->maxHeap.top();
            T& newTop = this->maxHeap.get(index);
            newTop.priority = top.priority - 1;
            this->maxHeap.bubbleUp(index);
        }
        T removed = this->maxHeap.remove();
    };

    bool empty () {
        return this->maxHeap.empty();
    }

    void showQueue() {
        this->maxHeap.showHeap();
    }
};
