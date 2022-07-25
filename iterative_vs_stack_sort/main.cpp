#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include "soluciones.h"
using namespace std;
int main(){
	int q=100,i,n;
	cout<<"Ingrese n"<<endl;
	cin>>n;
	int array[n];
	//CREO EL ARREGLO
	srand((unsigned)time(NULL));
	for(int j=0;j<n;j++){
		array[j]=rand()%1000+1;
	}
	soluciones* solucion =new soluciones();

	int resultado;
	double timeCre,timeDec,timeDes;
	//ARREGLO DESORDENADO
	//SOLUCION UNO
	clock_t start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionUno(i,array);
	}
	timeDes=((double)clock()-start)/CLOCKS_PER_SEC;
	timeDes=timeDes/(double)q;
	cout<<"Desordenado\nsolucionUno: "<<timeDes<<endl;
	//SOLUCION DOS
	start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionDos(i,array);
	}
	timeDes=((double)clock()-start)/CLOCKS_PER_SEC;
	timeDes=timeDes/(double)q;
	cout<<"solucionDos: "<<timeDes<<endl;
	//ARREGLO ORDENADO CRECIENTE
	//SOLUCION UNO
	sort(array, array+n);
	start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionUno(i,array);
	}
	timeCre=((double)clock()-start)/CLOCKS_PER_SEC;
	timeCre=timeCre/(double)q;
	cout<<"Creciente\nsolucionUno: "<<timeCre<<endl;
	//SOLUCION DOS
	start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionDos(i,array);
	}
	timeCre=((double)clock()-start)/CLOCKS_PER_SEC;
	timeCre=timeCre/(double)q;
	cout<<"solucionDos: "<<timeCre<<endl;
	//ARREGLO ORDENADO DECRECIENTE
	//SOLUCION UNO
	sort(array,array +n,greater<>());
	start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionUno(i,array);
	}
	timeDec=((double)clock()-start)/CLOCKS_PER_SEC;
	timeDec=timeDec/(double)q;
	cout<<"Decreciente\nsolucionUno: "<<timeDec<<endl;
	//SOLUCION DOS
	start=clock();
	for(int j=0;j<q;j++){
		i=rand()%n;
		resultado=solucion->solucionDos(i,array);
	}
	timeDec=((double)clock()-start)/CLOCKS_PER_SEC;
	timeDec=timeDec/(double)q;
	cout<<"solucionDos: "<<timeDec<<endl;

	return 0;
}