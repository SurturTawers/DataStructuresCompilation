#include <vector>
#include "PriorityQueueHeap.h"
#include "PriorityQueueUnsorted.h"
#include <ctime>
using namespace std;
void HeapSort(vector<int> &vec){
    PriorityQueueHeap *pqh= new PriorityQueueHeap();
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        pqh->push(*it);
    }
    //SORTING
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        *it=pqh->top();
        pqh->pop();
    }
    delete pqh;
}
void SelectionSort(vector<int> &vec){
    PriorityQueueUnsorted *pqu = new PriorityQueueUnsorted();
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        pqu->push(*it);
    }
    //SORTING
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        *it=pqu->top();
        pqu->pop();
    }
    delete pqu;
}
int main(){
    int n=20,num;
    vector<int> v1,v2;
    srand((unsigned)time(NULL));
	//PriorityQueueADT *pqh = new PriorityQueueHeap();
	//PriorityQueueADT *pqu = new PriorityQueueUnsorted();
	for(int i=0;i<n;i++){
        num=rand()%n;
	    v1.push_back(num);
	    v2.push_back(num);
	}
	SelectionSort(v1);
	HeapSort(v2);
    for(int i=0;i<v1.size();i++){
	    cout<<v1.at(i)<<' ';
	}
	cout<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2.at(i)<<' ';
    }
    cout<<endl;
	return 0;
}