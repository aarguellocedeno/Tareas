#include "lista.h"
#include <iostream>
using namespace std;
// Ana Gabriela Argüello Cedeño 

int main(){
	Lista lis;
	int cuantas,i,tam;
	lis.insListaOrdenada(1);
	lis.insListaOrdenada(4);
	lis.insListaOrdenada(3);
	lis.insListaOrdenada(2);
	lis.insListaOrdenada(0);

	tam = lis.longLista();
	printf("Esta es la lista ordenada= ");
	for(i=1; i <= tam; i++){
		cout <<lis.infoLista(i)<<" ";
	}
	return 0;
}
