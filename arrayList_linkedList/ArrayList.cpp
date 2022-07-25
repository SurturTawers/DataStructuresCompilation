#include "ArrayList.h"
//#include <bits/stdc++>
#include <iostream>
using namespace std;

ArrayList::ArrayList(){
	this->mysize=0;
	this->capacity=1;
	this->myarray=(int*)malloc(sizeof(int));
}

ArrayList::~ArrayList(){
	if(this->mysize!=0){
		delete[] this->myarray;
	}
}
void ArrayList::agrandar(){
		this->capacity*=2;
		int* aux=(int*)malloc(sizeof(int)*(this->capacity));
		for(int i=1;i<=mysize;i++){
			aux[i]=this->myarray[i-1];
		}
		delete[] this->myarray;
		this->myarray=aux;
}

void ArrayList::insert(int n){
	if(this->mysize==this->capacity){
		this->agrandar();
		this->myarray[0]=n;
		this->mysize++;
	}else{
		for(int i=this->mysize-1;i>=0;i--){
			this->myarray[i+1]=this->myarray[i];
		}
		this->myarray[0]=n;
		this->mysize++;
	}
}

void ArrayList::pop(){
	if(mysize>0){
		this->myarray[mysize-1]=0;
		this->mysize--;
	}
}

int ArrayList::at(int pos){
	if(pos<this->mysize && pos>=0){
		return this->myarray[pos];
	}else return -1;
}

int ArrayList::size(){
	return this->mysize;
}