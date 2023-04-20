#include "lista.h"
#include <iostream>
using namespace std;

// Ana Gabriela Argüello Cedeño 


int main(){
	Lista lis1,lis2,lis3;
	lis1.anxLista(1);
	lis1.anxLista(2);
	lis1.anxLista(3);
	lis2.anxLista(4);
	lis2.anxLista(5);
	lis2.anxLista(6);
	lis3 = lis1 + lis2;
	int tam = lis3.longLista();
	printf("esta es la lista junta= ");
	for(int i=1; i <= tam;i++){
		cout <<lis3.infoLista(i)<<" ";
	}
	return 0;
}
