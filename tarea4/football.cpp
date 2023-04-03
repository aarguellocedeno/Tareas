//ANA GABRIELA ARGUELLO CEDENO - 8976713
//La complejidad del algoritmo es lineal es decir O(n), ya que no se cuentan los ciclos anidados porque estos 
// se cuentan desde la parte de pedida de datos, si se contara con esta parte del proceso, entonces la complejidad seria cuadrada es decir O(n^2)
//PUNTO 2

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
class 	Equipo{
	public:
		string nombre;
		int goles,part,pun,der,res,porc;
		Equipo(){
			nombre = "";
			pun =0;
			part = 0;
			goles = 0;
			der = 0;
			res = 0;
			porc =0;
			
		}
		Equipo (string equipo1,string equipo2,int pun1,int gol2,int numEqui,int numJug){
			this->nombre= nombre;
			this->pun = pun;
			this->part = part;
			this->goles= goles;
			this->der=der;
			this->res = res;
			this->porc = porc;
		}
	  	bool operator ==(const Equipo& equi){
    		bool ans = nombre == equi.nombre;
    	return ans;
  		}
  		
	  bool operator <(const Equipo& equi){
	    bool ans;
	    if(pun != equi.pun ){
	    	ans = pun > equi.pun;
		}
	    else{
	      ans = nombre < equi.nombre;
	    }
	    return ans;
	  }
	
};




	int main(){
	int numEqui,numJug,i,j,a=0,cnt=0,gol1,gol2,dif=0;
	string equipo1,equipo2,nom,completo,juego,salto;
	vector<string> equipos;
	vector<int> num;
	vector<Equipo> inequipo;
	vector<string> partidos;
	cin>> numEqui >> numJug;
	while((numEqui != 0)||(numJug != 0)){
		int tam = numEqui;
		string nome ;
		for(i=0; i<numEqui; i++){
			cin >> nom;
			Equipo name = Equipo();
			name.nombre = nom;
			inequipo.push_back(name);
			
		}
		for (j=0; j < numJug; j++){
			cin>>equipo1;
			scanf(" %d - %d ",&gol1,&gol2);
			cin>>equipo2;
			if(gol1 == gol2){
				for(a=0;a < inequipo.size();a++){
					if(inequipo[a].nombre == equipo1){
						Equipo point = Equipo();
						inequipo[a].der += gol2;
						inequipo[a].goles += gol1;
						inequipo[a].part += 1;
					}
					if(inequipo[a].nombre == equipo2){
						Equipo point = Equipo();
						inequipo[a].pun += 1;
						inequipo[a].der += gol2;
						inequipo[a].goles += gol1;
						inequipo[a].part += 1;
					}
				}
			}
			else if(gol1 < gol2){
				for(a=0;a < inequipo.size();a++){
					if(inequipo[a].nombre ==equipo2){
						inequipo[a].pun += 3;
						inequipo[a].der += gol1;
						inequipo[a].goles += gol2;
						inequipo[a].part += 1;
						
					}
					if(inequipo[a].nombre ==equipo1){
						inequipo[a].der += gol2;
						inequipo[a].goles += gol1;
						inequipo[a].part += 1;
					}
				}
			}
			else if(gol1 > gol2){
				for(a=0;a < inequipo.size();a++){
					if(inequipo[a].nombre == equipo1){
						inequipo[a].pun += 3;
						inequipo[a].der += gol2;
						inequipo[a].goles += gol1;
						inequipo[a].part += 1;
						
					}
					if(equipo2 == inequipo[a].nombre){
						inequipo[a].der += gol1;
						inequipo[a].goles += gol2;
						inequipo[a].part += 1;
					}
				}
			}				
			
		}
		for(i=0; i<inequipo.size();i++){
			inequipo[a].res += inequipo[i].goles - inequipo[i].der;
		}
		sort(inequipo.begin(),inequipo.end());
		for (auto it = inequipo.begin(); it != inequipo.end(); ++it) {
           cout << "              " << " " <<it->nombre << " "<< it->pun<< " " << it->part<< " " << it->goles<< " " << it->der << " "<< it->res<< " " << it->porc;
           cout << "\n";
       }
	cin>> numEqui >> numJug;
	equipos.clear();
	num.clear();
	partidos.clear();
	}
	return 0;
}
