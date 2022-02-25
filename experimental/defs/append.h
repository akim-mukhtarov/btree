#include <stddef.h>   // offsetof
/*
A macro that expands to generic algo of appending
a binary tree to another binary tree
It is up to user to define binary tree type
*/
#define btree__append(                                                  \
        T,                                                              \
        tree,                                                           \
        subtree,                                                        \
        comp,                                                           \
        attr_parent,                                                    \
        attr_left,                                                      \
        attr_right                                                      \
)                                                                       \
({                                                                      \
    T *parent = tree;                                                   \
    T **next = &tree;                                                   \
                                                                        \
    while (*next)                                                       \
    {                                                                   \
        parent = *next;                                                 \
                                                                        \
        if (comp(subtree, tree))                                        \
            next = (T**)((char*)parent + offsetof(T, attr_right));      \
        else                                                            \
            next = (T**)((char*)parent + offsetof(T, attr_left));       \
    }                                                                   \
    subtree->attr_parent = parent;                                      \
    *next = subtree;                                                    \
})
