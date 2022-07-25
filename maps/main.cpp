#include <iostream>
#include "MapG.h"
#include "MapB.h"
#include "MapDH.h"
#include <vector>
#include <ctime>
using namespace std;
int main(){
    vector<pair<string,int>> vec;
    srand((unsigned)time(NULL));
    string clave;
    int colBIn=0,colBAt=0,colGIn=0,colGAt=0,colDHIn=0,colDHAt=0;
    int val,N,reps=1;
    cout<<"Ingrese el numero de elementos: ";
    cin>>N;
    while(N<=0){
        cout<<"Ingrese un numero valido"<<endl;
        cin>>N;
    }
    for(int z=0;z<reps;z++){
        for(int j=0;j<N;j++){
            for(int i=0;i<6;i++){
                clave.push_back(char(rand()%25 +97));
            }
            val=rand()%11;
            vec.push_back(make_pair(clave,val));
            clave.clear();
        }
        MapB* mB=new MapB(N);
        MapG* mG=new MapG(N);
        MapDH* mDH=new MapDH(N);
        for(auto it=vec.begin();it!=vec.end();it++){
            mB->insert(*it);
            mG->insert(*it);
            mDH->insert(*it);
            mB->at(it->first);
            mG->at(it->first);
            mDH->at(it->first);
        }
        colBIn+=mB->getColisionesIn();
        colGIn+=mG->getColisionesIn();
        colDHIn+=mDH->getColisionesIn();
        colBAt+=mB->getColisionesAt();
        colGAt+=mG->getColisionesAt();
        colDHAt+=mDH->getColisionesAt();
        delete mB;
        delete mG;
        delete mDH;
    }
    colBIn/=reps;
    colGIn/=reps;
    colDHIn/=reps;
    colBAt/=reps;
    colGAt/=reps;
    colDHAt/=reps;
    cout<<"Numero de colisiones para "<<N<<" elementos"<<endl;
    cout<<"MapB "<<"Insert: "<<colBIn<<"\tat: "<<colBAt<<endl;
    cout<<"MapG "<<"Insert: "<<colGIn<<"\tat: "<<colGAt<<endl;
    cout<<"MapDH "<<"Insert: "<<colDHIn<<"\tat: "<<colDHAt<<endl;
    return 0;
}
