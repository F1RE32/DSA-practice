#include <iostream>
using namespace std;
#include <stdlib.h>

struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode** node, int inp)
{
    if (*node == NULL)
    {
        BSTNode* curr = new BSTNode;
        curr->value = inp;
        curr->left = curr->right = NULL;
        return curr;
    }
    if (inp < (*node)->value)
    {
        (*node)->left = insert(&((*node)->left), inp);
    }
    else
    {
        (*node)->right = insert(&((*node)->right), inp);    
    }
    return *node;
}

void searchtree(BSTNode*  node, int inp)
{
    if (node == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }
    if (inp == node->value)
    {
        cout << "Value Found"  << endl;
        return;
    }
    if (inp < node->value)
    {
        searchtree(node->left, inp);
    }
    else 
    {
        searchtree(node->right, inp);
    }
}

void inordertrav(BSTNode*  node)
{
	if (node != NULL)
	{
		inordertrav(node->left);
		cout << node->value << endl;
		inordertrav(node->right);
	}
}

void preordertrav(BSTNode*  node)
{
	if (node != NULL)
	{
		cout << node->value << endl;
		inordertrav(node->left);
		inordertrav(node->right);
	}
}

void postordertrav(BSTNode*  node)
{
	if (node != NULL)
	{
		inordertrav(node->left);
		inordertrav(node->right);
		cout << node->value << endl;
	}
}

BSTNode* findmin(BSTNode*  node)
{
	node = node->right;
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

BSTNode* findmax(BSTNode*  node)
{
	node = node->left;
	while (node->right != NULL)
	{
        node = node->right;
	}
	return node;
}

BSTNode* deleteBSTvalue(BSTNode* node, int todel)
{
	if (node == NULL)
	{
		cout << "Not Exist" << endl;
		return node;
	}
	if (todel < (node)->value)
	{
		node->left = deleteBSTvalue(node->left, todel);
	}
	else if(todel > node->value)
	{
		node->right = deleteBSTvalue(node->right, todel);  
	}
	else
	{
		if (node->left == NULL)
		{
			BSTNode* temp = node->right;
			free (node);
			return temp;
		}
		else if (node->right == NULL)
		{
			BSTNode* temp = (node)->left;
			free(node);
			return temp;
		}
		else
		{
			BSTNode* temp = findmin(node);
			node->value = temp->value;
			node->right = deleteBSTvalue(node->right, temp->value); 
			return node;
		}
	}
}

int main ()
{
    BSTNode* Root = NULL;
    int inp;
    cout << "Tree is initially empty, Insert a value: ";
    cin >> inp;
    Root = insert(&Root, inp);
    cout << "Press 1 to Insert, 2 to Search, 0 to Exit" << endl;
    int select;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
        	cout << "VALUE INSERTION" << endl;
            cout << "Insert the value: ";
            cin >> inp;
            insert(&Root, inp);
        }
        if (select == 2)
        {
        	cout << "VALUE SEARCHING" << endl;
        	cout << "Insert the value: ";
            cin >> inp;
            searchtree(Root, inp);
        }
        if (select == 3)
        {
        	int trav;
        	cout << "TREE PRINT" << endl;
        	cout << "Press 31 for Inorder, 32 for Preorder or 33 for Postorder Traversal: ";
        	cin >> trav;
        	if (trav == 31)
        	{
        		inordertrav(Root);
			}
			if (trav == 32)
        	{
        		preordertrav(Root);
			}
			if (trav == 33)
        	{
        		postordertrav(Root);
			}
		}
		if (select == 4)
		{
			int minmax;
        	cout << "FINDING MIN/MAX" << endl;
        	cout << "Press 41 to find minimum, 42 to find maximum: ";
        	cin >> minmax;
        	if (minmax == 41)
        	{
        		BSTNode* min = findmin(Root);
        		cout << min->value << endl;
			}
			if (minmax == 42)
        	{
        		BSTNode* max = findmax(Root);
        		cout << max->value << endl;
			}
		}
		if (select == 5)
		{
			int todel;
			cout << "Value Deletion: ";
			cin >> todel;
			deleteBSTvalue(Root, todel);
		}
        cout << "Press 1 to Insert, 2 to Search, 3 to Traverse, 4 to find Minimum/Maximum, 5 to Delete or 0 to Exit" << endl;
        cin >> select;
    }
    return 0;
}
