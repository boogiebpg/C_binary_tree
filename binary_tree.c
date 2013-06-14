#include "binary_tree.h"

void link_child_to_parent(struct node* parent, struct node* child)
{
    if (parent == NULL)
        return;
    child->parent = parent;
    if (parent->data > child->data)
        parent->left = child;
    else
        parent->right = child;
}

struct node* delete_node(struct node* root_node, int data)
{
    struct node *node_for_destroy, *child, *child_left, *child_right, *parent,
            *deep_right_node, *new_root;

    new_root = root_node;

    node_for_destroy = lookup(root_node, data);
    if (node_for_destroy == NULL)
        return root_node;

    /* delete leaf - node doesn't have any child */
    if (node_for_destroy->left == NULL && node_for_destroy->right == NULL)
    {
        if (node_for_destroy == root_node)
        {
            free(node_for_destroy);
            return NULL;
        }
        else
        {
            if (node_for_destroy->parent->data > node_for_destroy->data)
                node_for_destroy->parent->left = NULL;
            else
                node_for_destroy->parent->right = NULL;
            free(node_for_destroy);
        }
    }
    /* node has 2 children */
    else if (node_for_destroy->left != NULL && node_for_destroy->right != NULL)
    {
        child_left = node_for_destroy->left;
        child_right = node_for_destroy->right;

        parent = node_for_destroy->parent;

        if (node_for_destroy->parent == NULL)
            new_root = child_left;

        free(node_for_destroy);

        /* move left child branch higher, to the place of node_for_destroy */
        link_child_to_parent(parent, child_left);
        
        /* searching the deepest right node of left child,
        we'll link right child branch to it */
        deep_right_node = child_left;
        while (deep_right_node->right != NULL)
        {
            deep_right_node = deep_right_node->right;
        }
        link_child_to_parent(deep_right_node, child_right);
    }
    /* node has only 1 child */
    else
    {
        if (node_for_destroy->left != NULL)
            child = node_for_destroy->left;
        else
            child = node_for_destroy->right;
        parent = node_for_destroy->parent;
        if (parent == NULL)
            new_root = child;
        link_child_to_parent(parent, child);
        free(node_for_destroy);
    }

    return new_root;
}

struct node* new_node(int data, struct node* parent) {
    struct node* node = malloc( sizeof(struct node) );
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return(node);
} 

struct node* insert(struct node* node, int data, struct node* parent)
{

    if( node == NULL )
    {
        node = new_node(data, parent);
        return(node);
    }
    else
    {
        if (data < node->data)
        {
            node->left = insert(node->left, data, node);
        }
        else
        {
            node->right = insert(node->right, data, node);
        }
    }
    return(node);
}

struct node* lookup(struct node* node, int target)
{
    if (node == NULL) {
        return NULL;
    }
    else
    {
        if (target == node->data)
        {
            return node;
        }
        else
        {
            if (target < node->data)
            {
                return(lookup(node->left, target));
            }
            else
            {
                return(lookup(node->right, target));
            }
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
