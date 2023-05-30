#include "BigInteger.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <deque> 

using namespace std;
/*
Ana Gabriela Argüello Cedeño
Proyecto- Estructura de datos
TAD - BigInteger
*/
BigInteger::BigInteger(){}

/*
Función constructora bigInteger copy
Entrada: un objeto de la instancia BigInteger.
Salida: la copia del objeto
Descripción: Esta funcion se encarga de copiar los dígitos del bigInteger de referencia en el objeto que se está creando.
*/
BigInteger::BigInteger(const BigInteger &copy){
	bigInt = copy.bigInt;
}

/*
Función constructora bigInteger
Entrada: un dato tipo string dado por referencia.
Salida: El bigInteger con los datos de la string.
Descripción: Esta funcion se encarga de construir el objeto bigInteger.
*/
BigInteger::BigInteger(const string& bignum){
	int num, i;
	for(i=0; i <bignum.length();i++){
		if(bignum[i]=='-'){
			i++;
			num = bignum[i]-48;
			num*=(-1);
			bigInt.push_back(num);
		}else if(bignum[i]!='.'){
			num = bignum[i];
			num-=48;
			bigInt.push_back(num);
		}
	}
}


/*
Función sobrecarga /
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha.
Descripción: Esta funcion se encarga de sobrecargar el operador / para poder hacer una división sin hacer el llamado a la operación quotient
*/
BigInteger BigInteger::operator/(BigInteger &bigTwo){
	BigInteger div, cop,aux,aux2;
	string divi;
	aux.bigInt.push_back(1);
	aux2.bigInt.push_back(0);
	int signo,same=0,cero=0;
	if(((bigInt[0]<0)&&(bigTwo.bigInt[0]>0))||((bigInt[0]>0)&&(bigTwo.bigInt[0]<0))){
		signo=1;
	}else if((bigInt[0]<0)&&(bigTwo.bigInt[0]<0)){
		signo=0;
	}
	cop.bigInt= bigInt;
	int flag=1,num=10,cnt=0,i;
	if(cop==bigTwo){
		cop.bigInt.clear();
		cop.bigInt.push_back(1);
	}else if(bigTwo.bigInt==aux.bigInt){
		same=1;
	}else if(bigInt==aux2.bigInt){
		cero=1;
	}else if((same==0)&&(cero==0)){
		while (flag!=0){
			cop.substract(bigTwo);
			cnt +=1;
			if (cop.bigInt<bigTwo.bigInt){
		 		flag=0;
		 	}
			if(bigTwo.bigInt==cop.bigInt){
				cnt++;
				cop.bigInt.clear();
				cop.bigInt.push_back(0);
				flag=0;
			}
		}
	}
	if(same==1){
		div = cop;
	}else if(cero==1){
		div= aux2;
	}else{
	divi= to_string(cnt);	
	div = BigInteger(divi);
	}


	return div;
}


/*
Función sobrecarga %
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha.
Descripción: Esta funcion se encarga de sobrecargar el operador % para poder sacar el residuo de una división sin hacer el llamado a la operación remainder
*/
BigInteger BigInteger::operator%(BigInteger &bigTwo){
	BigInteger div,cop;
	string divi;
	cop.bigInt= bigInt;
	int flag=1,num=10,cnt=0,i;
	if(cop==bigTwo){
		cop.bigInt.clear();
		cop.bigInt.push_back(1);
	}else{
		while (flag!=0){
			cop.substract(bigTwo);
			if (cop.bigInt<bigTwo.bigInt){
		 		flag=0;
		 	}
			if(bigTwo.bigInt==cop.bigInt){
				cop.bigInt.clear();
				cop.bigInt.push_back(0);
				flag=0;
			}
		}
	}
	return cop;
}

