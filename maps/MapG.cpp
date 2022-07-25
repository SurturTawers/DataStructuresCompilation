#include "MapG.h"
using namespace std;
MapG::MapG(int tam){
    N=tam/2;
    vMapG=new pair<string,int> [N];
}
MapG::~MapG(){
    delete[] vMapG;
}
void MapG:: insert(pair<string,int> par){
    string clave=par.first;
    int pos=hashing(clave);
    double alpha;
    if(vMapG[pos].first.empty()){
        vMapG[pos]=par;
    }else{
        //LINEAR PROBING
        if(vMapG[pos].first==clave){
            cout<<"Ya se encuentra "<<clave<<endl;
        }else{
            int p=0;
            colisionesIn++;
            while(p!=N){
                if(vMapG[pos].first.empty()){
                    vMapG[pos]=par;
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
int MapG::hashing(string clave){
    int acPol=(int)clave[clave.size()-1];
    int z=15,pos;
    for(int i=clave.size()-1;i>0;i--){
        acPol*=z;
        acPol+=clave[i-1];
    }
    pos=acPol%N;
    return pos;
}
void MapG::reHash(){
    N*=2;
    pair<string,int>* aux = new pair<string,int>[N];
    int pos;
    for(int i=0;i<N/2;i++){
        if(!vMapG[i].first.empty()){
            pos=hashing(vMapG[i].first);
            if(!aux[pos].first.empty()){
                int p=0;
                while(p!=N){
                    if(aux[pos].first.empty()){
                        aux[pos]=vMapG[i];
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
                aux[pos]=vMapG[i];
            }
        }
    }
    delete[] vMapG;
    vMapG=aux;
}
void MapG::erase(string key){
    int pos=hashing(key);
    int p=0;
    while(p!=N){
        if(vMapG[pos].first==key){
            vMapG[pos].first.clear();
            vMapG[pos].second=-1;
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
int MapG::at(string key){
    int pos=hashing(key);
    int p=0;
    int f=1;
    while(p!=N){
        if(vMapG[pos].first==key){
            return vMapG[pos].second;
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
int MapG::size(){
    int count=0;
    for(int i=0;i<N;i++){
        if(!vMapG[i].first.empty()){
            count++;
        }
    }
    return count;
}
bool MapG::empty(){
    for(int i=0;i<N;i++){
        if(!vMapG[i].first.empty()){
            return false;
        }
    }
    return true;
}
int MapG::getColisionesIn() {
    return colisionesIn;
}
int MapG::getColisionesAt() {
    return colisionesAt;
}