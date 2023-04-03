//ANA GABRIELA ARGÜELLO CEDEÑO-8976713
//PUNTO 3
//la complejidad de este algoritmo es lineal es decir O(n) ya que no se encuentran cilos anidados(en el porceso), y
// en cada for se ejecutara n veces en uno se ejecuta n+1 y en otro for se ejecuta n;
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int i,j,g,p,a,inte,puntos,num,typeScore,aux,ide;
	vector<int> ans;
	cin >> g >> p;

	while((g != 0)||(p != 0)){
	int resu[g][p];
	for(i=0;i<g;i++){
		for(j=0;j<p;j++){
			cin >> num;
			resu[i][j] = num;
		}
	}
	
	cin >> typeScore;
	for(i=0;i<typeScore;i++){
		int puntaje[p]{0};
		int cnt = 0;
		vector<int> ans;
		cin >> inte;
		int igual[p]{0};
		int point[p]{0};
		for(j=0;j<inte;j++){
			cin >>puntos;
			point[j]= puntos;
		}	
		for(a=0;a<g;a++){
			for(j=0;j<p;j++){
				aux = resu[a][j] ;
				puntaje[j] +=  point[aux-1];
			}
		} 
	int may = puntaje[0];
	for(j=1;j<p;j++){
		if(puntaje[j]>may){
			may = puntaje[j];
		}
	}
	for(j=0;j<p;j++){
		if(may==puntaje[j]){
			cnt += 1;
			ans.push_back(j+1);
		}
	}
	for(j=0;j<=cnt-1;j++){
		if(j<cnt-1){
			cout <<ans[j]<<' ';
		}
		if(j==cnt-1){
			cout <<ans[j];
		}
	}
	cout << "\n";
	may = 0;
	}
	cin >> g >> p;
	}
	return 0;
}