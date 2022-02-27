#include <stdlib.h>
#include <stdio.h>
#include "btree.h"


int main()
{
    Btree tree = {};
    Node node = {};
    node.value.int_v = 200;

    Btree__insert(&tree, &node);
    printf("Value: %d\n", Node__get(tree.root, int));

    return EXIT_SUCCESS;
}
