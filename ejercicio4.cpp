#include <cassert>
#include <iostream>
#include <ostream>
#include "./tads/ExtendedPriorityQueue.cpp"

using namespace std;

int main()
{
    ExtendedPriorityQueue<int> * q = new ExtendedPriorityQueue<int>(10);
    q->enqueue(1);
    q->enqueue(10);
    q->enqueue(30);
    q->enqueue(20);
    cout << q->dequeue() << endl;
    // TODO
    return 0;
}