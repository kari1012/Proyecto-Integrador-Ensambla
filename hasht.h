#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>
using namespace std;

template <typename T>
class hasht {
public:
	hasht(int nEntradas);
	// Constructor que especifica el numero de cubetas (entradas) 
	// en la tabla

	hasht(const hasht<T>& obj);
	// Constructor copia

	~hasht();
	// Destructor (borra la tabla)

	T* search(const T& item);
	// Retorna un puntero a la llave o NULL si no se encuentra

	void insert(const T& item);
	// Inserta el elemento en la tabla

private:
	int numEntradas;
	// Nœmero de entradas en la tabla
	vector<list<T> > tabla;
	// La tabla es un vector de listas de STL
};


template<typename T>
hasht<T>::hasht(int nEntradas) {
	numEntradas=nEntradas;
	tabla.resize(nEntradas);
};

template<typename T>
hasht<T>::hasht(const hasht<T>& obj){
	
};

template<typename T>
hasht<T>::~hasht() {
	tabla.clear();
};

template<typename T>
void hasht<T>::insert(const T& item) {
	//int posicion = item % numEntradas;
	tabla[item % numEntradas].push_front(item);
};

template<typename T>
T* hasht<T>::search(const T& item) {
	int posicion = item % numEntradas;
	typename list<T>::iterator iterador = tabla[posicion].begin();
	//typename list<T>::iterator it2 = tabla[posicion].end();

	while (iterador != tabla[posicion].end()) {
		if (*iterador == item) {
			return &*iterador;
		}else {
			iterador++;
		}
	}
   
	return nullptr;
};
#endif
