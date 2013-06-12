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
void destroy_tree(struct node* node);

int main()
{
    struct node *root_node = NULL, *elem;

    //printf("%d\n",root->data);
    root_node = insert(root_node,5);
    root_node = insert(root_node,7);
    root_node = insert(root_node,3);
    root_node = insert(root_node,9);
    //printf("%d\n",root->right->data);
    print_preorder(root_node);
    destroy_tree(root_node);

    return 1;
}

struct node* new_node(int data) {
    printf("creating %d\n",data);
    struct node* node = malloc( sizeof(struct node) );
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    printf("node data is: %d\n",node->data);

    return(node);
} 

struct node* insert(struct node* node, int data)
{

    if( node == NULL )
    {
        printf("inserting into %d\n",&node);
        node = new_node(data);
        return(node);
    }
    else
    {
        if (data < node->data)
        {
            printf("go left\n");
            insert(node->left, data);
        }
        else
        {
            printf("go right\n");
            insert(node->right, data);
        }
    }
    return(node);
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

void destroy_tree(struct node* node)
{
  if ( node != NULL )
  {
      destroy_tree(node->left);
      destroy_tree(node->right);
      free(node);
  }
}
