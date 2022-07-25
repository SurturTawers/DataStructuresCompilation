#include "List.h"

struct nodo {
	int n;
	nodo *siguiente;
	/*nodo(int num){
		n=num;
		siguiente=NULL;
	}*/
};

class LinkedList: public List {
	private:
		struct nodo *head;
		int mysize;
	public:
		LinkedList();
		~LinkedList();
		void insert(int n);
		void pop();
		int at(int pos);
		int size();
};

/*
Struct nodo *aux=(Struct nodo*)malloc(sizeof())
*/