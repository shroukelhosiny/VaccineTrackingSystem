#include "linkedlist.h"
#include <assert.h>
#include"user.h"
template <class T>
Node<T>::Node()
{
	value=0;
	next=0;
}

template <class T>
Node<T>::Node(T val)
{
	value=val;
	next=0;
}

template <class T>
linkedlist<T>::linkedlist()
{
	head=tail=0;
	count=0;
}

template <class T>
int linkedlist<T>::Length()
{
	return count;
}

template <class T>
void linkedlist<T>::Append(T val)
{

	Node<T>* tmp = new Node<T>(val);

	if(head==NULL)
		head=tail=tmp;
	else //if the list is not empty
	{
		tail->next=tmp;
		tail=tmp;
	}

	count++;

}

template <class T>
T linkedlist<T>::At(int pos)
{
	assert(pos>=0&&pos<count);
	Node<T>* tmp=head;
	for(int i=0;i<pos;i++)
		tmp=tmp->next;
	return tmp->value;
}

template <class T>
void linkedlist<T>::InsertAt(int pos, T val)
{
	assert(pos>=0&&pos<count);
	Node<T>* tmp=head;
	Node<T>* newNode=new Node<T>(val);
	if(pos==0)
	{
		newNode->next=head;
		head=newNode;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			tmp=tmp->next;

		newNode->next=tmp->next;
		tmp->next=newNode;
	}
	count++;
}

template <class T>
void linkedlist<T>::DeleteAt(int pos)
{
    assert(pos>=0&&pos<count);
	Node<T>* tmp=head;
	if(pos==0)
	{
		head=head->next;
		delete tmp;

	}
	else
	{
		for(int i=0;i<pos-1;i++)
			tmp=tmp->next;
		Node<T>* del=tmp->next;
		tmp->next=del->next;
		delete del;
		if(pos==count-1)
			tail=tmp;
	}
count--;
}




template <class T>
linkedlist<T>::~linkedlist(void)
{
	while(count!=0)
		DeleteAt(0);
}


