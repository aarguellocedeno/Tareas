#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// ANA GABRIELA ARGUELLO CEDENO
/*
La complejidad de este algoritmo es O(n^2),donde n será el número de veces que se ejecutará el segundo while, dentro de este
while se encuentran dos for el primero que agrega a la primera cola los números ordenados de 1 a n, el segundo for
lo que hace es agregar a otra cola los números digitados, también hay un while, este ciclo itera hasta que flag !=0 y en el
caso medio(no el mejor, pero no el peor) de los casos eso se ejecutará n veces. 
Por lo anterior el algoritmo pasa de ser O(n) a ser O(n^2)
*/
int main(){
	int n,i=1,fin;
	vector<int> a;
	scanf("%d\n",&n);
	while(n !=0){
		scanf("%d\n",&fin);
		while(fin != 0){
			queue<int> cola,estB;
			estB.push(fin);
			stack<int>aux;
			int cnt=0;
			for(i=1;i<=n;i++){
				cola.push(i);
			}
			for(i=1;i<=n-1;i++){
				scanf("%d",&fin);			
				estB.push(fin);
				
			}
			aux.push(cola.front());	
			cola.pop();
			int flag = 1;
			while((flag!=0)){
				if(aux.size()!= 0){
					if(aux.top()==estB.front()){
						cnt++;
						aux.pop();
						estB.pop();
						
					}else{
						aux.push(cola.front());
						if(aux.top()==estB.front()){
							cnt++;
							aux.pop();
							estB.pop();
							cola.pop();
						}
						else{
							cola.pop();
						}
					}
				}
				
				else if((cola.size()!=0)){
					aux.push(cola.front());
					if(aux.top()==estB.front()){
						cnt++;
						aux.pop();
						estB.pop();
						cola.pop();
					}
					else{
						cola.pop();
					}
					
				}else if((cola.size()==0)&&(aux.size()!=0)){
					if(aux.top()==estB.front()){
						cnt++;
						aux.pop();
						estB.pop();
					}else{
						flag = 0;
					}
				}
				if((cola.size()==0)&&(aux.size()!=0)){
					if(aux.top()!=estB.front())
						flag=0;	
				}if((cola.size()==0)&&(aux.size()==0)){
					flag = 0;
				}
				
		}
		if((aux.size()==0) &&(cola.size()==0)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		scanf("%d\n",&fin);
		}
		printf("\n");
		scanf("%d\n",&n);
		
	}
		
}