/*
Función sobrecarga *
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha.
Descripción: Esta funcion se encarga de sobrecargar el operador * para poder hacer una multiplicacion sin hacer el llamado a la operación product
*/
BigInteger BigInteger::operator*(BigInteger &bigTwo){
	int big1,big2,big3, i=0, j=0, neg=0, signo=0, prd=0, res=0, num=0,cas=0,d=0,t=0,s1=0,s2=0;
	deque<int>bigSal;
	BigInteger sali;
	big1=bigInt.size();
	big2=bigTwo.bigInt.size();
	deque<int>aux;
	if(bigInt[0] < 0){
		bigInt[0]*=(-1);
		neg=1;
	}else {
		neg=0;
	}
	if(bigTwo.bigInt[0]< 0){
		bigTwo.bigInt[0]*=(-1);
		neg+=1;
	}	
	if (neg==1) {
		signo = 1;
	}
	cas=-1;
	for(i=big2-1;i>=0;i--){
		cas+=1;
		d=cas;
		res=0;
		for(j=big1-1;j>=0;j--){
			if(big2==1){
				if((i==0) && (j==0)){
					num = num + res;
					bigSal[d] = num;
				}
			}
			if(i==big2-1){
				prd = (bigTwo.bigInt[i] * bigInt[j]) + res;
				num = prd % 10;
				bigSal.push_back(num);
				s1 +=1;
			}else{
				if(d==bigSal.size()){
					bigSal.push_back(0);
				}
				prd = (bigTwo.bigInt[i] * bigInt[j]) + res + bigSal[d];
				num = prd % 10;
				s2=bigSal.size();
				bigSal[d] = num;
			};
			res = (prd - num) / 10;
			d +=1;
		}
		if(res>0){
			bigSal.push_back(res);
			res =0;
		}
	}
	if(res>0){
		bigSal.push_back(res);
	}
	big3 = bigSal.size();
	if(signo==1){
			bigSal[big3-1]*=(-1);
		}
	for(i = big3-1; i>=0; i--){
		sali.bigInt.push_back(bigSal[i]);
	}
	return sali;
}


/*
Función sobrecarga -
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha.
Descripción: Esta funcion se encarga de sobrecargar el operador - para poder hacer una resta sin hacer el llamado a la operación substract
*/
BigInteger BigInteger::operator-(BigInteger &bigTwo){
	deque<int> sal;
	BigInteger copi,sali;
	copi.bigInt = bigInt;
	int aum=2,taille=bigInt.size(),i=0,men,pres=0,res,neg=0,num1,sumo=0,num2,si=0,signo=0;
	if((bigInt[0]< 0)&&(bigTwo.bigInt[0]< 0)){
			bigInt[0]*=(-1);
			bigTwo.bigInt[0]*=(-1);
			if(bigInt<bigTwo.bigInt){
				signo=0;
			}else{
				signo=1;
			}
			neg=1;
	}else if(((copi.bigInt[0]< 0)&&(bigTwo.bigInt[0]>=0))||((copi.bigInt[0]>=0)&&(bigTwo.bigInt[0]< 0))){
		if(bigTwo.bigInt[0]<0){
			bigTwo.bigInt[0]*=(-1);
			signo=0;
			copi.add(bigTwo); 
			sumo=1;
		}else if(copi.bigInt[0]<0){
			copi.bigInt[0]*=(-1);
			if(((copi<bigTwo)==0)||(copi==bigTwo)){
				neg=1;
			}
			signo=1;
			copi.add(bigTwo);  
			sumo=1;
		}
	}
	if(sumo==0){
		if(bigInt.size()==bigTwo.bigInt.size()){
			if(bigInt<bigTwo.bigInt){
				signo=1;
				aum=0;
				taille=bigTwo.bigInt.size();
				men= bigInt.size();
			}else if(bigTwo.bigInt<bigInt){
				aum=1;
				taille=bigInt.size();
				men= bigTwo.bigInt.size();
			}
		}else{
			if(bigInt.size()<bigTwo.bigInt.size()){
				signo=1;
				neg=1;
				aum=0;
				taille=bigTwo.bigInt.size();
				men= bigInt.size();
			}else if(bigTwo.bigInt.size()<bigInt.size()){
				aum=1;
				taille=bigInt.size();
				men= bigTwo.bigInt.size();
			}
		}
		if(aum!=2){
			for(i=men;i<taille ;i++){
				if (aum==0){
					bigInt.push_front(0);
				}else{
					bigTwo.bigInt.push_front(0);
				}
			}
		}
		if(aum==1){
			i=taille-1;
			while(i>=0){
				num1= bigInt[i]-si;
				num2= bigTwo.bigInt[i];
				if(num1<num2){
					num1 +=10;
					si=1;
				}else{
					si=0;
				}
				res= num1-num2;
				sal.push_front(res);
				i--;
			}
		}else if(aum==0){
			i=taille-1;
			si=0;
			while(i>=0){
				num1= bigTwo.bigInt[i]-si; 
				num2= bigInt[i];
				if(num1<num2){
					num1 +=10;
					si=1;
				}else{
					si=0;
				}
				res= num1-num2;
				sal.push_front(res);
				i--;
			}
		}else{
			bigInt.clear();
			sal.push_back(0);
		}
	}
	if(signo==1){
		sali.bigInt[0]*=(-1);
	}
	if(sumo==0){
		sali.bigInt= sal;
		if(neg==1){
			sali.bigInt[0]*=(-1);
		}
	}if(sumo==1){
		sali = copi;
	}
	return sali;
}


