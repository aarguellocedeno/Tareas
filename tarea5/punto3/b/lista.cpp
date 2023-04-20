#include "lista.h"



Lista::Lista(){
  act = NULL;
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

La complejidad de este algoritmo en O(n), puesto a que el while en el peor caso se ejecutara
n+1 veces (donde n es el tamaño de la lista),y los condicionales en el peor caso se ejecutarán n veces.

*/

void  Lista::insListaOrdenada(Elemento elem){
  int i=1,flag = 1;
  Nodo* tmp = act;
  Nodo* ante = NULL;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  if(act == NULL){
  	act = nuevo;
  }else{	
  	while((tmp != NULL)&&(flag != 0)){   // n+1
		if((tmp->dato < elem)&&(tmp->sig == NULL)){ //n
			tmp->sig = nuevo;
			flag = 0;
		}else{	//n
			if((tmp->dato <= elem)&&(tmp->sig->dato >=elem)){ //n
				nuevo->sig = tmp->sig;
				tmp->sig = nuevo;
				flag = 0;
			}
			else if((ante==NULL)&&(tmp->dato > elem)){ //n
				nuevo->sig = tmp;
				act = nuevo;
				flag = 0;
			}
	    }
	    ante = tmp;
		tmp = tmp->sig;
	}
  }
}

