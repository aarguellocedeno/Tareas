

#1

def fibo (n):
    listaAns = []
    suma = 0
    for i in range(0,n+1):
        if i == 0:
            listaAns.append(0)
        elif i == 1:
            listaAns.append(1)
        else:
            suma = listaAns[len(listaAns)-1] + listaAns[len(listaAns)-2]
            listaAns.append(suma)
    ans = suma
    return ans
#print(fibo(6))





#2
def fibo2 (n):
    listaAns = []
    suma = 0
    for i in range(0,n+1):
        if i == 0:
            listaAns.append(0)
        elif i == 1:
            listaAns.append(1)
        else:
            suma = listaAns[1]+ listaAns[0]
            print("suma  =  %d"%suma)
            listaAns[0]= listaAns[1]
            
            listaAns[1] = suma
            print("li0  =  %d"%listaAns[1])

    return suma
#print(fibo2(6))










        
