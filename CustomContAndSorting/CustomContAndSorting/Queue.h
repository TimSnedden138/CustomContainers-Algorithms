#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity
#define SIZE 10
template <class T>
class queue 
{
	T *arr; 		// Array for Storing
	int capacity;   // Capacity of the queue
	int frontA;  	// Front element
	int rear;   	// Rear Element
	int count;  	// Current Size

public:
	queue(int size = SIZE);

	void dequeue();
	void enqueue(T& item);
	T peek();
	int size() const;
	bool isEmpty();
	bool isFull();

	T& front();                           // returns the front-most element
	T& back();                            // returns the back-most element
};

// Constructor
template <class T>
queue<T>::queue(int size)
{
	arr = new T[size];
	capacity = size;
	frontA = 0;
	rear = -1;
	count = 0;
}

//Remove Element
template <class T>
void queue<T>::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "Program is being fixed";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[frontA] << '\n';

	frontA = (frontA + 1) % capacity;
	count--;
}

//Add Element
template <class T>
void queue<T>::enqueue(T& item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "Program is being fixed";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

//Return Element
template <class T>
T queue<T>::peek()
{
	if (isEmpty()) 
	{
		cout << "Program is being fixed";
		exit(EXIT_FAILURE);
	}
	return &arr[frontA];
}

//Return Size
template <class T>
int queue<T>::size() const
{
	return count;
}

//Return if the queue is empty or not
template <class T>
bool queue<T>::isEmpty()
{
	return (size() == 0);
}

//Return if the queue is full or not
template <class T>
bool queue<T>::isFull()
{
	return (size() == capacity);
}

template<class T>
inline T & queue<T>::front()
{
	return arr[frontA];
}

template<class T>
inline T & queue<T>::back()
{
	return arr[back];
}
