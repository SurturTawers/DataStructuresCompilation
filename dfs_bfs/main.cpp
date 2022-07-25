#include <iostream>
#include <vector>
#include <list>
using namespace std;
typedef struct{
    int val;
    int label;
}Nodo;
void DFS(vector<vector<Nodo>> G,int i){
    G.at(i-1).begin()->label=1;
    cout<<G.at(i-1).begin()->val<<" -> ";
    for(auto it=G.at(i-1).begin()+1;it!=G.at(i-1).end();it++){
        if(it->label==0) {
            if(G.at(it->val-1).begin()->label==0){
                it->label=1;
                DFS(G,it->val);
            }
        }
    }
}
void DFSIn(vector<vector<Nodo>> G){
    for(auto i=G.begin();i!=G.end();i++){
        i->begin()->label=0;
        for(auto j=i->begin()+1;j!=i->end();j++){
            j->label=0;
        }
    }
    for(auto i=G.begin();i!=G.end();i++){
        if(i->begin()->label==0){
            DFS(G,i->begin()->val);
        }
    }
}
void BFS(vector<vector<Nodo>> G, int i){
    list<Nodo> queue;
    G.at(i-1).begin()->label=1;
    queue.push_back(*G.at(i-1).begin());
    int temp;
    while(!queue.empty()){
        temp=queue.front().val;
        cout<<temp<<" -> ";
        queue.pop_front();
        for(auto j=G.at(temp-1).begin()+1;j!=G.at(temp-1).end();j++){
            if(j->label==0){
                if(G.at(j->val-1).begin()->label==0){
                    j->label=1;
                    G.at(j->val-1).begin()->label=1;
                    queue.push_back(*j);
                }
            }
        }
    }
}
void BFSIn(vector<vector<Nodo>> G){
    for(auto i=G.begin();i!=G.end();i++){
        i->begin()->label=0;
        for(auto j=i->begin()+1;j!=i->end();j++){
            j->label=0;
        }
    }
    for(auto i=G.begin();i!=G.end();i++){
        if(i->begin()->label==0){
            BFS(G,i->begin()->val);
        }
    }
}
int main() {
    int n,m;
    cout<<"Inserte N: ";
    cin>>n;
    while(n<=0){
        cout<<"Ingrese un numero mayor a 0: ";
        cin>>n;
    }
    vector<vector<Nodo>> listAd(n);
    for(int i=0;i<n;i++){
        listAd.at(i).push_back({i+1,0});
    }
    cout<<"Inserte M: ";
    cin>>m;
    while(m<0){
        cout<<"Ingrese un numero mayor o igual a 0: ";
        cin>>m;
    }
    //RELLENA LAS ARISTAS DEL GRAFO
    cout<<"Ingrese las conexiones de los nodos"<<endl;
    int temp1,temp2;
    for(int i=0;i<m;i++){
        cout<<"Nodo: ";
        cin>>temp1;
        while(temp1<=0 || temp1>n){
            cout<<"Ingrese un numero entre 1 y "<<n<<endl;
            cout<<"Nodo: ";
            cin>>temp1;
        }
        cout<<"Conexion: ";
        cin>>temp2;
        while(temp2<=0 || temp2>n){
            cout<<"Ingrese un numero entre 1 y "<<n<<endl;
            cout<<"Conexion: ";
            cin>>temp2;
        }
        listAd.at(temp1-1).push_back({temp2,0});
        listAd.at(temp2-1).push_back({temp1,0});
    }
    //IMPRIME LAS CONEXIONES DE LOS NODOS DEL GRAFO
    /*int count=1;
    for(auto it=listAd.begin();it!=listAd.end();it++){
        for(auto ii=it->begin();ii!=it->end();ii++){
            if(ii==it->begin()){
                cout<<*ii<<": ";
            }else{
                cout<<*ii<<" ";
            }
        }
        cout<<endl;
        count++;
    }*/
    //DFS
    cout<<"DFS"<<endl;
    DFSIn(listAd);
    cout<<endl;
    //BFS
    cout<<"BFS"<<endl;
    BFSIn(listAd);
    cout<<endl;
    return 0;
}