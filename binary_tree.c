#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
  void *data;
  struct node *left;
  struct node *right;
};

struct node* tree_init();

/* initialize tree */
struct node* tree_init()
{
    struct node *root;

    root = malloc( sizeof(struct node) );
    root->data = NULL;
    root->left = 0;
    root->right = 0;

    return root;
}

int main()
{
	root = tree_init();
}