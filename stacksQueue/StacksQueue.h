#include "ADTQueue.h"
#include <vector>
#include "Iterador.h"
class StacksQueue : public ADTQueue{
public:
	StacksQueue();
	~StacksQueue();
	void push(int);
	void pop();
	int front();
	bool empty();
	int size();
	Iterador begin();
private:
	int aux;
	int* inicio;
	int* final;
	std::vector<int> stack1,stack2;
	Iterador* it;
};