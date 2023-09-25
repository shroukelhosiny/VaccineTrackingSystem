#include "BST.h"
node::node() {
	value = "0";
	left = right = NULL;
}


node::node(string v) {
	value = v;
	left = right = NULL;
}


BST::BST() {
	root = NULL;
}


bool BST::contains(string v) {
	node* tmp = root;
	while (tmp != 0 && v != tmp->value)
	{
		if (v < tmp->value)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	return(tmp != 0);
}

void BST::insert(string v) {
	node* n = new node(v);
	if (root == 0)
		root = n;
	else {
		node* tmp = root;
		while (true)
		{


			if (v < tmp->value)
				if (tmp->left == 0) {
					tmp->left = n;
					break;
				}
				else
					tmp = tmp->left;
			else
				if (tmp->right == 0) {
					tmp->right = n;
					break;
				}
				else
					tmp = tmp->right;
		}
	}


}
