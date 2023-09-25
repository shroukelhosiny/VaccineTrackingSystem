#ifndef BST_H
#define BST_H
#include <string>
using namespace std;
class node {
public:
	string value;
	node* left, * right;
	node();
	node(string v);
};


class BST
{
public:
	node* root;
	BST();
	bool contains(string v);
	void insert(string n);
};

#endif // BST_H
