#include <iostream>
#include "./models/Item.cpp"
#include "./tads/HeapSort.cpp"

using namespace std;

int main()
{
    int size, id, price, lowerPrices;
    cin >> size;
    HeapSort<Item> * heapSort = new HeapSort<Item>(size);

    for (int i = 0; i < size; i++)
    {
        cin >> id;
        cin >> price;
        Item item(id, price);
        heapSort->insert(item);
    }

    Item *items = heapSort->sort();
    cin >> lowerPrices;
    int * ids = new int[size]();
    int index = 0;
    while (lowerPrices > 0) {
        id = items[index].id;
        if (ids[id] == 0) {
            ids[id] = 1;
            cout << items[index].id << '\n';
            lowerPrices--;
        }
        index++;
    }

    return 0;
}
