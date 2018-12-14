#pragma once

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements

	template<typename T>
	inline tStack<T>::tStack()
	{
	}

	template<typename T>
	inline void tStack<T>::push(const T & value)
	{
		Node *tmp;
		tmp = new (struct Node);
		tmp->info = item;
		tmp->link = top;
		top = tmp;
		return top;

	}

	template<typename T>
	inline void tStack<T>::pop()
	{
		Node *tmp;
		if (top == NULL)
			cout << "Stack is Empty" << endl;
		else
		{
			tmp = top;
			cout << "Elements: " << tmp->info << endl;
			top = top->link;
			delete(tmp);
		}
	}

	template<typename T>
	inline T & tStack<T>::top()
	{
		return top;
	}

	template<typename T>
	inline size_t tStack<T>::size() const
	{
		return vec.size;
	}
};