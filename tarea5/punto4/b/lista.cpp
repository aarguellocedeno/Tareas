#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}

/*

Esta funcion posee una complejidad O(n^2), (donde n es el tam de la lista), esto ya que en esta funcion se usa lo que es anxlista e infolista
las cuales son O(n), y estas al ser usadas dentro de un ciclo, en el peor de los casos se ejecutaran n(n).

*/
Lista Lista::operator+(Lista lis){
		Lista lista3;
		int i = 1;
		Nodo* l1 = lis.act;
		
		while(i<=longLista()){ // n+1 donde n es la longitud de la lista
			int num = infoLista(i); //n(n)
	        lista3.anxLista(num); // n(n)
	    	i++; 
		}
		while(l1 != NULL){ //n+1 donde n es la longitud de la lista
			lista3.anxLista(l1->dato); // n(n)
			
			l1 = l1->sig;
		}
			
	return lista3;
}
