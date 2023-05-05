/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Implementación TAD Cola

modificadores: Nicolle Ruiz, Ana Gabriela Argüello
 */


#include "colaPrioridad.h"
#include <vector>
#include <iostream>
Cola::Cola(){
}

//Esta funcion auxiliar tiene una complejidad de O(n), puesto que se itera segun el tamaño del vector

Elemento Cola:: menor(){
   int numMen= l[0];
   for(int i=1;i<l.size();i++){
     if(l[i]<numMen){
         numMen = l[i];
     }
   }
   return numMen;
}
// esta funcion al igual que la anterior tiene una complejidad O(n) ya que se itera n veces, siendo n la longitud del vector
int Cola:: posi(){
   int pos= 0,aux=l[0];
   for(int i=1;i<l.size();i++){
     if(l[i]<aux){
         aux = l[i];
         pos = i;
     }
   }
   return pos;
}
// Esta funcion tiene una complejidad O(n), ya que se hace el llamado de la funcion menor(), y esta tiene una complejidad O(n), puesto que ocmo se explico
//anteriormente tiene una complejidad O(n).
Elemento Cola::front(){
   Elemento ans = menor();
   return ans;
}
//esta funcion tiene una complejidad de O(1)amortizado ya que esa es la complejidad que posee internamente la funcion push_back
void Cola::enqueue(Elemento e){
   l.push_back(e);
}
//Esta O(n) porque al llamar a posi tiene una complejidad ya antes dicha de O(n), y el erase tiene una complejidad de O(1) y eso no le suma a la complejidad
//
void Cola::deque(){
   int bus = posi();
   l.erase(l.begin()+bus);
}
//Esta funcion tiene una complejidad de O(1), ya que es la complejidad que empty posee internamente es O(1)
bool Cola::vaciaCola(){
  bool ans;
  if(l.empty())
     ans = true;
  else
     ans = false;
  return ans;
}
