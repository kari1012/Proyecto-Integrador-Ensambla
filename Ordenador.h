#ifndef ORDENADOR
#define ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"

using namespace std;

class Ordenador{
	private:
	
	void merge2(int *arreglo, int p, int r);
	void merge3(int *arreglo, int p, int q, int r);
	void buildMaxHeap(int *arreglo, int tamano);
	void maxHeapify(int *arreglo, int i, int tamano);
	void quicksort1(int *arreglo, int p, int r);
	int partition(int *arreglo, int p, int r);
	int obtenerMinimo(int arr[], int n);
	int getMaximo(int arr[], int n);
	void countSort(int arr[], int n, int exp);
	
	
	public:
	
	Ordenador();
	~Ordenador();
	
	//Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	//simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	//que se va a ejecutar el mismo �main� para todas las tareas.
	void seleccion(int * arreglo, int tamano);
	void insercion(int * arreglo, int tamano);
	void mergesort(int * arreglo, int tamano);
	void heapsort(int * arreglo, int tamano);
	void quicksort(int * arreglo, int tamano);
	void radixsort(int * arreglo, int tamano);
};
#endif
