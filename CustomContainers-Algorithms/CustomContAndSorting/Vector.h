#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the tVector's default values
	~tVector();
	tVector& operator=(const tVector &vec); // copies the contents of the provided vector into this vector
	tVector(const tVector& vec);

	T *data();                          
	void reserve(size_t newCapacity);   // resizes the tVector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the Vector
	void pop_back();                    // drops the last element of the Vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
	bool empty() const;                 // Returns true if the vector contains no elements.
	void resize(size_t);                // Resizes the vector to contain the given number of elements.
	void shrink_to_fit();               // Resizes the vector's capacity to match its size.
	void clear();                       // Empties the vector (all elements are destroyed in this process)
	T& operator[] (size_t index); // returns the object at the given index

};
// initializes the tVector's default values
template<typename T>
inline tVector<T>::tVector()
{
	arr = new T[20];
	arrSize = 0;
	arrCapacity = 20;
}
// Deletes the tVector's default valuess
template<typename T>
inline tVector<T>::~tVector()
{
	delete arr;
}
template<typename T>
inline tVector<T> & tVector<T>::operator=(const tVector & vec)
{
	// TODO: insert return statement here
		arr = new T[vec.arrCapacity];
	
		for (size_t i = 0; i < vec.arrSize; i++)
		{
			arr[i] = vec.arr[i];
		}
		arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;
}
// Makes a copy of the tVector's default values
template<typename T>
inline tVector<T>::tVector(const tVector &vec)
{
	arr = new T[vec.arrCapacity];
	for(size_t i = 0; i < vec.size(); i++){
	arr[i] = vec.arr[i];
}
	arrSize = vec.size();
	arrCapacity = vec.capacity();
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}
//Resizes the Vector
template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (newCapacity > arrCapacity) {
		T *reserveTempArr;
		reserveTempArr = new T[newCapacity];

		for (int i = 0; i < newCapacity; i++) {
			reserveTempArr[i] = arr[i];
		}
		delete[] arr;
		arr = reserveTempArr;
		arrCapacity = newCapacity;
	}
	else {
		std::cout << "Reserve size is less than arrCapacity." << "\nArray Capacity = " << arrCapacity << std::endl;
	}
}
//Add Element
template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity) {
		reserve(arrCapacity * GROWTH_FACTOR);
	}

	arr[arrSize] = value;
	arrSize++;
}
//Pop Front
template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
return arr[index];
}
//Return Current Amount of Elements
template<typename T>
inline size_t tVector<T>::size() const
{
	return size_t(arrSize);
}
// Returns Maximum Number of Elements
template<typename T>
inline size_t tVector<T>::capacity() const
{
	return size_t(arrCapacity);
}
// Returns true if the vector contains no elements
template<typename T>
inline bool tVector<T>::empty() const
{
	if (arrSize == 0)
	{
		std::cout << "Empty" << std::endl;
		return true;
	}
	std::cout << "Not empty" << std::endl;
	return false;
}
// Resizes the vector to contain the given number of elements.
template<typename T>
inline void tVector<T>::resize(size_t)
{
	if (newSize < arrSize)
	{
		arrSize = newSize;
	}
	else
	{
		for (size_t i = arrSize; i < newSize; i++)
		{
			push_back(T());
		}
	}
}
// Resizes the vector's capacity to match its size.
template<typename T>
inline void tVector<T>::shrink_to_fit()
{
	if (arrCapacity = arrSize)
	{
		return;
	}
	T *temp = new T[arrSize];
	for (size_t i = 0; i < arrSize; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;

	arr = temp;
	arrCapacity = arrSize;
}
// Empties the vector (all elements are destroyed in this process)
template<typename T>
inline void tVector<T>::clear()
{
	arrSize = 0;
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	return arr[index];
}
