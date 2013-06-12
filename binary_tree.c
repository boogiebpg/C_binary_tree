#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node* tree_init();
struct node* new_node(int data);
struct node* insert(struct node* node, int data);
void print_preorder(struct node* tree);
void print_inorder(struct node* tree);
void print_postorder(struct node* tree);
void destroy_tree(struct node* node);

int main()
{
    struct node *root_node = NULL, *elem;

    //printf("%d\n",root->data);
    root_node = insert(root_node,5);
    root_node = insert(root_node,7);
    root_node = insert(root_node,3);
    root_node = insert(root_node,9);
    root_node = insert(root_node,12);
    root_node = insert(root_node,1);
    //printf("%d\n",root->right->data);
    print_preorder(root_node);
    printf("%d\n", lookup(root_node,11));
    printf("%d\n", lookup(root_node,12));
    destroy_tree(root_node);

    return 1;
}

struct node* new_node(int data) {
    struct node* node = malloc( sizeof(struct node) );
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
} 

struct node* insert(struct node* node, int data)
{

    if( node == NULL )
    {
        node = new_node(data);
        return(node);
    }
    else
    {
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
    }
    return(node);
}

int lookup(struct node* node, int target) {
    if (node == NULL) {
        return 0;
    }
    else
    {
        if (target == node->data)
        {
            return 1;
        }
        else
        {
            if (target < node->data) return(lookup(node->left, target));
            else return(lookup(node->right, target));
        }
    }
} 

void print_preorder(struct node* tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(struct node* tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(struct node* tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void destroy_tree(struct node* node)
{
  if ( node != NULL )
  {
      destroy_tree(node->left);
      destroy_tree(node->right);
      free(node);
  }
}
