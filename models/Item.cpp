#ifndef ITEM
#define ITEM
using namespace std;

class Item
{
public:
    int id = 0;
    int price = 0;
    Item(int id, int price)
    {
        this->id = id;
        this->price = price;
    }
    Item()= default;

    bool operator>(const Item& other) const
    {
        return this->price > other.price ||
               (this->price == other.price && this->id < other.id);
    }

    bool operator==(const Item& other) const
    {
        return this->id == other.id;
    }
};

#endif