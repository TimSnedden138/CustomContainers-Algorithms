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
	int front;  	// Front element
	int rear;   	// Rear Element
	int count;  	// Current Size

public:
	queue(int size = SIZE);

	void dequeue();
	void enqueue(T x);
	T peek();
	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor
template <class X>
queue<T>::queue(int size)
{
	arr = new T[size];
	capacity = size;
	front = 0;
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

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

//Add Element
template <class T>
void queue<T>::enqueue(T item)
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
	return arr[front];
}

//Return Size
template <class T>
int queue<T>::size()
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