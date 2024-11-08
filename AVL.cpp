#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
	int height;
};

void init(Node*& root)
{
	root = NULL;
}

Node* createNode(int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	tmp->height = 1;


	return tmp;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int getHeight(Node* root)
{
	if (root == NULL)  return 0;
	return root->height;
}

void updateHeight(Node*& root)
{
	if (root != NULL)
	{
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	}
}

void rightRotate(Node*& root)
{
	Node* x = root->left;
	root->left = x->right;
	x->right = root;

	// cap nhat chieu cao
	updateHeight(root);
	updateHeight(x);

	root = x;
}

void leftRotate(Node*& root)
{
	Node* x = root->right;
	root->right = x->left;
	x->left = root;

	// cap nhat chieu cao
	updateHeight(root);
	updateHeight(x);

	root = x;
}

int getBalance(Node* root)
{
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

void insertNode(Node*& root, int data)
{
	if (root == NULL)
		root = createNode(data);
	else if (data > root->data)
		insertNode(root->right, data);
	else if (data < root->data)
		insertNode(root->left, data);

	else
		return;

	updateHeight(root);
	int value = getBalance(root);

	if (value > 1 && data < root->left->data)
	{
		// lech trai trai
		rightRotate(root);
	}
	else if (value > 1 && data > root->left->data)
	{
		// lech trai phai
		leftRotate(root->left);
		rightRotate(root);
	}
	else if (value <-1 && data > root->right->data)
	{
		// lech phai
		leftRotate(root);
	}
	else if (value < -1 && data< root->right->data)
	{
		// lech phai trai
		rightRotate(root->right);
		leftRotate(root);
	}

}

void searchStand(Node*& cur, Node*& temp)
{
	if (temp->left != NULL)
	{
		searchStand(cur, temp->left);
	}
	else
	{
		cur->data = temp->data;
		cur = temp;
		temp = temp->right;
	}
}

void delNode(Node*& root, int key)
{
	if (root == NULL)
		return;
	if (key > root->data)
		delNode(root->right, key);
	else if (key < root->data)
		delNode(root->left, key);
	else
	{
		Node* cur = root;
		// node la or node bac 1
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
		{
			root = root->left;
		}
		else
		{
			searchStand(cur, root->right);
		}
		delete cur;
	}

	if (root == NULL)
		return;
	updateHeight(root);
	int value = getBalance(root);

	if (value > 1 && getBalance(root->left) >=  0)
	{
		// lech trai trai
		rightRotate(root);
	}
	else if (value > 1 && getBalance(root->left) < 0)
	{
		// lech trai phai
		leftRotate(root->left);
		rightRotate(root);
	}
	else if (value <-1 && getBalance(root->right) <= 0)
	{
		// lech phai
		leftRotate(root);
	}
	else if (value < -1 && getBalance(root->right) > 0)
	{
		// lech phai trai
		rightRotate(root->right);
		leftRotate(root);
	}
}

void LNR(Node* root)
{
	if (root != NULL)
	{
		LNR(root->left);
		cout << root->data << "(" << root->height << ") ";
		LNR(root->right);
	}
}


int main()
{
	Node* root;
	init(root);
	insertNode(root, 40);
	insertNode(root, 20);
	insertNode(root, 10);
	insertNode(root, 45);
	insertNode(root, 19);
	insertNode(root, 42);
	insertNode(root, 30);

	LNR(root);
	



	return 0;
}

