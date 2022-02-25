#include "btree.h"
#include "defs/append.h"


void Btree__append(Btree* tree, Node* node, int err)
{
    if (tree == NULL || node == NULL)
        return;

    btree__append(Node, tree->root, node, tree->comp, parent, left, right);
}
