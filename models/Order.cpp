#ifndef ITEM
#define ITEM
#include <string>
#include "Priority.h"
using namespace std;

class Order : public Priority<bool>
{
public:
    int id = 0;
    int priority = 0;
    bool takeAway = false;
    string items = "";
    Order(int id)
    {
        this->id = id;
    }
    Order()= default;

    bool operator>(const Order& other) const
    {
        return this->takeAway > other.takeAway || this->priority > other.priority;
    }
    bool operator<(const Order& other) const
    {
        return this->priority < other.priority ||
               (this->priority == other.priority && this->takeAway > other.takeAway) ||
               (this->priority == other.priority && this->takeAway == other.takeAway && this->id < other.id);
    }
    bool operator==(const Order& other) const
    {
        return this->id == other.id;
    }

    bool getPriority() override {
        return this->takeAway;
    };

    void setPriority(bool priority) override {
        this->takeAway = priority;
    };

    void toString() {
        cout << this->id << " " << this->priority << " " << (this->takeAway ? "true" : "false") <<  " " << this->items << endl;
    }
};

#endif