#include "LinkedList.h"
#include "List.h"
#include "ArrayList.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
int main(){
	int rep,num;
	double time;
	LinkedList a;
	ArrayList b;
	cout<<"Ingrese el numero de elementos: ";
	cin>> rep;

//LINKEDLIST TEST
	//INSERT
	cout<< "*LinkedList*"<< endl;
	clock_t start = clock();
	for(int i=0;i<rep;i++){
		a.insert(1);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("LinkedList insert: %.10f\n\n",time/(double)rep);
	//SIZE
	start = clock();
	for(int i=0;i<100;i++){
		a.size();
	} 
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("LinkedList size: %.10f\n\n", time/(double)rep);
	//AT
	start = clock();
	for(int i=0;i<100;i++){
		num=a.at(rep-1);
	} 
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("LinkedList at: %.10f\n\n", time/(double)rep);
	//POP
	start = clock();
	for(int i=0;i<rep;i++){
		a.pop();
	} 
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("LinkedList pop: %.10f\n\n", time/(double)rep);

	a.~LinkedList();
//ARRAYLIST TEST
	//INSERT
	cout<< "*ArrayList*"<< endl;
	for(int i=0;i<rep;i++){
		b.insert(1);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("ArrayList insert: %.10f\n\n", time/(double)rep);
	//SIZE
	start = clock();
	for(int i=0;i<100;i++){
		b.size();
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("ArrayList size: %.10f\n\n", time/(double)rep);
	//AT
	start = clock();
	for(int i=0;i<100;i++){
		num=b.at(rep-1);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("ArrayList at: %.10f\n\n", time/(double)rep);
	//POP
	start = clock();
	for(int i=0;i<rep;i++){
		b.pop();
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("ArrayList pop: %.10f\n\n", time/(double)rep);
	b.~ArrayList();
	return 0;
}