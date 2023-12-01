#include "Btree.h"

int main() {
    Btree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(12);
    t.insert(15);
    t.insert(23);
    t.insert(1);
    t.insert(21);
    t.insert(22);
    t.insert(8);
    t.insert(9);

    std::cout << "The B-tree: << std::endl;
    t.traverse();

    int k = 23;

    Node* foundNode = t.search(k);

    k = 4;

    foundNode = t.search(k);

    return 0;

}
    
