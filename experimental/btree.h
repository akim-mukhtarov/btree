#include <stdbool.h>


typedef
union Node__any_t
{
    char char_v;
    int int_v;
    double double_v;
    float float_v;
    void* void_p;
} Node__any_t;


typedef
struct Node
{
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    Node__any_t value;
} Node;


typedef
struct Btree
{
    Node* root;
    bool (*comp)(const Node*, const Node*);
} Btree;


void Btree__append(Btree* tree, Node* node, int* err);
