//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
	this->vec = new int[n];

	srand(time(NULL));

	for(int i=0;i<n;i++) {
		this->vec[i] = rand() % n + 1;
	}
	this->tam = n;
	sort(this->vec,this->vec + this->tam);

	/*
	for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
	puts("");
	*/
}

Busqueda::~Busqueda(){
	delete[] this->vec;
}
int Busqueda::size(){
	return this->tam;
}

int Busqueda::lineal(int num){
	for (int i=0;i<this->size();i++){
		if(this->vec[i]==num){
			return i;
		}
	}
	return -1;
}

int Busqueda::binariaRecursiva(int num,int l,int r){
	int mid=(l+r)/2;
	if(l<=r){
		if(this->vec[mid]==num){
			return mid;
		}else if(this->vec[mid]<num){
			return this->binariaRecursiva(num,mid+1,r);
		}else if(this->vec[mid]>num){
			return this->binariaRecursiva(num,l,mid-1);
		}
	}
	return -1;
}

int Busqueda::binariaIterativa(int num){
	int l=0, r=(this->size())-1, mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(this->vec[mid]==num){
			return mid;
		}else if(this->vec[mid]<num){
			l=mid+1;
		}else if(this->vec[mid]>num){
			r=mid-1;
		}
	}
	return -1;
}

int Busqueda::binariaRecursiva(int num){
	return binariaRecursiva(num,0,tam-1);
}