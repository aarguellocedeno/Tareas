#include "lista.h"
#include <iostream>
using namespace std;
// Ana Gabriela Argüello Cedeño 

/*

Este algoritmo tiene como complejidad O(n^2), por el motivo de que cuando se hace uso de la lis.infolista(i) dentro del while en el 
peor caso se ejecutara n(n) veces puesto que la complejidad de la funcion infolista(i) es de n (siendo n el la longitud de la lista)


*/
void insertarEnListaOrdenada(Lista &lis,int v){
	int i=0,flag=1,tam=lis.longLista();
	while((i<tam) &&(flag != 0)){// este en el peor caso se ejecuta n+1 veces donde n es la longitud de la lista
		int num = lis.infoLista(i); // por tal motivo este se ejecutara n(n) veces y
		int num1 = lis.infoLista(i+1); //este tambien.
		if(((v>=num)&&(v<=num1)) || (v < num)){
			lis.insLista(v,i+1);
			flag = 0;
		}
		else if(v > lis.infoLista(tam)){
			lis.anxLista(v); //este tambien se ejecutara n(n) veces 
			flag = 0;
		}
	i++;
	}
}

int main(){
	Lista lis;
	int v=4,cuantas,i,tam;
	lis.anxLista(0);
	lis.anxLista(1);
	lis.anxLista(2);
	lis.anxLista(5);
	lis.anxLista(6);
	insertarEnListaOrdenada(lis,v);
	tam = lis.longLista();
	printf("esta es la lista ordenada= ");
	for(i=1; i <= tam;i++){
		cout <<lis.infoLista(i)<<" ";
	}
	return 0;
}
