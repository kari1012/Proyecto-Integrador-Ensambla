//Karina Gómez Rodríguez - B42904
#include "Ordenador.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;

Ordenador::Ordenador() {}
Ordenador::~Ordenador() {}

void Ordenador::seleccion(int * arreglo, int tamano) {
	int posicion; //almacenará la posición del valor mas pequeño en cada iteración 
	int temporal; //se usará para poder hacer los cambios de numeros en el arreglo
	for (int x = 0; x < tamano; x++) {
		posicion = x;
		for (int y = x + 1; y < tamano; y++) {
			if (arreglo[posicion] > arreglo[y]) {
				posicion = y;
			}
		}
		temporal = arreglo[posicion];
		arreglo[posicion] = arreglo[x];
		arreglo[x] = temporal;
	}
}

void Ordenador::insercion(int * arreglo, int tamano) {
	int key = 0;
	int i = 0;
	
	for (int j = 1; j < tamano; j++) {
		
		key = arreglo[j];
		i = j - 1;
		while (i >= 0 && arreglo[i] > key) {
			
			arreglo[i + 1] = arreglo[i];
			i = i - 1;
			arreglo[i + 1] = key;
		}
	}
}

void Ordenador::mergesort(int *arreglo, int tamano) {
	merge2(arreglo, 0, tamano-1);
}


void Ordenador::merge2(int* arreglo, int p, int r) {
	if (p < r) {
		
		int m = ((p+r)/2);
		
		
		merge2(arreglo, p, m);
		merge2(arreglo, m+1, r);
		
		merge3(arreglo, p, m, r);
		
	}
}

void Ordenador::merge3(int* arreglo, int p, int q, int r) {
	
	int i, j, k;
	
	int n1 = q - p + 1;
	int n2 = r - q;

	int *L = new int[n1+1];
	int *R = new int[n2+1];
	
	L[n1] = 1000000;
	R[n2] = 1000000;

	for (int i = 0; i < n1; i++) {
		L[i] = arreglo[p + i];
	}

	for (int j = 0; j < n2; j++) {
		R[j] = arreglo[q + 1 + j];
	}

	i = 0;
	j = 0;
	k = p;
	
	for(; k <= r; k++){
		if(L[i] < R[j]){
			arreglo[k] = L[i];
			i++;
		}else{
			arreglo[k] = R[j];
			j++;
		}
	}
	delete L;
	L = nullptr;
	delete R;
	R = nullptr;
}

//metodos de heapsort
void Ordenador::heapsort(int * arreglo, int tamano) {
	int temporal = 0;
	buildMaxHeap(arreglo, tamano);
	for (int i = tamano; i > 1; i--) {
		temporal = arreglo[0];
		arreglo[0] = arreglo[i - 1];
		arreglo[i - 1] = temporal;
		tamano = tamano - 1;
		maxHeapify(arreglo, 0, tamano);
	}
}

void Ordenador::buildMaxHeap(int *arreglo, int tamano) {
	for (int i = floor(tamano / 2); i >= 0; i--) {
		maxHeapify(arreglo, i, tamano);
	}
}

void Ordenador::maxHeapify(int *arreglo, int i, int tamano) {
	int masLargo = 0;
	int temporal = 0;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < tamano && arreglo[l] > arreglo[i]) {
		masLargo = l;
	}
	else {
		masLargo = i;
	}

	if (r < tamano && arreglo[r] > arreglo[masLargo]) {
		masLargo = r;
	}
	if (masLargo != i) {
		temporal = arreglo[i];
		arreglo[i] = arreglo[masLargo];
		arreglo[masLargo] = temporal;
		maxHeapify(arreglo, masLargo, tamano);
	}
}

//Métodos usados por quicksort
void Ordenador::quicksort(int * arreglo, int tamano) {
	tamano--;
	quicksort1(arreglo, 0, tamano);
}

void Ordenador::quicksort1(int *arreglo, int p, int r) {
	if (p < r) {

		int q = partition(arreglo, p, r);
		quicksort1(arreglo, p, q - 1);
		quicksort1(arreglo, q + 1, r);

	}
}

int Ordenador::partition(int *arreglo, int p, int r) {
	int temporal = 0;
	//p es el inicio del arreglo
	//r es el fin del arreglo
	int x = arreglo[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (arreglo[j] <= x) {
			i = i + 1;
			temporal = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = temporal;
		}
	}
	temporal = arreglo[r];
	arreglo[r] = arreglo[i + 1];
	arreglo[i + 1] = temporal;

	return i + 1;
}

//Métodos usados por radixsort
   
void Ordenador::radixsort(int* arreglo, int tamano) {
   int valor = abs(obtenerMinimo(arreglo,tamano));
    
    for(int i=0;i<tamano;i++)
        arreglo[i]=arreglo[i]+valor;

    int m = getMaximo(arreglo, tamano); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arreglo, tamano, exp); 

    for(int i=0;i<tamano;i++)
        arreglo[i]=arreglo[i]-valor;
}

int Ordenador::obtenerMinimo(int arreglo[], int n){
    int menor = arreglo[0];
    for(int i=1;i<n;i++){
        if(menor > arreglo[i]){
            menor = arreglo[i];
        }

    }
    return menor;
}

int Ordenador::getMaximo(int arreglo[], int n) 
{ 
    int maximo = arreglo[0]; 
    for (int i = 1; i < n; i++) 
        if (arreglo[i] > maximo) 
            maximo = arreglo[i]; 
    return maximo; 
} 

void Ordenador::countSort(int arreglo[], int n, int exp){ 
    int salida[n];
    int i; 
	int count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arreglo[i]/exp)%10 ]++; 

    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
   
    for (i = n - 1; i >= 0; i--){ 
        salida[count[ (arreglo[i]/exp)%10 ] - 1] = arreglo[i]; 
        count[ (arreglo[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arreglo[i] = salida[i]; 
} 