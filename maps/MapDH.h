#ifndef LAB6_MAPDH_H
#define LAB6_MAPDH_H
#include "ADTMap.h"
class MapDH:public ADTMap{
public:
    MapDH(int);
    ~MapDH();
    void insert(std::pair<std::string,int>);
    void erase(std::string);
    int at(std::string);
    int size();
    bool empty();
    int getColisionesIn();
    int getColisionesAt();
private:
    int hashing(std::string);
    int dobleHash(std::string);
    void reHash();
    int N,colisionesIn=0,colisionesAt=0;
    std::pair<std::string,int>* vMapDH;
};
#endif //LAB6_MAPDH_H