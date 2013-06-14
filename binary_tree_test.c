#include "binary_tree.h"

int main()
{
    struct node *root_node = NULL;

    root_node = insert(root_node,5,NULL);
    root_node = delete_node(root_node,5);
    root_node = insert(root_node,7,NULL);
    root_node = insert(root_node,3,NULL);
    root_node = insert(root_node,6,NULL);
    root_node = insert(root_node,9,NULL);
    root_node = insert(root_node,12,NULL);
    root_node = insert(root_node,1,NULL);
    print_preorder(root_node);
    root_node = delete_node(root_node,7);
    printf("----------------------\n");
    //printf("%d\n", lookup(root_node,11)->data);
    //printf("%d\n", lookup(root_node,12)->data);
    print_preorder(root_node);
    destroy_tree(root_node);

    return 1;
}