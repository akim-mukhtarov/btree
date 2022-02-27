#include <stdbool.h>
#include <stdlib.h>


typedef struct NODE(int) Node_int;
typedef struct BTREE(Node_int) Btree;


bool comp(const Node_int* fst, const Node_int* snd)
{
    return fst->value >= snd->value;
}


int main()
{
    Btree btree = { NULL, comp };
    Node_int node = {};
    node.value = 200;

    BTREE__INSERT(Btree, Node_int, &btree, &node);

    return EXIT_SUCCESS;
}
