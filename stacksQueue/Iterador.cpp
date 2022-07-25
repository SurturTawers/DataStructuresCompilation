#include "Iterador.h"
#include <vector>
#include <iostream>
using namespace std;
Iterador::Iterador(int* inicio, int* final){
	iter=(vector<int>::iterator)inicio;
	end=/*(vector<int>::iterator)*/final;
}
Iterador::~Iterador(){

}
bool Iterador::hasNext(){
	if(iter==(vector<int>::iterator)end+1){
		return false;
	}
	return true;
}
int Iterador::next(){
	aux=*iter;
	iter++;
	return aux;
}