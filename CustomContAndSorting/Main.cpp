//#include"Vector.h"
#include"Queue.h"
#include"LinkedList.h"
#include<iostream>
void MergeSort(int * arr, size_t p, size_t r);
void Merge(int * arr, size_t p, size_t q, size_t r);
int sortarr[8]{25,14,42,15,1666,147,45,28954 };

int main(){
	std::cout << "LINKED LISTS"<<std::endl;
	tForwardList<int> link;
	//tVector<int>tI;
	queue<int>tQ;
	link.push_front(2);
	link.push_front(57);
	link.push_front(89);
	link.push_front(42);
	link.remove(42);
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
void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
	size_t q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}
void Merge(int * arr, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;
	int * L = new int[leftEnd];
	int * R = new int[rightEnd];
	for (int i = 0; i < leftEnd; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = arr[q + j + 1];
	}
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if ((j >= rightEnd) || (i < leftEnd && L[i] <= R[j])) {
			arr[k] = L[i];
			i++;

		}
		else {
			arr[k] = R[j];
			j++;

		}

	}
	delete[] L;
	delete[] R;

}
