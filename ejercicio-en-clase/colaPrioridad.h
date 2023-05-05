/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Implementación TAD Cola

 */

#ifndef  COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <vector>
using namespace std;
typedef int Elemento;

class Cola{
   vector<int> l;
   public:
      Cola(); // crearCola
      Elemento menor();
      int posi();
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool vaciaCola();
};

#endif
