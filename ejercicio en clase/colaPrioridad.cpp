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


Elemento Cola:: menor(){
   int numMen= l[0];
   for(int i=1;i<l.size();i++){
     if(l[i]<numMen){
         numMen = l[i];
     }
   }
   return numMen;
}
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

Elemento Cola::front(){
   Elemento ans = menor();
   return ans;
}

void Cola::enqueue(Elemento e){
   l.push_back(e);
}

void Cola::deque(){
   int bus = posi();
   l.erase(l.begin()+bus);
}

bool Cola::vaciaCola(){
  bool ans;
  if(l.empty())
     ans = true;
  else
     ans = false;
  return ans;
}

