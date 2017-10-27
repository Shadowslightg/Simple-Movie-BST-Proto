#include <iostream>

using namespace std;

struct NODE
{
	int key_value;
	NODE * pleft;
	NODE * pright;
};

class btree
{
public:
	btree();	//constructor
	~btree();	//destructor

	void insert (int key);	
	NODE * search (int key);
	void destroy_tree();

private:
	void destroy_tree(NODE * leaf);
	void insert(int key, NODE * leaf)
	NODE * search (int key, NODE * leaf);
	
	NODE *root;
};

btree::btree()
{
	root = NULL;
}
btree::~btree()
{
	destroy_tree();
}

//this function will delete all the nodes of the tree
void btree::destroy_tree(NODE * leaf)
{
	if (leaf != NULL)
	{
		destroy_tree (leaf -> left);
		destroy_tree (leaf -> right);
		delete leaf;
	}
}

void btree::insert (int key, NODE * leaf)
{
	if (key < leaf -> key_value)
	{
		if (leaf -> left != NULL)
			insert (key, leaf -> left);
		else
		{
			leaf -> left = new NODE;
			leaf -> left -> key_value = key;
			leaf -> left -> left = NULL;	//sets the left child of the child node to NULL
			leaf -> left -> right = NULL;	//sets the right child of the child node to NULL
		}
	}
	else if (key >= leaf -> key_value)
	{
		if (leaf -> right != NULL)
		{
			insert (key, leaf-> right);
		}
		else
		{
			leaf -> left =new NODE;
			leaf -> right -> key_value=key;
			leaf -> right -> left = NULL;	//sets the left child of the child node to NULL
			leaf -> right -> right = NULL;	//sets the right child of the child node to NULL
		}
	}
}

NODE *btree::search (int key, NODE * leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf -> key_value)
		{
			return leaf;
		}
		if (key < leaf -> key_value)
		{
			return search( ket, leaf->right);
		}
		else 
		{
			return search (key, leaf->right);
		}
	else return NULL;
	}
}

void btree::insert(int key)
{
	if (root !=NULL)
	{
		insert (key, root);
	}
	else
	{
		root = new NODE;
		root -> key_value = key;
		root -> left = NULL;
		root -> right = NULL;
	}
}

NODE * btree::search( int key)
{
	return search(key, root);
}

void btree::destroy_tree()
{
	destroy_tree (root);
}
