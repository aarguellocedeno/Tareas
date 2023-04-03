//ANA GABRIELA ARGUELLO CEDEÑO - 8976713 
// la complejidad de este algoritmo es O(nlogn) ya que se divide en la mitad pero igual se usa la otra mitad, si en el caso contratrio solo se usara una de las mitades la complejidad podria cambiar a O(log2n)
// PUNTO 4
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

bool compara(char a,char b){
	bool ans = true;
	int as1 = int(a);
	int as2 = int(b);
	if ((a == b) ||(as1 == as2-1)){
		ans = false;
	}
	return ans;
}


int main(){
	vector <string> org;
	vector <string> gru1;
	vector <string> gru2;
	int casos;
	cin>>casos;
	
	while(casos != 0){
		vector <char> cara1;
		vector <char> cara2;
		char let[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		int i=0,j,cas,flag=1,flag2=1,cnt=0,cnt2=0,asc1=0,asc2=0;
		string asis,cadena;
		bool proceso;
		
		
		for(i=0;i<casos;i++){
			cin>>asis;
			org.push_back(asis);
			
		}
		sort(org.begin(),org.end());
		
		cas = casos /2;
	    for (auto it=org.begin();it !=org.begin()+ cas;it++) {
	    	gru1.push_back(*it);
		}
		
	    for (auto it=org.begin()+ cas; it !=org.end();it++) {
	    	gru2.push_back(*it);
		}
 		int g1 = gru1[cas-1].size();
	   for (i = 0; i < g1; i++) {
	      cara1.push_back(gru1[cas-1][i]);
	      cnt +=1;
	   }
	   int g2 = gru2[0].size();
	   for (i = 0; i < g2; i++) {
	      cara2.push_back(gru2[0][i]);
	      cnt2 +=1;
	   }
	
	    proceso = compara(cara1[0] , cara2[0]);
	
	    if(proceso == 1){
	    	if(cnt ==1){
	    		cout <<cara1[0];
			}
	    	else{
				for(i=0;i <= 25;i++){
	    			if(cara1[0] == let[i]){
	    				cout <<let[i+1];
					}
				}
			}
		
		}
		else{
			if (cnt == 1){
		   		cout <<cara1[0];
			}
			else{
				if(cara1[0]==cara2[0]){
					i = 0;
					int c1 = cara1.size();
					while((i<c1) && (flag !=0)){
						if(cara1[i]==cara2[i]){
							cadena += cara1[i];
						}
						else{
							asc1 = int(cara1[i]);
							asc2 = int(cara2[i]);
							if(cnt == 2){ 
								cadena += cara1[i];	
								flag = 0;
							}
							else{
								if(asc1 != asc2-1 ){
										while((flag !=0)&&(j<=25)){
											if(let[j] == cara1[i]){
												cadena += let[j+1];
												flag = 0;
											}
										j++;	
								 		}
								}
								else{
									if(cnt2 == 2){
										cadena += cara1[i];
										flag =0;
									while(j<=25){
										if(let[j] == cara1[i+1]){
											cadena += let[j+1];
										}
									j++;	
									}
									}else{
										if(cnt == cnt2){
											cadena += cara1[i];
											flag = 0;	
										}
										else{
											cadena += cara2[i];
											flag = 0;	
										}
									}
										
								}
							}
						}
					i++;
					}
				}else{
					int c12 = cara1.size();
					if(cnt2 == 1){
						cadena += cara1[0];
						while((i<c12)&&(flag != 0)){
							flag2 = 1;
							while((j<=25)&&(flag2 != 0)&&(flag !=0)){
									if(cara1[i] == 'Z'){
										cadena += cara1[i];
										flag2 = 0;
									}else if(let[j] == cara1[i]){
										cadena += let[j+1];
										flag = 0;
									}
								j++;	
								}
						i++;	
						}
						
						
					}else{
						cout<< cara2[0];
					}
				}
		
			}
			
		}
	j=0;
	i =0;
	cout << cadena;
	cnt = 0;
	cnt2=0;
	cadena = "";
	flag = 1;
	flag2 = 1;
	asc1 = 0;
	asc2 = 0;
	proceso = 0;
    org.clear();
    cara1.clear();
    cara2.clear();
    gru1.clear();
    gru2.clear();
    cout << "\n";
	cin>>casos;

	}
}