/*
Función sobrecarga +
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha.
Descripción: Esta funcion se encarga de sobrecargar el operador * para poder hacer una suma sin hacer el llamado a la operación add
*/
BigInteger BigInteger::operator+(BigInteger &bigTwo){
	deque<int> sal;
	BigInteger cop;
	int ori=bigInt.size(),aum=2,taille=bigInt.size(),i=0,men,resi=0,sum,num1,num2,neg=0,resto=0;

	for(i=0;i<bigInt.size();i++){
		cop.bigInt.push_back(bigInt[i]);
	}
	if((bigInt[0]< 0)&&(bigTwo.bigInt[0]< 0)){
			cop.bigInt[0]*=(-1);
			bigTwo.bigInt[0]*=(-1);
			neg=1;
	}else if(((cop.bigInt[0]< 0)&&(bigTwo.bigInt[0]>= 0))||((cop.bigInt[0]>=0)&&(bigTwo.bigInt[0]< 0))){
		if(bigTwo.bigInt[0]<0){
			bigTwo.bigInt[0]*=(-1);
			cop.substract(bigTwo);
			resto=1;
			if(bigInt<bigTwo.bigInt){
				neg=1;
			}
		}else if(cop.bigInt[0]<0){
			cop.bigInt[0]*=(-1);
			cop.substract(bigTwo);
			resto=1;
			if(bigTwo.bigInt<bigInt){
				neg=1;
			}
		}
	}
	if(cop.bigInt.size()==bigTwo.bigInt.size()){
		if(cop.bigInt<bigTwo.bigInt){
			aum=0;
			taille=bigTwo.bigInt.size();
			men= bigInt.size();
		}else if(bigTwo.bigInt<bigInt){
			aum=1;
			taille=cop.bigInt.size();
			men= bigTwo.bigInt.size();
		}
	}else{
		if(bigInt.size()<bigTwo.bigInt.size()){
			aum=0;
			neg=2;
			taille=bigTwo.bigInt.size();
			men= cop.bigInt.size();
		}else if(bigTwo.bigInt.size()<bigInt.size()){
			aum=1;
			neg=2;
			taille=cop.bigInt.size();
			men= bigTwo.bigInt.size();
		}
	}
	if(aum!=2){
		for(i=men;i<taille ;i++){
			if (aum==0){
				cop.bigInt.push_front(0);
			}else{
				bigTwo.bigInt.push_front(0);
			}
		}
	}
	i=taille-1;
	while(i>=0){
		num1= cop.bigInt[i];
		num2= bigTwo.bigInt[i];
		sum= num1 + num2+resi;
 		if(sum>=9){
 			sum=(num1+num2+resi)%10;
 		}
 		sal.push_front(sum);
 		resi= (num1+num2+resi)/10;
		if((i==0)&&(resi!=0)){
			sal.push_front(resi);
		}
	  	i--;
	}
	if(resto==0){
		cop.bigInt.clear();
		for(i=0;i<sal.size();i++){
			cop.bigInt.push_back(sal[i]);
		}
	}
	if(neg==1){
		cop.bigInt[0]*=(-1);
	}
	return cop;
}


