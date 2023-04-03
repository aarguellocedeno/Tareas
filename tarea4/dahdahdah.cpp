//Ana GABRIELA ARGUELLO CEDEÑO - 8976713 
// PUNTO 1
// este programa tiene una complejidad constante es decir O(1) en el mejor caso donde solo hay un caso, y una cadena a traducir, y 
// en el peor caso es lineal es decir O(n).
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
// 1
int main(){
	vector<string> messa;
	int cases,i=0,j=0,a=0,b=0;
	int espa= 0;
	string codigo= "";
	string cod= "";
	char let[55][55]={"A" ,"B","C","D" ,"E" ,"F" ,"G" ,"H" ,"I" ,"J" ,"K" ,"L", "M" ,"N" ,"O" ,"P" ,"Q" ,"R" ,"S" ,"T" ,"U" ,"V" ,"W","X","Y" ,"Z","0" ,"1" ,"2", "3" ,"4","5" ,"6" ,"7","8","9", ".", "," , "?" , "'" ,"!","/","(" ,")", "&", ":" , ";", "=", "+","-", "_" ,"\"" ,"@"," " };
	char mor[55][55]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."," "};
	scanf("%d\n",&cases);
	while(i<=cases-1){
		getline(cin,cod); 
		a = 0;
		while(a < cod.length() ){
			if (cod[a] != ' '){
				codigo += cod[a];
				espa = 0;
			}
			else if(cod[a] == ' '){
				messa.push_back(codigo);
				espa += 1;
				codigo.clear();
			}if(espa == 2){
				messa.push_back(" ");
			}
			
		a++;
		} 
		if(codigo.length() > 0){
			messa.push_back(codigo);
			codigo.clear();
		}
		cout<<"Message #"<<i+1<<"\n";
		for(b =0; b < messa.size();b++){
			for(j = 0; j < 54;j++){
				if(messa[b] == mor[j]){
					cout << let[j];
				}
			}
		}
		messa.clear();
		cod.clear();
		espa= 0;
		if(i < cases){
			cout << "\n";
		}
		i++; 
		if(i < cases){
			cout << "\n";
		}
		
	}
	return 0;
}


