#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class PriorityQueue
{
public:
    virtual ~PriorityQueue() = default;

    virtual void enqueue(T item) = 0;

    virtual T dequeue() = 0;

    virtual T peek() = 0;
};

#endif