/*
Función sobrecarga ==
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un dato de tipo bool que diga si el caso es o no es igual.
Descripción: Esta funcion se encarga de sobrecargar el operador == para saber si dos objetos bigIntegers son iguales o no
*/
bool BigInteger::operator==(BigInteger &bigTwo){
	bool ans=0;
	int i,cnt=0;
	if((bigInt.size())!=(bigTwo.bigInt.size())&&(bigInt[0]==bigTwo.bigInt[0])){
		for(i=0;i<bigInt.size();i++){
			if(bigInt[i]==bigTwo.bigInt[i]){
				cnt++;
			}
		}
		if(cnt==bigInt.size()){
			ans=1;
		}else{
			ans=0;
		}
		
	}else{
		for(i=0;i<bigInt.size();i++){
			if(bigInt[i]==bigTwo.bigInt[i]){
				cnt++;
			}
		}
		if(cnt==bigInt.size()){
			ans=1;
		}
	}
	return ans;
}

/*
Función sobrecarga <
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un dato de tipo bool que diga si un objeto bigInteger es menor que otro objeto de la misma instancia
Descripción: Esta funcion se encarga de sobrecargar el operador < para saber si un bigInteger es menor que otro.
*/
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

/*
Función sobrecarga <=
Entrada: un objeto de instancia bigInteger dado por referencia.
Salida: un dato de tipo bool que diga si un objeto bigInteger es menor o igual que otro objeto de la misma instancia
Descripción: Esta funcion se encarga de sobrecargar el operador < para saber si un bigInteger es menor o igual que otro.
*/
bool BigInteger::operator<=(BigInteger &bigTwo){
	BigInteger num1,num2;
	num1.bigInt=bigInt;
	num2.bigInt=bigTwo.bigInt;
	bool ans=true;
	if(num1==num2){
		ans=true;
	}else if(num1<num2){
		ans=true;
	}else{
		ans=false;
	}
	return ans;
}

/*
Función toString
Entrada: un objeto de instancia bigInteger.
Salida: un dato de tipo string con los datos del bigInteger dado
Descripción: Esta funcion se encarga de crear una string con los datos del bigInteger
*/

string BigInteger::toString(){
	string num ="";
	deque<char> aux;
	int sum,i;
	for( i=0;i<bigInt.size();i++){
		if(bigInt[i]<0){
			num += '-';
			num +=((bigInt[i]*(-1))+'0');
		}else{
			num += bigInt[i]+'0';	
		}	
	}
	return num;
}

/*
Función sumarListasValores
Entrada: una lista de objetos de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha;
Descripción: Esta funcion se encarga de sumar los objetos biginteger que estan en la lista
*/
BigInteger BigInteger::sumarListaValores(deque<BigInteger>&lista){
	BigInteger aux,aux2;
	int i=0;
	aux = lista[0];
	for(i=1;i<lista.size();i++){
		aux2= aux + lista[i];
		aux=aux2;
	}
	return aux;
}

/*
Función MultiplicarListaValores
Entrada: una lista de objetos de instancia bigInteger dado por referencia.
Salida: un objeto bigInteger con la operacion hecha;
Descripción: Esta funcion se encarga de multiplicar los objetos biginteger que estan en la lista
*/
//en el proyecto esta en mayuscula pero en el main de prueba esta con minuscula, entonces lo cambie.
BigInteger BigInteger::multiplicarListaValores(deque<BigInteger>&lista){
	BigInteger aux,aux2;
	int i=0;
	aux = lista[0];
	for(i=1;i<lista.size();i++){
		aux2= aux * lista[i];
		aux=aux2;
	}
	return aux;
}


