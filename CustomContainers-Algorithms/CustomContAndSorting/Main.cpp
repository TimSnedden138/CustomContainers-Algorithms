#include<iostream>
#include"Queue.h"
#include"Stack.h"
#include"LinkedList.h"
#include"Vector.h"
#include"Merge.h"

int sortarr[8]{25,14,42,15,1666,147,45,222222 };

int main()
{
	tForwardList<int> link;
	tVector<int> tV;
	queue<int> tQ;
	tStack<int> stackObject;
	std::cout << "VECTOR"<<std::endl;
	tV.push_back(420);
	tV.push_back(1985);
	tV.push_back(1766);
	tV.push_back(55555);
	tV.pop_back();
	tV.push_back(2018);
	tV.push_back(2);

	tVector<int> tVCopy = tV;

	int tVectorSize = tV.size();
	int tVectorCapacity = tV.capacity();
	for (int i = 0; i < tV.size(); i++) 
	{
		std::cout << tV.at(i) << std::endl;
	}
	for (int i = 0; i < tVCopy.size(); i++) 
	{
		std::cout << tV.at(i) << std::endl;
	}
	std::cout << "Size = " << tV.size() << std::endl;
	std::cout << "Capacity = " << tV.capacity() << std::endl;
	std::cout << "Queue" << std::endl;;
	tQ.push(10);
	tQ.push(99);
	tQ.push(454);
	tQ.push(22);
	tQ.push(99);
	std::cout << "Front: " << tQ.front() << std::endl;
	std::cout << "Back: " << tQ.back() << std::endl;
	tQ.pop();
	std::cout << "Front: " << tQ.front() << std::endl;
	std::cout << "Back: " << tQ.back() << std::endl;
	std::cout << "Size: " << tQ.size() << std::endl;
	std::cout << "LINKED LISTS" << std::endl;
	link.push_front(2);
	link.push_front(57);
	link.push_front(89);
	link.remove(89);
	link.push_front(42);
	std::cout << "STACKS" << std::endl;
	std::cout << "Numbers In Our Stack" << std::endl;
	stackObject.push(28);
	std::cout << stackObject.top() << std::endl;
	stackObject.push(91);
	std::cout << stackObject.top() << std::endl;
	stackObject.push(64);
	std::cout << stackObject.top() << std::endl;
	stackObject.push(61);
	std::cout << stackObject.top() << std::endl;
	stackObject.push(34);
	std::cout << stackObject.top() << std::endl;
	std::cout << "Size: " << stackObject.size() << std::endl;
	std::cout << "Top: " << stackObject.top();
	std::cout << std::endl;
	std::cout << "\nRemove(pop) two from top of stack" << std::endl;
	stackObject.pop();
	stackObject.pop();
	std::cout << "\nNew Size: " << stackObject.size() << std::endl;
	std::cout << "New Top: " << stackObject.top() << std::endl;

	for (auto it = link.begin(); it != link.end(); ++it) {
		std::cout << (*it) << std::endl;
	}
	std::cout << link.front() << std::endl;
	std::cout << "MERGE SORT" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "Original:" << sortarr[i] << std::endl;
	}
	MergeSort(sortarr, 0, 7);
	for (int i = 0; i < 8; i++) {
		std::cout << "Stored:" << sortarr[i] << std::endl;
	}
	return 0;
}
