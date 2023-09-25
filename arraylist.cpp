#include "arraylist.h"
#include <assert.h>
#include <iostream>
template <class T>
arraylist<T>::arraylist()
{
	size=5;
	arr=new T[size];
	count=0;
}

template <class T>
int arraylist<T>::Length()
{
	return count;
}

template <class T>
void arraylist<T>::Append(T val)
{
	if(count==size)
		Expand();
	arr[count]=val;
	count++;
}

template <class T>
void arraylist<T>::Expand()
{
	size*=2; //define new capacity
	T* tmp=new T[size];
	for(int i=0; i<count;i++)
		tmp[i]=arr[i];
	delete arr; //release old space
	arr=tmp;
}

template <class T>
T arraylist<T>::At(int pos)
{
	assert(pos<count);
	return arr[pos];
}

template <class T>
void arraylist<T>::insertAt(int pos, T val)
{
	assert(pos<count);
	if(count==size)
		Expand();
	//shift elements to the right
	for(int i=count;i>pos; i--)
		arr[i]=arr[i-1];
	//insert value at required position
	arr[pos]=val;
	count++;
}

template <class T>
void arraylist<T>::deleteAt(int pos)
{
	assert(pos<count);
	//shift elements to the left
	for(int i=pos;i<count-1;i++)
		arr[i]=arr[i+1];
	count--;
}

template <class T>
arraylist<T>::~arraylist(void)
{
	delete[] arr;
}

