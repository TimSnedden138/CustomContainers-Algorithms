#pragma once
#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();							// initializes the vector's default values
	~tVector();   // destroys the underlying array
	tVector(const tVector&);
	T *data();                          // returns a pointer to the underlying array
	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements
	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector
	T &at(size_t index);                // returns the element at the given element
	tVector(const tVector &vec);
	T& operator[] (size_t index);
	void resize(size_t newsize);		// Resizes the vector to contain the given number of elements.
	void shrink_to_fit();				// Resizes the vector's capacity to match its size.
	void clear();						// Empties the vector (all elements are destroyed in this process)
	bool empty();						// Returns true if the vector contains no elements.
	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template<typename T>
tVector<T>::tVector()
{
	arr = nullptr;
	arrSize = 0;
	arrCapacity = 10;
}

template<typename T>
tVector<T>::~tVector()
{
	delete[] arr;
	
}

template<typename T>
T * tVector<T>::data()
{
	return arr;
}

template<typename T>
void tVector<T>::reserve(size_t newCapacity)
{
	if (!(newCapacity > arrCapacity)) { return; }

	T* temp = new T[newCapacity];

	for (size_t i = 0; i < arrSize; i++) {
		temp[i] = arr[i];
	}

	arrCapacity = newCapacity;
	delete[] arr;
	arr = temp;
}

template<typename T>
void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity) {
		reserve(value);
	}
	else {
		reserve(arrCapacity * GROWTH_FACTOR);
	}
	arr[arrSize] = value;
	++arrSize;

}

template<typename T>
void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
T & tVector<T>::at(size_t index)
{
	return(arr[index]);

}

template<typename T>
tVector<T>::tVector(const tVector & vec)
{
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	return at(index);
}


template<typename T>
void tVector<T>::resize(size_t newsize)
{
	if (newsize > arrCapacity) {
		return;
	}
	else {
		arrCapacity = newsize;
	}
}

template<typename T>
void tVector<T>::shrink_to_fit()
{
	arr = new * arr;
	arr
	arrCapacity = arrSize;
}

template<typename T>
void tVector<T>::clear()
{
	arrSize = 0;
}

template<typename T>
bool tVector<T>::empty()
{
	if (arrSize == 0) {
		return true;
	}
	else {
		return	false;
	}
}

template<typename T>
size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
size_t tVector<T>::capacity() const
{
	return arrCapacity;
}
