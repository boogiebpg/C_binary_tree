#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

int is_empty_tree(struct node *node);
struct node* tree_init();
void insert(int data, struct node *node);
void destroy_tree(struct node *node);

int main()
{
  struct node *root;

  root = tree_init();
  printf("%d\n",root->data);
  insert(5,root);
  printf("and here\n");
  //printf("%d\n",root->data);
  insert(7,root);
  printf("and here\n");
  printf("%d\n",root->data);
  destroy_tree(root);

  return 1;
}

/* check if specified list is empty */
int is_empty_tree(struct node *node)
{
    if (node == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* initialize node */
struct node* tree_init()
{
    struct node *root = 0;

    return root;
}

void insert(int data, struct node* node)
{
    if( is_empty_tree(node) )
    {
        node = malloc( sizeof( node ) );
        node->data = data;
        node->left = 0;
        node->right = 0;
        printf("we here\n");
    }
    else if(data < node->data)
    {
        printf("test1\n");
        insert( data, node->left );
    }
    else if(data > node->data)
    {
        printf("test2\n");
        insert( data, node->right );
    }
}

void destroy_tree(struct node* node)
{
  if ( !is_empty_tree(node) )
  {
      destroy_tree(node->left);
      destroy_tree(node->right);
      free(node);
  }
}
