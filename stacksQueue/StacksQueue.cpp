#include <vector>
#include "StacksQueue.h"
#include "Iterador.h"
using namespace std;
StacksQueue::StacksQueue(){
}
StacksQueue::~StacksQueue(){
	delete it;
}
void StacksQueue::push(int elem){
	while(!stack2.empty()){
		aux=stack2.back();
		stack1.push_back(aux);
		stack2.pop_back();
	}
	stack1.push_back(elem);
}
void StacksQueue::pop(){
	while(!stack1.empty()){
		aux=stack1.back();
		stack2.push_back(aux);
		stack1.pop_back();
	}
	stack2.pop_back();
}
int StacksQueue::front(){
	while(!stack1.empty()){
		aux=stack1.back();
		stack2.push_back(aux);
		stack1.pop_back();
	}
	return stack2.back();
}
bool StacksQueue::empty(){
	if(stack2.empty() && stack1.empty()){
		return true;
	}
	return false;
}
int StacksQueue::size(){
	if(stack1.empty()){
		return stack2.size();
	}
	return stack1.size();
}
Iterador StacksQueue::begin(){
	while(!stack2.empty()){
		aux=stack2.back();
		stack1.push_back(aux);
		stack2.pop_back();
	}
	inicio=&(stack1[0]);
	int tam=stack1.size()-1;
	final=&(stack1[tam]);
	it = new Iterador(inicio,final);
	return *it;
}