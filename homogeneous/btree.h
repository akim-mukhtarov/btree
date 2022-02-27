#include "algo/insert.h"


#define NODE(value_t)\
Node_##value_t\
{\
        struct Node_##value_t* parent;\
        struct Node_##value_t* left;\
        struct Node_##value_t* right;\
        value_t value;\
}


#define BTREE(node_t)\
Btree_##node_t\
{\
        node_t* root;\
        bool (*comp)(const node_t*, const node_t*);\
}


#define BTREE__INSERT(tree_t, node_t, tree_p, node_p)\
({\
    btree__insert(\
        node_t, (tree_p)->root, (node_p),\
        (tree_p)->comp, parent, left, right);\
})
