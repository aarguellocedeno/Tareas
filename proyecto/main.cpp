/*
Ana Gabriela Argüello Cedeño
problema B: biggersmaller

*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <deque> 

using namespace std;

typedef int Elemento;

class BigInteger{
  private:
    deque<int> bigInt;
  public:
  	BigInteger();
    BigInteger(const string& bignum);
	bool operator ==(BigInteger &numTwo);
	bool operator <(BigInteger &numTwo);
};


BigInteger::BigInteger(){}
/*
La complejidad de este algoritmo es O(n) donde n es el tamaño de la cadena que se da como parametro, esta complejidad es asi por el motivo de que se usa un for
que itera desde 0 hasta n-1, dentro de este for se lo que se hace es ir agregando los elementos de la cadena(transformados a int),al bigInt de la calse biginteger
en este cuando un numero de la cadena es negativo lo que se hace es primero transformarlo a int y luego multiplicarlo * -1 para que siga negativo
*/
BigInteger::BigInteger(const string& bignum){
	int num, i;
	for(i=0; i<bignum.length();i++){
		if(bignum[i]=='-'){
			i++;
			num = bignum[i]-48;
			num*=(-1);
			bigInt.push_back(num);
		}else{
			num = bignum[i];
			num-=48;
			bigInt.push_back(num);
		}
	}
}


bool BigInteger::operator==(BigInteger &bigTwo){
	bool ans=false;
	int i,cnt=0;
	if((bigInt.size())!=(bigTwo.bigInt.size())&&(bigInt[0]==bigTwo.bigInt[0])){
		for(i=bigInt.size();i<bigTwo.bigInt.size();i++){
			bigInt.push_back(0);
		}
		for(i=0;i<bigInt.size();i++){
			if(bigInt[i]==bigTwo.bigInt[i]){
				cnt++;
			}
		}
		if(cnt==bigInt.size()){
			ans=true;
		}else{
			ans=false;
		}
		
	}else{
		for(i=0;i<bigInt.size();i++){
			if(bigInt[i]==bigTwo.bigInt[i]){
				cnt++;
			}
		}
		if(cnt==bigInt.size()){
			ans=true;
		}
	}
	return ans;
}


bool BigInteger::operator<(BigInteger &bigTwo){
	int cnt1=0,cnt2=0,i=0,flag=1;
	bool ans=false;
	if(bigInt.size()==bigTwo.bigInt.size()){
		if(bigInt[0]>bigTwo.bigInt[0]){
			ans=false;
		}else{
			while((i<bigInt.size())&&(ans!=true)){
				if(bigInt[i]<bigTwo.bigInt[i]){
					ans=true;
				}else if(bigInt[i]>bigTwo.bigInt[i]){
					ans=false;
				}
				i++;	
			}
		}
	}
	if(bigInt.size()<bigTwo.bigInt.size()){
		ans=true;
	}else if(bigInt.size()>bigTwo.bigInt.size()){
		ans=false;
	}
	return ans;
}


int main() {
    string bignum;
	int casos=0;
	while(getline(cin, bignum) && !cin.eof()){
		string bigOne,bigTwo,p1,p2;
		int i=0,cnt=1,point=0;
        bool flag=true;
		BigInteger num,num2,deci1,deci2;
		while((i<bignum.length())&&(flag!=false)){
			if(bignum[i] != ' '){
				if(bignum[i]=='.'){
					point=1;
				}
				if(point==0){
					bigOne += bignum[i];
					cnt++;
				}else if(point==1){
					point=2;
					cnt++;
				}else if(point==2){
					p1 +=bignum[i];
					cnt++;
				}
			}else{
				flag = false;
			}
			i++;
		}
		point=0;
		for(cnt;cnt<bignum.length();cnt++){
				if(bignum[cnt]=='.'){
					point=1;
				}
				if(point==0){
					bigTwo += bignum[cnt];
				}else if(point==1){
					point=2;
				}else if(point==2){
					p2 +=bignum[cnt];
				}
		}
		num= BigInteger(bigOne);
		num2= BigInteger(bigTwo);
		deci1= BigInteger(p1);
		deci2= BigInteger(p2);
		casos+=1;
		printf("Case %d: ",casos);
        if(bigOne.length()>bigTwo.length()){
            if(num<num2){
                printf("Smaller\n");
            }else{
                printf("Bigger\n");
            }
        }else if(bigOne.length()<bigTwo.length()){
            printf("Smaller\n");
        }else if(bigOne.length()==bigTwo.length()){
            if(num==num2){
                if(deci1==deci2){
                    printf("Same\n");
                }else if(deci1<deci2){
                    printf("Smaller\n");
                }else{
                    printf("Bigger\n");
                }
            }else if(num<num2){
                printf("Smaller\n");
            }else{
                printf("Bigger\n");
            }

        }

	}
    return 0;
}



