#include "queuelist.h"
#include<iostream>
#include <assert.h>
#include<iostream>
using namespace std;

template <class t>
 queuelist<t>::queuelist(){
    front = back = -1;
    size = 10;
    count = 0;
    data = new t[size];

}

template <class t>
bool queuelist<t>::full() {

    return (count == size);
}

template <class t>
bool queuelist<t>::empty() {

    return (count == 0);
}

template <class t>
void queuelist<t>::enqueue(t s) {
    assert(!full());
	if(count==0)
		front=0;
	back=(back+1)%size;
	data[back]=s;
	count++;

}

template <class t>
void queuelist<t>::dequeue() {

    if (empty())
        cout << "not found users" << endl;
    else if (front == back) {
        front = back = -1;
    }
    else {

        front = (front + 1) % size;
    }
    count--;

}

template <class t>
void queuelist<t>::expand() {
    size *= 2;
    t* tmp = new t[size];
    for (int i = 0; i < count; i++)
        tmp[i] = data[i];
    delete data;
    data = tmp;
}

template <class t>
t queuelist<t>::Front(){
	assert(!empty());
  	return data[front];
}

template <class t>
queuelist<t>::~queuelist()
{
	delete[] data;
}
