//Ana Gabriela Argüello Cedeño
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
using namespace std;
/*
La complejidad que posee este algoritmo es O(n^2) ya que el primer for se ejecuta n veces donde n es el
tamaño de la frase digitada, y dentro de este for se encuentren dos ciclos , uno que guarda la cadena que 
este entre un [---] o un [---[ y seguido a ese ciclo, hay un for que itera del tamaño de la cadena -1 hasta 0,
en el peor caso estos ciclos iteraran n veces por lo que que la complejidad pasa de O(n) a O(n^2).

*/
int main(){
	deque<char> lista;
	int i;
    string frase;
    while(cin>>frase){
	    for(i=0;i<frase.length();i++){
        	if((frase[i]!='[')&&(frase[i]!=']')){
        		lista.push_back(frase[i]);
			}else if(frase[i]=='['){
        		string cadena;
        		while((frase[i+1]!='[')&&(frase[i+1]!=']')&&(frase[i+1]!='\0')&&(i<frase.length())){
        			cadena+=frase[i+1];
        			i++;				
				}
				for(int b=cadena.length()-1;b>=0;b--){
					lista.push_front(cadena[b]);			
				}
			}else if(frase[i+1]==']'){
				if(frase[i+2]=='[')
				lista.push_back(frase[i+1]);
				i++;
			}
		}
		for(int it=0;it<lista.size();it++){
			if((lista[it]!= '[')&&(lista[it]!= ']')){
				cout<<lista[it];
			}	
		}
		cout<<endl;
		lista.clear();
    }
    return 0;
} 