/*
Operación quotient
Entrada: Un objeto de instancia BigInteger que sera el divisor.
Descripción: Esta operación se encarga de realizar la division, donde el divisor sera
el bigInteger de referencia y el dividendo es el objeto BigInteger que invoca dicha operacion
*/
void BigInteger::quotient(BigInteger &bigTwo){
	BigInteger div, cop,aux,aux2;
	string divi;
	aux.bigInt.push_back(1);
	aux2.bigInt.push_back(0);
	int signo,same=0,cero=0;
	if(((bigInt[0]<0)&&(bigTwo.bigInt[0]>0))||((bigInt[0]>0)&&(bigTwo.bigInt[0]<0))){
		signo=1;
	}else if((bigInt[0]<0)&&(bigTwo.bigInt[0]<0)){
		signo=0;
	}
	cop.bigInt= bigInt;
	int flag=1,num=10,cnt=0,i;
	if(cop==bigTwo){
		cop.bigInt.clear();
		cop.bigInt.push_back(1);
	}else if(bigTwo.bigInt==aux.bigInt){
		same=1;
	}else if(bigInt==aux2.bigInt){
		cero=1;
	}else if((same==0)&&(cero==0)){
		while (flag!=0){
			cop.substract(bigTwo);
			cnt +=1;
			if(cop.bigInt<bigTwo.bigInt){
		 		flag=0;
		 	}
			if(bigTwo.bigInt==cop.bigInt){
				cnt++;
				cop.bigInt.clear();
				cop.bigInt.push_back(0);
				flag=0;
			}
		}
	}
	if(same==1){
		div = cop;
	}else if(cero==1){
		div= aux2;
	}else{
		divi= to_string(cnt);	
		div = BigInteger(divi);
	}
	bigInt.clear();
	bigInt = div.bigInt;
}


/*
Operación remainder
Entrada: Un objeto de instancia BigInteger dado por referencia.
Descripción: Esta operación se encarga de devolver el residuo de la division entre el objeto bigInteger y el dado como referencia
*/
void BigInteger::remainder(BigInteger &bigTwo){
	BigInteger div, cop,hey;
	string divi;
	cop.bigInt= bigInt;
	int flag=1,num=10,cnt=0,i;
	if(cop==bigTwo){
		cop.bigInt.clear();
		cop.bigInt.push_back(1);
	}else{
		while (flag!=0){
			cop.substract(bigTwo);
			cnt +=1;
			if (cop.bigInt<bigTwo.bigInt){
		 		flag=0;
		 	}
			if(bigTwo.bigInt==cop.bigInt){
				cop.bigInt.clear();
				cop.bigInt.push_back(0);
				flag=0;
			}
		}
	}
	bigInt.clear();
	bigInt=cop.bigInt;
}

/*
Operación product
Entrada:  Un objeto de instancia BigInteger que sera el multiplicador
Descripción: Esta operación se encarga de realizar la Multiplicacion, donde el multiplicador sera
el bigInteger de referencia y el multiplicado es el objeto BigInteger que invoca dicha operacion
*/
void BigInteger::product(BigInteger &bigTwo){
	int big1,big2,big3, i=0, j=0, neg=0, signo=0, prd=0, res=0, num=0,cas=0,d=0,t=0,s1=0,s2=0;
	deque<int>bigSal;
	big1=bigInt.size();
	big2=bigTwo.bigInt.size();
	deque<int>aux;
	if(bigInt[0] < 0){
		bigInt[0]*=(-1);
		neg=1;
	}else if(bigTwo.bigInt[0]< 0){
		bigTwo.bigInt[0]*=(-1);
		neg+=1;
	}else{
		neg=0;
	}
	if(neg==1) {
		signo = 1;
	}
	cas=-1;
	for(i=big2-1;i>=0;i--){
		cas+=1;
		d=cas;
		res=0;
		for(j=big1-1;j>=0;j--){
			if(big2 == 1){
				if ((i==0) && (j==0)){
					num += res;
					bigSal[d] = num;
				}
			}
			if(i==big2-1){
				prd = (bigTwo.bigInt[i] * bigInt[j]) + res;
				num = prd % 10;
				bigSal.push_back(num);
				s1 +=1;
			}else{
				if(d==bigSal.size()){
					bigSal.push_back(0);
				}
				prd = (bigTwo.bigInt[i] * bigInt[j]) + res + bigSal[d];
				num = prd % 10;
				bigSal[d] = num;
			};
			res= ((prd - num) / 10);
			d+=1;
		}
		if (res>0){
			bigSal.push_back(res);
			res=0;
		}
	}
	if (res>0){
		bigSal.push_back(res);
	}
	if (signo==1){
			bigSal[bigSal.size()-1]*=(-1);
		}

	bigInt.clear();
	for(i = bigSal.size()-1; i>=0; i--){
		bigInt.push_back(bigSal[i]);
	}

}

