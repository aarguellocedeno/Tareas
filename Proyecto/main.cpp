#include "BigInteger.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void numero(){
	int i=0,flag=1,cnt=1;
	string bignum,bigOne,bigTwo;
	getline(cin,bignum);
	while((i<bignum.length())&&(flag!=0)){
		if(bignum[i] != ' '){
			bigOne += bignum[i];
			cnt++;
		}else{
			flag = 0;
		}
		i++;
	}
	for(cnt;cnt<bignum.length();cnt++){
		bigTwo += bignum[cnt];
	}
	BigInteger num= BigInteger(bigOne);
	BigInteger num2= BigInteger(bigTwo);
	num.add(num2);
	num.toString();
}


int main(){
	int i=0,j,sum,flag=1,cnt=1;
	scanf("%d\n",&sum);

	for(j=0;j<sum;j++){
		numero();
	}
	return 0;
}