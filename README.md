## Motivation

It's about my curiosity, for learning purposes only.
It's not a rocket-science or something like that.  
Somehow I don't find it interesting to write yet another
Btree (and Node?) structs implementation again.  
I wonder if I can write a set of macros which expand to generic
algorithms to use with binary tree-like structs, defined by user himself.  

Say someone could define her/his binary tree struct as follows:

```C
struct Btree
{
    struct Btree *parent;
    struct Btree *left;
    struct Btree *right;
    void *value;  // or union, I guess
};
```      

or in another way
```C
struct MyNode
{
    struct MyNode *prev;
    struct MyNode *left;
    struct MyNode *right;
    // instead of having it in a separate struct...
    int int_key;
    const char* str_key;
};
```
Appending, balancing, copying should work with both (and other possible).
