#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
using namespace std;
//Ana Gabriela Arguello Cedeno
/*
Este algoritmo tiene una complejidad de O(k*n^2), donde k es el tamaño de la lista y n es el tamaño de las letras
Dentro del for que itera k veces, se encuentra otros dos ciclos el primero itera n veces, ese ciclo lo que hace 
es pasar los datos de la lista de letras a una lista auxiliar, el otro ciclo itera n^2 puesto que dentro de él
hay otro ciclo el cual en su peor caso itera n veces.
Juntando esa complejidad con la del for principal se obtiene la mencionada anteriormente que es O(k*n^2)
*/
int main(){
	string words,letters;
	deque<string> listW;
	cin>>words;
	while(words[0]!='#'){
		listW.push_back(words);
		cin>>words;
	}
	getline(cin,letters);
	int imp=0;
	deque<string> aux;
	while(letters[0]!='#'){
		int a=0,let=0;
		char num;
		let = letters.length();
		deque<char> listLet;
		while(a < let ){
			if(letters[a]!= ' '){
				num= letters[a];
				listLet.push_back(num);	
			}
		a++;
		}
		int cnt=0,tamList,tamLet;
		tamList = listW.size();
		tamLet = listLet.size();
		for(int i=0;i<tamList;i++){
			int flag=1,pos=0,let=0,pale=0;
			deque<char> aux;
			for(int b=0;b<tamLet;b++){
				aux.push_back(listLet[b]);
			}
			int j=0;
			while(j<=tamLet){
				int entra= 1;
				deque<char>::iterator a=aux.begin();
				while((entra!=0)&&(a!=aux.end())){
					if(listW[i][pos]==*a){
						let++;
						pos++;
						aux.erase(a);
						entra=0;	
					}else{
						if((aux.size()==1)&&(listW[i][pos]==*a)){
							let++;
							pos++;
							aux.erase(a);
							entra=0;	
						}
						a++;
					}
				}
				j++;
			}
			pale=listW[i].size();
			if(let==pale){
				cnt++;
			}
		}
		if(imp!=0){
			cout<<cnt<<endl;
		}
		imp++;
		getline(cin,letters);
	}
}
