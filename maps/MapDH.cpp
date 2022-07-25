#include "MapDH.h"
using namespace std;
MapDH::MapDH(int tam){
    N=tam/2;
    vMapDH=new pair<string,int>[N];
}
MapDH::~MapDH(){
    delete[] vMapDH;
}
void MapDH:: insert(pair<string,int> par){
    string clave=par.first;
    int pos=hashing(clave);
    double alpha;
    if(vMapDH[pos].first.empty()){
        vMapDH[pos]=par;
    }else{
        //DOBLE HASH
        if(vMapDH[pos].first==clave){
            cout<<"Ya se encuentra "<<clave<<endl;
        }else{
            colisionesIn++;
            int dobH=dobleHash(clave),ind;
            for(int j=1;j<=N;j++){
                ind=(pos+(j*dobH))%N;
                if(vMapDH[ind].first.empty()){
                    vMapDH[ind]=par;
                    break;
                }
            }
            alpha=((double)size()/(double)N);
            if(alpha<0.5){
                reHash();
            }
        }
    }
}
int MapDH::hashing(string clave){
    int acPol=(int)clave[clave.size()-1];
    int z=15,pos;
    for(int i=clave.size()-1;i>0;i--){
        acPol*=z;
        acPol+=clave[i-1];
    }
    pos=acPol%N;
    return pos;
}
int MapDH::dobleHash(string clave){
    int acPol=(int)clave[clave.size()-1];
    int z=15;
    for(int i=clave.size()-1;i>0;i--){
        acPol*=z;
        acPol+=clave[i-1];
    }
    int dobH=7-(acPol%7);
    return dobH;
}
void MapDH::reHash(){
    N*=2;
    pair<string,int>* aux = new pair<string,int>[N];
    int pos;
    for(int i=0;i<N/2;i++){
        if(!vMapDH[i].first.empty()){
            pos=hashing(vMapDH[i].first);
            if(!aux[pos].first.empty()){
                int dobH=dobleHash(vMapDH[i].first),ind;
                for(int j=1;j<=N;j++){
                    ind=(pos+(j*dobH))%N;
                    if(aux[ind].first.empty()){
                        aux[ind]=vMapDH[i];
                        break;
                    }
                }
            }else{
                aux[pos]=vMapDH[i];
            }
        }
    }
    delete[] vMapDH;
    vMapDH=aux;
}
void MapDH::erase(string key){
    int pos=hashing(key);
    if(vMapDH[pos].first==key){
        vMapDH[pos].first.clear();
        vMapDH[pos].second=-1;
    }else{
        int dobH=dobleHash(key),ind;
        for(int j=1;j<=N;j++){
            ind=(pos+(j*dobH))%N;
            if(vMapDH[ind].first==key){
                vMapDH[pos].first.clear();
                vMapDH[pos].second=-1;
                break;
            }
        }
        if(vMapDH[ind].first!=key){
            cout<<"No existe el elemento"<<endl;
        }
    }
}
int MapDH::at(string key){
    int pos=hashing(key);
    int f=1;
    if(vMapDH[pos].first==key){
        return vMapDH[pos].second;
    }else{
        int dobH=dobleHash(key),ind;
        for(int j=1;j<=N;j++){
            ind=(pos+(j*dobH))%N;
            if(f==1){
                colisionesAt++;
                f=0;
            }
            if(vMapDH[ind].first==key){
                return vMapDH[ind].second;
            }
        }
        if(vMapDH[ind].first!=key){
            cout<<"No existe el elemento"<<endl;
            return -1;
        }
    }
}
int MapDH::size(){
    int count=0;
    for(int i=0;i<N;i++){
        if(!vMapDH[i].first.empty()){
            count++;
        }
    }
    return count;
}
bool MapDH::empty(){
    for(int i=0;i<N;i++){
        if(!vMapDH[i].first.empty()){
            return false;
        }
    }
    return true;
}
int MapDH::getColisionesIn() {
    return colisionesIn;
}
int MapDH::getColisionesAt() {
    return colisionesAt;
}