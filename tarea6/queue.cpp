#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
#include <map>
using namespace std;
// ANA GABRIELA ARGUELLO CEDENO
/*  
La complejidad que posee este algoritmo es O(nlogn), puesto que la función "find" que viene incluida
en la librería de mapas, posee una complejidad O(logn),ya que esta función internamente es un árbol
e implementa una búsqueda binaria para saber si el elemento a buscar se encuentra en el mapa. En adición,
esa función find se encuentra dentro de un for, el cual se ejecutará n veces, donde n es el número de
casos que se digitan.
*/

int main(){
	int poblacion,casos,i,cnt=0;
	cin>> poblacion >> casos;
	while((poblacion != 0)||(casos != 0)){
		int num= casos;
		map<int,int> hospi;
		cnt++;
		deque<pair<int, int>> cola;
		printf("Case %d:\n",cnt);
		if(poblacion<casos){
			num= poblacion;
		}
		for(i=0;i<num;i++){
			cola.push_back(pair<int,int>(i+1,0));
			hospi.insert(pair<int,int>(i+1,0));
		}
		for(i=0;i<=casos-1;i++){
			string ent="";
			cin>>ent;
			if((ent[0]=='N')){
				while(cola.front().second!=hospi[cola.front().first]){
					cola.pop_front();			
				}
				if(cola.front().second==hospi[cola.front().first]){
						cout<<cola.front().first<<endl;
						hospi[cola.front().first]+=1;
						cola.push_back(pair<int,int>(cola.front().first,hospi[cola.front().first]));
				}		
			}else{
				int pri;
				cin>>pri;
    			if (hospi.find(pri) == hospi.end()) {
    			    hospi.insert(pair<int,int>(pri,0));
    			    cola.push_front(pair<int,int>(pri,0));
    			}
				else{
    				hospi[pri]+=1;
    				cola.push_front(pair<int,int>(pri,hospi[pri]));
				}
			} 
		}
		cin>> poblacion >> casos;
	}
}