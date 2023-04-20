#include "lista.h"
#include <iostream>
using namespace std;
// Ana Gabriela Argüello Cedeño 


/*

La complejidad de el algoritmo concatenarListas es O(n^2) (donde n es el tam de la lista )por el motivo de que 
tanto lis2.infolista(i) como lis1.anxLista(num) son n(n), esto ya que la funcion longLista al igual que infoLista
y anxLista poseen una complejidad O(n), y como estan dentro de un for estas se ejecutarian las n(n) mencionadas anteriormente

*/

void concatenarListas(Lista &lis1,Lista &lis2){
	int i,num; //2
	for(i=1; i<= lis2.longLista();i++){ //n + 1
		num = lis2.infoLista(i); // n(n)
		lis1.anxLista(num);  // n(n)
	}
}


int main(){
	Lista lis1,lis2;
	lis1.anxLista(1);
	lis1.anxLista(2);
	lis1.anxLista(3);
	lis2.anxLista(4);
	lis2.anxLista(5);
	lis2.anxLista(6);
	concatenarListas(lis1,lis2);
	int tam = lis1.longLista();
	printf("esta es la lista junta= ");
	for(int i=1; i <= tam;i++){
		cout <<lis1.infoLista(i)<<" ";
	}
	return 0;
}
