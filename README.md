## Motivation

In C, making generic data structures isn't trivial.
Yet this is not really a problem as the C apps are
rather quite concrete and rarely deal with some tricky business logic.
Nevertheless I thought about writing a set of macros which expand to
generic algorithms suitable to any user defined struct,
that look like binary tree.

It's about my curiosity, for learning purposes only.

Say there are 3 ways to define Node struct:

```C
struct Btree
{
    struct Btree *parent;
    struct Btree *left;
    struct Btree *right;
    void *value;  // is not suitable for using with primitive types
};
```      

```C
struct Node
{
    struct Node *parent;
    struct Node* left;
    struct Node* right;
    Any_t value;  // assume some user defined union
};
```

or in a very concrete manner
```C
struct Node
{
    struct MyNode *parent;
    struct MyNode *left;
    struct MyNode *right;
    int value;
};
```
Appending, balancing, copying and finding should work with all (and other possible :).