/*
Operación pow
Entrada: Un un numero dado por referncia
Descripción: Esta operación se encarga de realizar la potencia al objeto de instancia bigInteger, es
decir que aplica el pow al objeto que invoca dicha operacion
*/
void BigInteger::pow(int num3){
	int big1,big2,big3, i=0, j=0, neg=0, signo=0, prd=0, res=0, num=0,c=0,d=0,t=0,k=0,s1=0,s2=0,par=0,salida;
	if(bigInt[0] < 0){
		bigInt[0]*=(-1);
		par = num3 % 2;
		if (par==0){
			signo=0;
		}else{
			signo=1;
		}
	}
	BigInteger bigTwo,aux;
	bigTwo.bigInt = bigInt;
	aux.bigInt = bigInt;
	if (num3 == 0){
		salida = 0;
	}else if(num3 == 1){
		salida = 1;
	}else{
		for (k=1;k<num3;k++){
			aux.product(bigTwo);
		}
	}
	if (salida==0){
		bigInt.clear();
		bigInt.push_back(1);
	}
	if(par!=0){
		aux.bigInt[0]*=(-1);
	}if(salida==1){
		bigInt.clear();
		bigInt=aux.bigInt;
	}
}



/*
Operación substract
Entrada: Un objeto de instancia BigInteger que sera el sustraendo.
Descripción: Esta operación se encarga de realizar la resta, donde el sustraendo sera
el bigInteger de referencia y el minuendo es el objeto BigInteger que invoca dicha operacion
*/
void BigInteger::substract(BigInteger &bigTwo){
	deque<int> sal;
	int aum=2,taille=bigInt.size(),i=0,men,pres=0,res,neg=0,num1,sumo=0,num2,si=0,signo=0;
	if((bigInt[0]< 0)&&(bigTwo.bigInt[0]< 0)){
			bigInt[0]*=(-1);
			bigTwo.bigInt[0]*=(-1);
			if(bigInt<bigTwo.bigInt){
				signo=0;
			}else{
				signo=1;
			}
			
	}else if(((bigInt[0]< 0)&&(bigTwo.bigInt[0]>=0))||((bigInt[0]>=0)&&(bigTwo.bigInt[0]< 0))){
		if(bigTwo.bigInt[0]<0){
			bigTwo.bigInt[0]*=(-1);
			signo=0;
			add(bigTwo);
			sumo=1;
		}else if(bigInt[0]<0){
			bigInt[0]*=(-1);
			signo=1;
			add(bigTwo);
			sumo=1;
		}
	}
	if(sumo==0){
		if(bigInt.size()==bigTwo.bigInt.size()){
			if(bigInt<bigTwo.bigInt){
				signo=1;
				aum=0;
				taille=bigTwo.bigInt.size();
				men= bigInt.size();
			}else if(bigTwo.bigInt<bigInt){
				aum=1;
				taille=bigInt.size();
				men= bigTwo.bigInt.size();
			}
		}else{
			if(bigInt.size()<bigTwo.bigInt.size()){
				signo=1;
				aum=0;
				taille=bigTwo.bigInt.size();
				men= bigInt.size();
			}else if(bigTwo.bigInt.size()<bigInt.size()){
				aum=1;
				taille=bigInt.size();
				men= bigTwo.bigInt.size();
			}
		}
		if(aum!=2){
			for(i=men;i<taille ;i++){
				if (aum==0){
					bigInt.push_front(0);
				}else{
					bigTwo.bigInt.push_front(0);
				}
			}
		}
		i=taille-1;
		if(aum==1){
			while(i>=0){
				num1= bigInt[i]-si;
				num2= bigTwo.bigInt[i];
				if(num1<num2){
					num1 +=10;
					si=1;
				}else{
					si=0;
				}
				res= num1-num2;
				sal.push_front(res);
				i--;
			}
		}else if(aum==0){
			while(i>=0){
				num1= bigTwo.bigInt[i]-si; 
				num2= bigInt[i];
				if(num1<num2){
					num1 +=10;
					si=1;
				}else{
					si=0;
				}
				res= num1-num2;
				sal.push_front(res);
				i--;
			}
		}else{
			bigInt.clear();
			sal.push_back(0);
			bigInt.push_back(0);
		}
	}
	if(sumo==0){
		bigInt.clear();
		int a=0;
		for(i=0;i<sal.size();i++){
			bigInt.push_back(sal[i]);
		}
	}
	if(signo==1){
		bigInt[0]*=(-1);
	}
}






