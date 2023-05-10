#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
typedef int Elemento;

class BigInteger{
  private:
    string bignum="";
    vector<int> bigInt;
  public:
    BigInteger(const string& bignum); 
    BigInteger(BigInteger &copy);
    void add(BigInteger &numTwo);
    void substract(BigInteger &numTwo);
    void product(BigInteger &numTwo);
    void quotient(BigInteger &numTwo);
    void remainder(BigInteger &numTwo);
    void pow(int num);
	string toString();
	BigInteger operator+(BigInteger &numTwo);
	BigInteger operator-(BigInteger &numTwo);
	BigInteger operator*(BigInteger &numTwo);
	BigInteger operator/(BigInteger &numTwo);
	BigInteger operator%(BigInteger &numTwo);
	bool operator ==(BigInteger &numTwo);
	bool operator <(BigInteger &numTwo);
    bool operator <=(BigInteger &numTwo);
};

#endif
