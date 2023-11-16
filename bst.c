#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

struct node *search(struct node *node, int key)
{
    if (node == NULL || node->key == key)
    {
        return node;
    }
    if (node->key < key)
    {
        return search(node->right, key);
    }
    else
    {
        return search(node->left, key);
    }
}

struct node *mini(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct node *maxi(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

struct node *delete(struct node *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key < k)
    {
        root->left = delete(root->left, k);
        return root;
    }
    else if (root->key > k)
    {
        root->right = delete(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct node *succparent = root;
        struct node *succ = root->right;
        while (succ->left != NULL)
        {
            succparent = succ;
            succ = succ->left;
        }
        if (succparent != root)
            succparent->left = succ->right;
        else
            succparent->right = succ->right;
        root->key = succ->key;
        free(succ);
        return root;
    }
}

void Display(struct node *root)
{
    if (root != NULL)
    {
        Display(root->left);
        printf("%d ", root->key);
        Display(root->right);
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return 1 + (leftheight > rightheight ? leftheight : rightheight);
    }
}

int depth(struct node *root, int data, int currentDepth)
{
    if (root == NULL)
    {
        return -1;
    }
    if (data == root->key)
    {
        return currentDepth;
    }
    else if (data < root->key)
    {
        return depth(root->left, data, currentDepth + 1);
    }
    else
    {
        return depth(root->right, data, currentDepth + 1);
    }
}


void diameter(struct node *node)
{
    if (node == NULL)
    {
        printf("0\n");
        return;
    }

    int t = height(node->left);
    int s = height(node->right);
    int diameter = 3 + t + s;
    printf("%d\n", diameter);
}

int main()
{
    struct node *root = NULL;

    // Insert elements into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the elements of the tree
    printf("In-order traversal of the tree:\n");
    Display(root);
    printf("\n");

    // Search for a key in the tree
    int key_to_search = 40;
    struct node *result = search(root, key_to_search);
    if (result != NULL)
    {
        printf("%d found in the tree.\n", key_to_search);
    }
    else
    {
        printf("%d not found in the tree.\n", key_to_search);
    }

    // Find the minimum and maximum elements in the tree
    struct node *min_node = mini(root);
    struct node *max_node = maxi(root);
    printf("Minimum element in the tree: %d\n", min_node->key);
    printf("Maximum element in the tree: %d\n", max_node->key);

    // Delete a node from the tree
    int key_to_delete = 30;
    root = delete(root, key_to_delete);
    printf("In-order traversal after deleting %d:\n", key_to_delete);
    Display(root);
    printf("\n");

    // Calculate and display the height of the tree
    int tree_height = height(root);
    printf("Height of the tree: %d\n", tree_height);

    // Calculate and display the depth of a specific node
    int key_to_find_depth = 60;
    int node_depth = depth(root, key_to_find_depth, 0);
    if (node_depth != -1)
    {
        printf("Depth of node %d: %d\n", key_to_find_depth, node_depth);
    }
    else
    {
        printf("Node %d not found in the tree.\n", key_to_find_depth);
    }

    // Calculate and display the diameter of the tree
    printf("Diameter of the tree: ");
    diameter(root);

    return 0;
}

