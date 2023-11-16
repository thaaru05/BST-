#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*) malloc (sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void inorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

void preorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
    printf("%d ", node->data);
	preorder(node->left);	
	preorder(node->right);
}

void postorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Enter your choice:\n");
	printf("1. Inorder\n");
	printf("2. Preorder\n");
	printf("3. Postorder\n");
	printf("4. Exit\n");

	int n;
	scanf("%d", &n);

	switch(n) {
		case 1:
			inorder(root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			break;
		default:
			printf("Invalid choice\n");
	}

	return 0;
}

