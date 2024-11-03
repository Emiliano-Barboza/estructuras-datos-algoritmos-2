#include "PriorityQueue.h"
#include "MaxHeap.cpp"

template <class T>
class ExtendedPriorityQueue: PriorityQueue<T> {
private:
    MaxHeap<T> maxHeap;
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
    void changePriority(const T& value, int newPriority) {
        int index = this->maxHeap.indexOf(value);
        assert(index >= 0);
        T valueToUpdate = this->maxHeap.get(index);
        int previousPriority = valueToUpdate.getPriority();
        if (newPriority != previousPriority) {
            valueToUpdate.setPriority(newPriority);
            if (newPriority > previousPriority) {
                this->maxHeap.bubbleUp(index);
            } else {
                this->maxHeap.bubbleDown(index);
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
        T top = this-->maxHeap.top();
        T newTop = this->maxHeap.get(index);
        int maxPriority = top.getPriority() + 1;
        newTop.setPriority(maxPriority);
        this->maxHeap.bubbleUp(index);
        this->maxHeap.remove();
    };
};
