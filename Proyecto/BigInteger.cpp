#include "BigInteger.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

//falta modificarlo para cuando sean decimales
BigInteger::BigInteger(const string& bignum){
	//bigInt es un vector que se a creado en la clase bigInteger
	int num,neg;
	for(int i=0; i <bignum.length() ;i++){
		if(bignum[0]=='-'){
			num = bignum[i]-48;
			num-= num*2;
			bigInt.push_back(num);
		}
		else{
			num = bignum[i];
			num-=48;
			bigInt.push_back(num);	
			tam += 1;
		}
	}
	
}

void BigInteger::substract(BigInteger &bigTwo){
	int taille=bigInt.size(),i,uno,dos;
	if(bigInt.size()>bigTwo.tam){
		taille =bigTwo.tam;
	}
	for(i=1;i<=taille;i++){
		uno=bigInt[bigInt.size()-i];
		dos=bigTwo.bigInt[bigTwo.bigInt.size()-i];
		if(uno<dos){
			bigInt[bigInt.size()-i]+=10;
			bigInt[bigInt.size()-(i+1)]-= 1;
			bigInt[bigInt.size()-i]-=dos;
		}else{
			bigInt[bigInt.size()-i]-=dos;
		}
	}
	
}


void BigInteger::add(BigInteger &bigTwo){
	int taille=bigInt.size(),i,uno,dos,sum;
	if(bigInt.size()>bigTwo.tam){
		taille =bigTwo.tam;
	}
	for(i=1;i<=taille;i++){
		uno=bigInt[bigInt.size()-i];
		dos=bigTwo.bigInt[bigTwo.bigInt.size()-i];
		sum = uno+dos;
		if(sum>=10){
			sum-=10;
			bigInt[bigInt.size()-i]=sum;
			bigInt[bigInt.size()-(i+1)]+= 1;
		}else{
			bigInt[bigInt.size()-i]+=dos;
		}
	}	
}



string BigInteger::toString(){
	string num ="";
	int sum;
	for(int i=0;i<bigInt.size();i++){
		if(bigInt[i]<0){
			num += '-';
			num +=(bigInt[i]-(bigInt[i]*2))+'0';
		}else{
			num += bigInt[i]+'0';	
		}	
	}
	return num;
}




