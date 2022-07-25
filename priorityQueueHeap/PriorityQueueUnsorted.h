#include "PriorityQueueADT.h"
#include <iostream>
#include <vector>
class PriorityQueueUnsorted : public PriorityQueueADT{
private:
	std::vector<int> _arr;
public:
	PriorityQueueUnsorted();
	~PriorityQueueUnsorted();
    bool empty();
	int size();
	int top();
	void push(int);
	void pop();
};
