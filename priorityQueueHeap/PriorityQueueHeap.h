#include "PriorityQueueADT.h"
#include <iostream>
#include <vector>
class PriorityQueueHeap : public PriorityQueueADT{
private:
	std::vector<int> _arr;
public:
	PriorityQueueHeap();
	~PriorityQueueHeap();
	void UpHeap(std::vector<int>::iterator,int);
	void DownHeap(std::vector<int>::iterator,int);
	bool empty();
	int size();
	int top();
	void push(int);
	void pop();
};
