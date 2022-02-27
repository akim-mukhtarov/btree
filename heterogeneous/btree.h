#include <stdbool.h>
#include <stddef.h>     // offsetof


typedef
struct Any_t
{
        char char_v;
        int int_v;
        float float_v;
        double double_v;
        void* void_p;
} Any_t;


typedef
struct Node
{
        struct Node* parent;
        struct Node* left;
        struct Node* right;
        Any_t value;
} Node;


typedef
struct Btree
{
        Node* root;
        bool (*comp)(const Node*, const Node*);
} Btree;


#define Node__get(node_p, value_t) ( *(value_t*)(char*)node_p + offsetof(Node, value) )
#define Node__get_asref(node_p, value_p) ( *(value_p*)(void*)(char*)node_p + offsetof(Node, value) )

void Btree__insert(Btree* tree, Node* node);
