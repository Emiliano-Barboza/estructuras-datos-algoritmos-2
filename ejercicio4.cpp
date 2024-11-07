#include <iostream>
#include "./tads/ExtendedPriorityQueue.cpp"
#include "./models/Order.cpp"

using namespace std;

ExtendedPriorityQueue<Order, bool> * orderQueue;

int main()
{
    int size, amountOperations, id, priority;
    string items, operationType, takeAway;
    cin >> size;
    cin >> amountOperations;

    orderQueue = new ExtendedPriorityQueue<Order, bool>(size);

    for (int i = 0; i < amountOperations; i++)
    {
        cin >> operationType;
        if (operationType == "I") {
            cin >> id;
            cin >> priority;
            cin >> takeAway;
            cin >> items;
            Order order(id);
            order.priority = priority;
            order.takeAway = takeAway == "true" ? true : false;
            order.items = items;
            orderQueue->enqueue(order);
        } else if (operationType == "E") {
            cin >> id;
            Order order(id);
            orderQueue->deleteElement(order);
        }else if (operationType == "C") {
            cin >> id;
            Order order(id);
            orderQueue->changePriority(order, true);
        }
    }

    while(!orderQueue->empty()) {
        Order removed = orderQueue->dequeue();
        removed.toString();
    }

    return 0;
}