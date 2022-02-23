#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "btree/defs.h"


typedef
struct Btree
{
    struct Btree* parent;
    struct Btree* left;
    struct Btree* right;
    int val;
} Btree;

bool comp(Btree* fst, Btree* snd)
{
    return fst->val >= snd->val;
}

int main()
{
    Btree* tree = calloc(sizeof(Btree), 1);
    assert(tree != NULL);
    tree->val = 20;

    Btree* sub = calloc(sizeof(Btree), 1);
    assert(tree != NULL);
    sub->val = 200;

    btree__append(Btree, tree, sub, comp, parent, left, right);

    printf("%d\n", tree->val);
    printf("%d\n", sub->parent->val);

    return EXIT_SUCCESS;
}
