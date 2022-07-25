#include "MapB.h"
using namespace std;
MapB::MapB(int tam){
    N=tam/2;
    vMapB=new pair<string,int> [N];
}
MapB::~MapB(){
    delete[] vMapB;
}
void MapB::insert(pair<string,int> par){
    string clave=par.first;
    int pos=hashing(clave);
    double alpha;
    if(vMapB[pos].first.empty()){
        vMapB[pos]=par;
    }else{
        //LINEAR PROBING
        if(vMapB[pos].first==clave){
            cout<<"Ya se encuentra "<<clave<<endl;
        }else{
            int p=0;
            colisionesIn++;
            while(p!=N){
                if(vMapB[pos].first.empty()){
                    vMapB[pos]=par;
                    break;
                }else{
                    pos++;
                    if(pos==N){
                        pos=0;
                    }
                    p++;
                }
            }
            if(p==N){
                cout<<"No se pudo insertar"<<endl;
            }
            alpha=((double)size())/(double)N;
            if(alpha>0.5){
                reHash();
            }
        }
    }
}
int MapB::hashing(string clave){
    int pos=clave[0]%N;
    return pos;
}
void MapB::reHash(){
    N*=2;
    pair<string,int>* aux = new pair<string,int>[N];
    int pos;
    for(int i=0;i<N/2;i++){
        if(!vMapB[i].first.empty()){
            pos=hashing(vMapB[i].first);
            if(!aux[pos].first.empty()){
                int p=0;
                while(p!=N){
                    if(aux[pos].first.empty()){
                        aux[pos]=vMapB[i];
                        break;
                    }else{
                        pos++;
                        if(pos==N){
                            pos=0;
                        }
                        p++;
                    }
                }
            }else{
                aux[pos]=vMapB[i];
            }
        }
    }
    delete[] vMapB;
    vMapB=aux;
}
void MapB::erase(string key){
    int pos=hashing(key);
    int p=0;
    while(p!=N){
        if(vMapB[pos].first==key){
            vMapB[pos].first.clear();
            vMapB[pos].second=-1;
            break;
        }else{
            pos++;
            if(pos==N){
                pos=0;
            }
            p++;
        }
    }
    if(p==N){
        cout<<"El elemento no existe"<<endl;
    }
}
int MapB::at(string key){
    int pos=hashing(key);
    int p=0;
    int f=1;
    while(p!=N){
        if(vMapB[pos].first==key){
            return vMapB[pos].second;
        }else{
            pos++;
            if(pos==N){
                pos=0;
            }
            p++;
            if(f==1){
                colisionesAt++;
                f=0;
            }
        }
    }
    if(p==N){
        cout<<"El elemento no existe"<<endl;
        return -1;
    }
}
int MapB::size(){
    int count=0;
    for(int i=0;i<N;i++){
        if(!vMapB[i].first.empty()){
            count++;
        }
    }
    return count;
}
bool MapB::empty(){
    for(int i=0;i<N;i++){
        if(!vMapB[i].first.empty()){
            return false;
        }
    }
    return true;
}
int MapB::getColisionesIn() {
    return colisionesIn;
}
int MapB::getColisionesAt(){
    return colisionesAt;
}