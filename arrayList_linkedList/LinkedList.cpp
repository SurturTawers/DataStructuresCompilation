#include "LinkedList.h"
//#include <bits/stdc++>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
	this->mysize=0;
	this->head=NULL;
}

LinkedList::~LinkedList(){
	if(this->mysize!=0){
		struct nodo* actual=this->head;
		struct nodo* siguiente;
		cout<<this->mysize<<endl;
		while(actual!= NULL){
			siguiente=actual->siguiente;
			free(actual);
			actual=siguiente;
		}
		this->head=NULL;
	}
}

void LinkedList::insert(int n){
	struct nodo* aux=(struct nodo*)malloc(sizeof(struct nodo));
	aux->n=n;
	aux->siguiente=this->head;
	this->head=aux;
	this->mysize++;
}

void LinkedList::pop(){
	if(mysize>0){
		struct nodo* ultimo=this->head;
		struct nodo* anterior;
		while(ultimo->siguiente !=NULL){
			anterior=ultimo;
			ultimo=ultimo->siguiente;
		}
		if(ultimo!=head){
			anterior->siguiente=NULL;
		}
		free(ultimo);
		this->mysize--;
	}
}

int LinkedList::at(int pos){
	if(pos>=0 && pos<this->mysize){
		int count=0;
		struct nodo* elemento=this->head;
		while(count!=pos){
			elemento=elemento->siguiente;
			count++;
		}
		return elemento->n;
	}else return -1;
}

int LinkedList::size(){
	return this->mysize;
}