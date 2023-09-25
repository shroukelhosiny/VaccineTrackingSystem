#ifndef QUEUELIST_H
#define QUEUELIST_H
template <class t>
class queuelist
{
 int size, count;
    int front, back;
    t* data;
public:
    queuelist();
    void enqueue(t s);
    void dequeue();
    bool empty();
    bool full();
    void expand();
    t Front();
   ~queuelist();
};

#endif // QUEUELIST_H
