#ifndef ARRAYLIST_H
#define ARRAYLIST_H
template <class T>
class arraylist
{  T* arr;
	int size, count;
public:
	arraylist();
	int Length();
	void Append(T);
	void Expand();
	T At(int);
	void insertAt(int, T);
	void deleteAt(int);
	~arraylist(void);
};

#endif // ARRAYLIST_H
