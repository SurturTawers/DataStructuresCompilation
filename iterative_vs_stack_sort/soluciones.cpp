#include <iostream>
#include "soluciones.h"
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
soluciones::soluciones(){
}
soluciones::~soluciones(){
}
int soluciones::solucionUno(int i, int* array){
	for(int j=i;j<sizeof(array)/sizeof(array[0]);j++){
			if(array[j]>array[i]){
				return array[j];
			}
		}
		return -1;
}
int soluciones::solucionDos(int i, int* array){
	stackMayor.push(array[i]);
	for(int j=i;j<sizeof(array)/sizeof(array[0]);j++){
		if(array[j]>stackMayor.top()){
			stackMayor.pop();
			return array[j];
		}
	}
	return -1;
}