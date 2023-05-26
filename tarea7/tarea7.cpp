/*
Ana Gabriela Arguello Cedeno
tarea 7

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <vector>
using namespace std;
/*
punto 1 

La complejidad de este algoritmo es O(n), donde n es el tamaño de la pila, esta complejidad es asi
ya que se usa un ciclo que coloca los elementos que no se deben borrar en un auxiliar, tambien se hace,
otro ciclo(por fuera del principal), en el que se pasan los datos que estan es aux, a la pila original,
este for en su peor caso es n-1,en donde solo se pide borrar un elemento pero este esta en la ultima posicion.
*/
void eliminarPosicionesPila(stack<int>pil,deque<int>l){
    stack<int>aux;
    int i=0,j=0,tam=pil.size(),tam2=l.size();
    while((i<tam)&&(j<tam2)){
        if(l[j]==i){
            pil.pop();
            j++;
        }else{
            aux.push(pil.top());
            pil.pop();
        }
        i++;
    }
    tam=aux.size();
    for(i=0;i<tam;i++){
        pil.push(aux.top());
        aux.pop();
    }
}


/*
punto 6

La complejidad de este algoritmo es O(n^2), donde n es el tam de la cola.
Esta complejidad es asi, por el motivo de que en su pero caso,(no hay numeros repetidos) lo que hace que el ciclo
principal se ejecute n veces ya que busca en cada posicion si hay algun numero repetido y el que se encuentra dentro,
se ejecute n*n veces, lo que hace que la complejidad pase de ser lineal a ser cuadratica.
*/
int verificarRepetidos(queue<int>col){
    int i=0,j,tam,a=0,ans=0;
    bool flag;
    deque<int>repeti;
    queue<int>aux;
    aux=col;
    for(i=0;i<col.size();i++){
        repeti.push_back(aux.front());
        aux.pop();
    }
    tam= col.size();
    while(a<tam){
        j=a+1;
        flag=true;
        while((flag==true)&&(j<repeti.size())){
            if(col.front()==repeti[j]){
                ans++;
                flag=true;
            }
            j++;
        }
        col.pop();
        a++;
    }
    return ans;
}



/*
punto 7

La complejidad de este algoritmo es O(nlogn) donde n es el tamaño de la cadena, esta complejidad es asi
puesto que al ser un for,este se ejecutara segun el tamaño de cad, haciendo que su complejidad sea lineal
es decir O(n), pero dentro del for esta la funcion find, la cual tiene una complejidad O(logn),causando que la
complejidad pasa de se O(n) a O(nlogn)
*/

map<char,deque<int>>obtenerPosicionesOcurrencias(string& cad){
    int i;
    char cara;
    map<char,deque<int>> mapi;
    for(i=0;i<cad.length();i++){
        cara=cad[i];
        if(mapi.find(cara)==mapi.end()){
            mapi.insert(pair<char,deque<int>>(cara,deque<int>()));
            mapi[cara].push_back(i);
        }else{
            mapi[cara].push_back(i);
        }
    }
    return mapi;
}

/*
punto 8

La complejidad que tiene este algoritmo es O(n^2),donde n es el tamaño de la matriz 
La complejidad es esa ya que dentro del algoritmo hay un ciclo que se ejecuta n veces, sin embargo,
dentro del mismo, se encuentra otro for y este se ejecutará n*n veces ocasionando que la complejidad pase de
lineal a cuadrática; aunque en ese for de adentro se use la operación push_back, al ser un deque su complejidad 
será constante O(1), lo que hace que la complejidad antes dicha no sufra ningún cambio.

*/
vector<deque<pair<int, int>>> crearMatrizDispersa(vector<vector<int>>&mat){
    int i, j,a,cnt=0;
    vector<deque<pair<int, int>>> dis;
    for(i=0;i<mat.size();i++){
        dis.push_back(deque<pair<int,int>>());
    }
    for(a=0;a<mat.size();a++){
        for(j=0;j<mat[a].size();j++){
            if(mat[a][j]!=0){
                dis[a].push_back(pair<int,int>(mat[a][j],j));
            }
        }
    }
    return dis;
}

