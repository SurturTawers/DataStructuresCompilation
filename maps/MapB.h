#ifndef LAB6_MAPB_H
#define LAB6_MAPB_H
#include "ADTMap.h"
class MapB:public ADTMap{
public:
    MapB(int);
    ~MapB();
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
    std::pair<std::string,int>* vMapB;
};
#endif //LAB6_MAPB_H