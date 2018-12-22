#pragma once
#include "Vector.h"
#include <queue>

template <typename T>
class queue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	queue();                             // default initializes the queue
	queue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();                           // returns the front-most element
	T& back();                            // returns the back-most element

	size_t size() const;                  // returns current number of elements

	const T& front() const;
	const T& back() const;

	bool empty() const;

};

	template<typename T>
	inline queue<T>::queue()
	{
	}
	template<typename T>
	inline queue<T>::queue(size_t count, const T & value)
	{
		for (int i = 0; i < count; i++) {
			vec.push_back(value);
			std::cout << value << std::endl;
		}
	}
	// adds an element to the top of the Queue
	template<typename T>
	inline void queue<T>::push(const T & value)
	{
		vec.push_back(value);
		std::cout << value << std::endl;
	}
	// drops the top-most element of the Queue
	template<typename T>
	inline void queue<T>::pop()
	{
		for (int i = 0; i < size() - 1; i++) {
			vec.at(i) = vec.at(i + 1);
			std::cout << vec.at(i + 1) << std::endl;
		}
	}
	// returns the front-most element
	template<typename T>
	inline T & queue<T>::front()
	{
		return vec.at(0);
	}
	// returns the back-most element
	template<typename T>
	inline T & queue<T>::back()
	{
		return vec.at(vec.size() - 1);
	}
	// returns current number of elements
	template<typename T>
	inline size_t queue<T>::size() const
	{
		return vec.size();
	}

	template<typename T>
	inline const T & queue<T>::front() const
	{
		return vec.at(0);
	}

	template<typename T>
	inline const T & queue<T>::back() const
	{
		return vec.at(vec.size() - 1);
	}

	template<typename T>
	inline bool queue<T>::empty() const
	{
		if (size() == 0) {
			return false;
		}
		else
		{
			return true;
		}
	}