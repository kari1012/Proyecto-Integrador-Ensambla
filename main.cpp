#include "hasht.h"
#include <iostream>
#include <time.h>

int main(){
	//printf("1");
	hasht<int>  hash(1000000);
	//printf("1");
	for(int n=1000000; n > 0;n--){
		printf("2");
		hash.insert(((rand()*rand())%2000001));
	}
	
	int random=0;
	int contador=0;
	clock_t termina=(clock()+(10*CLOCKS_PER_SEC));
	while(clock()<termina){
		printf("3");
		random=(rand()*rand())%2000001;
		hash.search(random);
		contador++;
	}
	printf("El resultado de la búsqueda iterativa es: %d\n", contador);
	
	/*random=0;
	contador=0;
	termina=(clock()+(10*CLOCKS_PER_SEC));
	while(clock()<termina){
		random=(rand()*rand())%2000001;
		arbol.treeSearch(random);
		contador++;
	}
	printf("El resultado de la búsqueda recursiva es: %d\n", contador);
	*/
	
	hasht<int> hash2(1000000);
	for (int n = 1000000; n > 0; n--) {
		hash2.insert(n);
	}
	
	random=0;
	contador=0;
	termina=(clock()+(10*CLOCKS_PER_SEC));
	while(clock()<termina){
		random=(rand()*rand())%2000001;
		hash2.search(random);
		contador++;
	}
	printf("El resultado de la búsqueda ordenada iterativa es: %d\n", contador);
	
	/*random=0;
	contador=0;
	termina=(clock()+(10*CLOCKS_PER_SEC));
	while(clock()<termina){
		random=(rand()*rand())%2000001;
		arbolO.treeSearch(random);
		contador++;
	}
	printf("El resultado de la búsqueda ordenada recursiva es: %d\n", contador);*/
	return 0;
}