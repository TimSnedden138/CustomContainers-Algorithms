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
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int j);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};
public:
		iterator begin();
		iterator end();

public:
	tForwardList();
	~tForwardList();

	void push_front(const T& val);    // adds element to front (i.e. head)
	void pop_front();				 // removes element from front

	T& front();				 // returns the element at the head
	const T& front() const; // returns the element at the head (const)

	void remove(const T& val); // removes all elements equal to the given value

	void resize();				//Resizes the linked list to contain the given number of elements
	void display();
	void clear();                   // Destroys every single node in the linked list
	bool empty() const;             // Returns true if there are no elements
};

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = NULL;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	Node *temp = NULL;
	while(head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	std::cout << "its clear" << std::endl;

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
	return head->data;
}

template<typename T>
inline void tForwardList<T>::resize()
{
	Node *temp = new Node;

	for (size_t i = 0; i < newSize; i++)
	{
		temp->next = head;
		temp->data = 0;

		head = temp;
	}
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

template<typename T>
inline void tForwardList<T>::display()
{
	Node *temp = new Node;					
	temp = head;							
	while (temp != NULL) {					
		std::cout << temp->data << "\t";	
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void tForwardList<T>::clear()
{
	ode *temp = new Node;

	if (head != NULL)
	{
		if (head == NULL)
		{
			return;
		}

		temp = head->next;
		delete head;

		head = temp;
	}
}

template<typename T>
inline bool tForwardList<T>::empty() const
{
	if (head == NULL) {
		return true;
	}
	return false;
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	return iterator(head);
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::end()
{
	return iterator(NULL);
}

template<typename T>
inline tForwardList<T>::iterator::iterator() {
	cur = NULL;
}

template<typename T>
inline tForwardList<T>::iterator::iterator(Node * startNode) {
	cur = startNode;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator==(const iterator & rhs) const {
	if (cur == rhs.cur) {
		return true;
	}
	return false;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator!=(const iterator & rhs) const {
	if (cur != rhs.cur) {
		return true;
	}
	return false;
}

template<typename T>
inline T & tForwardList<T>::iterator::operator*() const {
	return cur->data;
}

template<typename T>
typename tForwardList<T>::iterator & tForwardList<T>::iterator::operator++() 
{
	cur = cur->next;
	return *this;
}


template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int j)
{
	iterator temp;
	temp.cur = this->cur;
	for (int i = 0; i < j; i++) {
		temp.cur = temp.cur->next;
	}
	return temp;
}