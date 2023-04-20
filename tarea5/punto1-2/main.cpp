#include "lista.h"
#include <iostream>
using namespace std;
// Ana Gabriela Argüello Cedeño 


/*

La operacion contarOcurrencias tiene como complejidad O(n^2),
ya que cuando se usa la funcion lis.infoLista(i), esta operacion se ejecutara n(n) es decir n^2

*/

int contarOcurrencias(Lista &lis,int v){
	int cnt=0,i;  // 2
 	int tam = lis.longLista(); // n
 	for(i=1;i<= tam;i++){ // n+1
 		int num = lis.infoLista(i); // n(n)
 		if(num == v){ // n
 			cnt++; // en el mejor caso nunca se ejecutara, y en el peor siempre lo hara.
		 }
	 }
	 return cnt; //1
}



/*

En esta operación se obtiene la misma complejidad que la anterior es decir O(n^2) puesto que además de
que se ejecuta n(n) veces en el infoLista, tambien se ejecuta n(n) en el anxLista, en el peor caso del
if es decir que todos los números son menores a v

*/
Lista obtenerMenores(Lista &lis,int v){
	Lista men;
	int i; // 1
	int tam = lis.longLista(); //n
	for(i=1;i<= tam;i++){ // n
		int num = lis.infoLista(i); //n(n)
		if(num < v){ // n
			men.anxLista(num);	//en el mejor caso esto nunca se ejecutara puesto que ningun numero sera menor que v,y en el peor caso, se ejecutara n(n) 
		}
	} 
	return men;
}



int main(){
	Lista lis,limenor;
	int v=2,cuantas,i,tam;
	lis.anxLista(1);
	lis.anxLista(2);
	lis.anxLista(3);
	lis.anxLista(2);
	lis.anxLista(2);
	lis.anxLista(2);
	lis.anxLista(0);
	lis.anxLista(1);
	cuantas = contarOcurrencias(lis,v);
	cout << "aparece: " << cuantas<<"\n";
	cout << "la lista de menores es: ";
	limenor = obtenerMenores(lis,v);
	tam = limenor.longLista();
	for(i=1; i <=  tam;i++){
		cout <<limenor.infoLista(i);
	}
	return 0;
}