/*
punto 8-b

La complejidad de este algoritomo es O(n^2) donde n es el tamaño de la matriz
en este algoritmo el primer for se ejecutara nlogn veces por el motivo de que la complejidad de la funcion find es O(logn)
 y esta al encontrare dentro de un ciclo que se ejecuta n veces, la complejidad final de esta parte del algoritmo sera de O(nlogn);
por otro lado, el segundo for se ejecutara n*m veces donde n como se menciono anterirmente es el tamaño de la matriz, y m es el tamaño
del vector de la fila correspondiente de la matriz(no siempre sera cuadrada); En el caso medio, m sera igual que n, causando que su 
complejidad sea cuadratica O(n^2)
Ya que en esta definicion hay dos tipos de complejidad se selecciona la mayor que en este caso es O(n^2)

*/
map<int,deque<pair<int, int>>> crearMatrizDispersaAlter(vector<vector<int>>&mat){
    int i, j,a,cnt=0;
    map<int,deque<pair<int, int>>> disMap;
    for(i=0;i<mat.size();i++){
        if(disMap.find(i)==disMap.end()){
            disMap.insert(pair<int,deque<pair<int,int>>>(i,deque<pair<int,int>>()));
        }
    }
    for(a=0;a<mat.size();a++){
        for(j=0;j<mat[a].size();j++){
            if(mat[a][j]!=0){
                disMap[a].push_back(pair<int,int>(mat[a][j],j));
            }
        }
    }
    map<int,deque<pair<int, int>>>::iterator it;
    for(it=disMap.begin();it!=disMap.end();it++){
        if(it->second.size()==0){
            disMap.erase(it);
        }
    }
    return disMap;
}

/*
punto 9

La complejidad de este algoritmo es O(n^2), donde n es el tamaño de la cola.
Esta complejidad es esa ya que en el peor caso, no hay elementos repetidos lo que ocaciona que el ciclo
principal se ejecute n veces y el que se encuentra dentro, se ejecute n*n veces, lo que hace que la complejidad
se convierta en cuadratica;

*/
bool verificarRepetidosCola(queue<int>& col){
    bool ans= false;
    int i=0,j,tam,a=0;
    deque<int>repeti;
    queue<int>aux;
    aux=col;
    for(i=0;i<col.size();i++){
        repeti.push_back(aux.front());
        aux.pop();
    }
    tam= col.size();
    while((ans==false)&&(a<tam)){
        j=a+1;
        while((ans==false)&&(j<repeti.size())){
            if(col.front()==repeti[j]){
                ans=true;
            }
            j++;
        }
        col.pop();
        a++;
    }
    return ans;
}


/*
punto 10

la complejidad de este algoritmo es O(n), donde n es el tamaño de la cola
en el peor caso no hay ningún número par, causando que el ciclo se tenga que ejecutar n veces
donde, como se dijo anteriormente, n es el tamaño de la cola.
Aunque se usan diferentes funciones como la función front,pop y push, estas no generan ningún cambio en la
complejidad puesto que al ser colas de STL su complejidad es constante, es decir O(1).Al igual que al hacer
uso de la funcion push de la stack, al ser una pila en STL, la complejidad de dicha funcion sera O(1);

*/

stack<int> filtrarNParesCola(int& n, queue<int>& col){
    int i=0,front,par,tam;
    stack<int>ans;
    tam= col.size();
    while((ans.size()<n)&&(i<tam)){
        front=col.front();
        par=front%2;
        if(par==0){
            ans.push(front);
            col.pop();
        }else{
            col.pop();
        }
        i++;
    }
    return ans;
}


//int main(){
//    int n;
//    vector<vector<int>> mat;
//    mat={{1, 2, 3, 0},{0, 0, 0, 7},{ 0, 0, 0, 3},{0, 0, 0, 0}};
//    deque<int> l;
//    queue<int> col;
//    stack<int> res,pil;
//    //l.push_back(0);
//     l.push_back(2);
//    // l.push_back(4);
//    pil.push(2); 
//    pil.push(5); 
//    pil.push(9); 
//    pil.push(3); 
//    pil.push(1); 
//    string cad= "ana-banana";
//    col.push(1);
//    col.push(5);
//    col.push(1);
//    col.push(5);
//    col.push(2);
//    col.push(9);
//    n=3;
//    eliminarPosicionesPila(pil,l);
//    verificarRepetidos(col);
//    obtenerPosicionesOcurrencias(cad);
//    crearMatrizDispersa(mat);
//    crearMatrizDispersaAlter(mat);
//    verificarRepetidosCola(col);
//    res=filtrarNParesCola(n,col);
//    
//    return 0;
//}
