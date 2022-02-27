#include "btree.h"
#include "algo/insert.h"


void Btree__insert(Btree* tree, Node* node)
{
    btree__insert(Node, tree->root, node, node->comp, parent, left, right);
}
