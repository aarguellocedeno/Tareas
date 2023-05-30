#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <deque>
using namespace std;
typedef int Elemento;

class BigInteger{
  private:
    deque<int> bigInt;
  public:
  	BigInteger();
    BigInteger(const string& bignum); 
    BigInteger(const BigInteger &copy);
    void add(BigInteger &numTwo);
    void substract(BigInteger &numTwo);
    void product(BigInteger &numTwo);
    void quotient(BigInteger &numTwo);
    void remainder(BigInteger &numTwo);
    void pow(int num);
    string toString();
    BigInteger operator+(BigInteger &bigTwo);
    BigInteger operator-(BigInteger &bigTwo);
    BigInteger operator*(BigInteger &bigTwo);
    BigInteger operator/(BigInteger &bigTwo);
    BigInteger operator%(BigInteger &bigTwo);
    bool operator !=(BigInteger &numTwo);
    bool operator ==(BigInteger &numTwo);
    bool operator <(BigInteger &numTwo);
    bool operator <=(BigInteger &numTwo);
    static BigInteger sumarListaValores(deque<BigInteger>&lista);
    static BigInteger multiplicarListaValores(deque<BigInteger>&lista);
};

#endif