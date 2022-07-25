#ifndef Iterador_H
#define Iterador_H

#include <vector>
class Iterador{
public:
	Iterador(int*,int*);
	~Iterador();
	bool hasNext();
	int next();
private:
	int aux;
	int* end;
	std::vector<int>::iterator iter;
	//std::vector<int>::iterator end;
};
#endif