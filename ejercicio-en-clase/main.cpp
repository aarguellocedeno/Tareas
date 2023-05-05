#include "colaPrioridad.h"
#include <iostream>
using namespace std;
int main(){
   Cola c;
   c.enqueue(5);
   c.enqueue(2);
   c.enqueue(7);
   c.enqueue(1);
   cout<<c.front()<<endl;
   c.deque();
   cout<<c.front();

   return 0;
}