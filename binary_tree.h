#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
};

void link_child_to_parent(struct node* parent, struct node* child);
struct node* delete_node(struct node* root_node, int data);
struct node* new_node(int data, struct node* parent);
struct node* insert(struct node* node, int data, struct node* parent);
struct node* lookup(struct node* node, int target);
void print_preorder(struct node* tree);
void print_inorder(struct node* tree);
void print_postorder(struct node* tree);
void destroy_tree(struct node* node);

#endif