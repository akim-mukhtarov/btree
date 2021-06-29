// Dumpy Binary Tree implementation
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


typedef struct Node 
{
    struct Node*    parent;
    struct Node*    left;
    struct Node*    right;
    int             val;
} Node;


typedef struct B_Tree 
{
    Node*           root;
    size_t          size;
} B_Tree;


Node* init_node(int val) {
    // init node
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    printf("%s%d%s\n", "adding node ", node->val, "...");
    return node;
}


Node* search_parent(B_Tree* tree, Node* node) {
    // define node's parent in the tree
    if (tree->size == 0) {
        tree->root = node;
    } 
    else {
        Node* parent = tree->root;
        Node* next = tree->root;
        
        while(next != NULL) {
            parent = next; // ++parent, _only_ after assert that next is not NULL
            if (node->val >= parent->val) {
                next = parent->right;
            }
            else {
                next = parent->left;
            }
        }
        node->parent = parent;
        *(node->val >= parent->val ? &parent->right : &parent->left) = node;
    }
}


Node* add_node(B_Tree* tree, int val) {
    // init routine
    Node* node = init_node(val);
    Node* parent = search_parent(tree, node);
    node->parent = parent;
    ++tree->size;
    return node;
}


B_Tree* make_tree() {
    // init routine
    B_Tree* tree = (B_Tree*)malloc(sizeof(B_Tree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}



void padding ( char ch, int n )
{
  int i;

  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure ( Node* root, int level )
{
  int i;

  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->val );
    structure ( root->left, level + 1 );
  }
}



int main() {
    int values[] = {4,2,3,7,2,9,8,11,5,3}; // data to add
    size_t size = sizeof(values)/sizeof(int);
    
    B_Tree* tree = make_tree();
    
    for (int i=0; i < size; ++i) {
        add_node(tree, values[i]);
    }
    
    printf("%ld\n", tree->size);
    structure(tree->root, 0);
    
    return 0;
}