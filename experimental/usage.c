#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "btree.h"
#include "defs/utils.h"


typedef
struct CustomType
{
    int key;
    const char* name;
} CustomType;


bool comp(const Node* fst, const Node* snd)
{
    int fst_val = node__get_asref(fst, CustomType*)->key;
    int snd_val = node__get_asref(snd, CustomType*)->key;
    return fst >= snd;
}


int main()
{
    Btree tree = { NULL, comp };
    Node node = {};
    CustomType some = { 200, "some" };

    node.value.void_p = &some;

    int err;
    Btree__append(&tree, &node, &err);
    assert(err == 0);

    printf("value: %d\n", node__get_asref(tree.root, CustomType*)->key );

    return EXIT_SUCCESS;
}
