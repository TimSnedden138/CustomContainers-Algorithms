#pragma once
#include <iostream>
template<typename T>
class tForwardList
{
	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;

public:
	tForwardList();
	~tForwardList();

	void push_front(const T& val);
	void pop_front();

	T& front();
	const T& front() const;

	void remove(const T& val);
};

template<typename T>
inline tForwardList<T>::tForwardList()
{
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node *temp = new Node;
	temp->data = val;
	temp->next = head;
	head = temp;
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	Node *temp = new Node;
	if (head == NULL) {
		return;
	}
	temp = head->next;
	delete head;
	head = temp;
}

template<typename T>
inline T & tForwardList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	// TODO: insert return statement here
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	Node *temp = new Node;
	if (head == NULL) {
		return;
	}
	else if (head->data == val) {
		temp = head->next;
		delete head;
		head = temp;
	}
	else {
		head = head->next;
	}
}
