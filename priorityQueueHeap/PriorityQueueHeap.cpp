#include "PriorityQueueHeap.h"
using namespace std;
PriorityQueueHeap::PriorityQueueHeap(){
    _arr.push_back(0);
}
PriorityQueueHeap::~PriorityQueueHeap(){
}
bool PriorityQueueHeap::empty(){
    if(_arr.size()-1==0){
        return true;
    }
    return false;
}
int PriorityQueueHeap::size(){
    return _arr.size()-1;
}
int PriorityQueueHeap::top(){
    DownHeap(_arr.begin()+1,1);
    return _arr.at(1);
}
void PriorityQueueHeap::push(int n){
    _arr.push_back(n);
    if(_arr.size()-1>1){
        UpHeap(_arr.end()-1,(_arr.size()-1)/2);
    }
}
void PriorityQueueHeap::DownHeap(vector<int>::iterator nodo,int ind){
    int aux;
    if(ind*2<=_arr.size()-1){
        vector<int>::iterator cambioIzq=_arr.begin()+(ind*2);
        if(*nodo>*cambioIzq){
            aux=*nodo;
            *nodo=*cambioIzq;
            *cambioIzq=aux;
        }
        DownHeap(cambioIzq,ind*2);
    }
    if((ind*2)+1<=_arr.size()-1){
        vector<int>::iterator cambioDer=_arr.begin()+(ind*2)+1;
        if(*nodo>*cambioDer){
            aux=*nodo;
            *nodo=*cambioDer;
            *cambioDer=aux;
        }
        DownHeap(cambioDer,(ind*2)+1);
    }
}
void PriorityQueueHeap::UpHeap(vector<int>::iterator nodo,int ind){
    vector<int>::iterator cambio=_arr.begin()+ind;
    int aux;
    if(ind==0){
        return;
    }
    if(*cambio>*nodo){
        aux=*cambio;
        *cambio=*nodo;
        *nodo=aux;
        UpHeap(cambio,(ind/2));
    }
}
void PriorityQueueHeap::pop(){
    _arr.erase(_arr.begin()+1);
}