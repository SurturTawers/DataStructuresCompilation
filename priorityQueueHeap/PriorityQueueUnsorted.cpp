#include "PriorityQueueUnsorted.h"
using namespace std;
PriorityQueueUnsorted::PriorityQueueUnsorted(){
}
PriorityQueueUnsorted::~PriorityQueueUnsorted(){
}
bool PriorityQueueUnsorted::empty(){
    return _arr.empty();
}
int PriorityQueueUnsorted::size(){
    return _arr.size();
}
int PriorityQueueUnsorted::top(){
    vector<int>::iterator min=_arr.begin(),last=_arr.end()-1;
    int aux;
    for(vector<int>::iterator it=_arr.begin();it!=_arr.end();it++){
        if(*it<*min){
            min=it;
        }
    }
    aux=*last;
    *last=*min;
    *min=aux;
    return *last;
}
void PriorityQueueUnsorted::push(int n){
    _arr.push_back(n);
}
void PriorityQueueUnsorted::pop(){
    _arr.pop_back();
}