/*
Operación add
Entrada: Un objeto de instancia BigInteger que sera el sumando.
Descripción: Esta operación se encarga de realizar la suma, donde el objeto a sumar es el bigInteger
que invoca la operacion, y por el que se va a sumar sera el objeto bigInteger de referencia
*/
void BigInteger::add(BigInteger &bigTwo){
	deque<int> sal;
	int ori=bigInt.size(),aum=2,taille=bigInt.size(),i=0,men,resi=0,sum,num1,num2,neg=0,resto=0;
	for(i=0;i<bigInt.size();i++){
		cout<<bigInt[i]<<" ";
	}
	if((bigInt[0]< 0)&&(bigTwo.bigInt[0]< 0)){
			bigInt[0]*=(-1);
			bigTwo.bigInt[0]*=(-1);
			neg=1;
	}else if(((bigInt[0]< 0)&&(bigTwo.bigInt[0]>= 0))||((bigInt[0]>=0)&&(bigTwo.bigInt[0]< 0))){
		if(bigTwo.bigInt[0]<0){
			bigTwo.bigInt[0]*=(-1);
			substract(bigTwo);
			resto=1;
			if(bigInt<bigTwo.bigInt){
				neg=1;
			}
		}else if(bigInt[0]<0){
			bigInt[0]*=(-1);
			substract(bigTwo);
			resto=1;
			if(bigTwo.bigInt<bigInt){
				neg=1;
			}
		}
	}
	if(bigInt.size()==bigTwo.bigInt.size()){
		if(bigInt<bigTwo.bigInt){
			aum=0;
			taille=bigTwo.bigInt.size();
			men= bigInt.size();
		}else if(bigTwo.bigInt<bigInt){
			aum=1;
			taille=bigInt.size();
			men= bigTwo.bigInt.size();
		}
	}else{
		if(bigInt.size()<bigTwo.bigInt.size()){
			
			aum=0;
			neg=2;
			taille=bigTwo.bigInt.size();
			men= bigInt.size();
		}else if(bigTwo.bigInt.size()<bigInt.size()){
			aum=1;
			neg=2;
			taille=bigInt.size();
			men= bigTwo.bigInt.size();
		}
	}
	if(aum!=2){
		for(i=men;i<taille ;i++){
			if (aum==0){
				bigInt.push_front(0);
			}else{
				bigTwo.bigInt.push_front(0);
			}
		}
	}
	i=taille-1;
	while(i>=0){
		num1= bigInt[i];
		num2= bigTwo.bigInt[i];
		sum= num1 + num2+resi;
 		if(sum>=9){
 			sum=(num1+num2+resi)%10;
 		}
 		sal.push_front(sum);
 		resi= (num1+num2+resi)/10;
		if((i==0)&&(resi!=0)){
			sal.push_front(resi);
		}
	  	i--;
	}
	if(resto==0){
		bigInt.clear();
		for(i=0;i<sal.size();i++){
			bigInt.push_back(sal[i]);
		}
	}
	if(neg==1){
		bigInt[0]*=(-1);
	}
	
}
