#pragma once
template<typename T>
class tObjectPool
{
	ObjectPool();                       // default initializes the object pool
	ObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~ObjectPool();                      // destroys all objects
	T* pool;                            // all objects stored in the pool
	bool* free;                         // indicates whether an object is available

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
inline tObjectPool<T>::ObjectPool()
{
	pool = nullptr;
	count = 0;
}

template<typename T>
inline tObjectPool<T>::ObjectPool(size_t initialCapacity)
{
	pool = new T[initialCapacity];
	free = new bool[initialCapacity];
	for (int i = 0; i < initialCapacity; ++i)
	{
		free[i] = true;
	}
	count = initialCapacity;
}

template<typename T>
inline tObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline T * tObjectPool<T>::retrieve()
{
	for (int i = 0; i < count; i++)
	{
		if (free[i] == true)
		{
			free[i] = false;
			return &pool[i];
		}
	}

	return NULL;
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj)
{
	for (int i = 0; i < count; i++)
	{
		if (&pool[i] == obj)
		{
			free[i] = true;
			break;
		}
	}
}

}

template<typename T>
inline size_t tObjectPool<T>::capacity()
{
	return count;
}
