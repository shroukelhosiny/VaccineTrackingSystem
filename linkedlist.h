#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node
{
	public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};
template <class T>
class linkedlist
{   int count;
	Node<T>* head;
	Node<T>* tail;
public:
	linkedlist();
	int Length();
	T At(int);
	void InsertAt(int,T);
	void Append(T);
	void DeleteAt(int);
	~linkedlist(void);
};

#endif // LINKEDLIST_H
