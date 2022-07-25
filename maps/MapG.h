#ifndef LAB6_MAPG_H
#define LAB6_MAPG_H
#include "ADTMap.h"
#include <iostream>
class MapG:public ADTMap{
public:
    MapG(int);
    ~MapG();
    void insert(std::pair<std::string,int>);
    void erase(std::string);
    int at(std::string);
    int size();
    bool empty();
    int getColisionesIn();
    int getColisionesAt();
private:
    int hashing(std::string);
    void reHash();
    int N,colisionesIn=0,colisionesAt=0;
    std::pair<std::string,int>* vMapG;
};
#endif //LAB6_MAPG_H