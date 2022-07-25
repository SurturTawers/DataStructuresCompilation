#include <vector>
#include <stack>
using namespace std;
class soluciones{
public:
	soluciones();
	~soluciones();
	int solucionUno(int i, int* array);
	int solucionDos(int i, int* array);
private:
	stack <int> stackMayor;
};
