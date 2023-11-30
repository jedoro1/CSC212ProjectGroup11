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

    t.traverse();

    int k = 23;

    t.search(k);

    k = 4;

    t.search(k);

    return 0;

}
    
