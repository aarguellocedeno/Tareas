"""
Ana Gabriela Argüello Cedeño
Tarea 1
"""
#1
def verificarDiagonales(mat):
    ans = False
    cnt = 0
    posi = 0
    for i in range(len(mat)):
        posi += cnt
        posiInv = len(mat[i])-1-cnt
        if mat[i][posi] == mat[i][posiInv] :
            cnt += 1
        posi = 0
    if cnt == len(mat):
        ans = True
    return ans
        
#print(verificarDiagonales(mat = [[11, 23, 76, 34, 11],[14, 30, 92, 30, 101],[12, 45, 58, 92, 22],[74, 56, 49, 56, 100],[99, 5, 28, 47, 99]]))

#2
def esCapicua(lista):
    ans = False
    flag = True
    for i in range(len(lista)):
        if lista[i]== lista[-1-i] and flag:
            ans = True
        else:
            ans = False
            flag = False
    return ans

#print(esCapicua([42, 12, 90, 12, 42]))


#3
# A

def diferenciaListas(listaA,listaB):
    ans = []
    for i in range(len(listaA)):
        if listaA[i] not in listaB:
            ans.append(listaA[i])
        elif listaA[i] in listaB:
            listaB.remove(listaA[i])

    return ans

listaA = [40, 10, 22, 12, 33, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33, 19]
#print(diferenciaListas(listaB, listaA))


# B
def leerImprimir():
    listaA = []
    listaB = []
    cantEje = int(input())
    guard = []
    for i in range(cantEje):
        for r in range(2):
            datos = input().split()
            cantDatos = int(datos[0])
            for j in range(1,cantDatos+1):
                lis = int(datos[j])
                if r == 0:
                    listaA.append(lis)
                
                else:
                    listaB.append(lis)
        t = diferenciaListas(listaA,listaB)
        listaA = []
        listaB = []
        for b in range(len(t)):
            if b < len(t)-1:
                print(t[b], end=", ")
            else:
                print(t[b], end="\n")
#leerImprimir()



#4

def sonPrimos(N):
    ans  = True
    flag = True
    i = 2
    while i < N and flag:
            if (N%i) == 0:
               ans = False
               flag = False
            i += 1
    return ans

def mostrarPrimos():
    listaNum = []
    flag = True
    listaSumas = []
    ans = []
    sumaPrimos = 0
    N = int(input())
    for i in range(2,N+1):
        d = sonPrimos(i)
        if d == True:
            listaNum.append(i)
    print("Números primos entre 1 y %d:"%N)
    for n in range(len(listaNum)):
        if n < len(listaNum)-1:
            print("--> %d,"% listaNum[n])
        else:
            print("--> %d" % listaNum[n])
    print("\nNúmeros entre 1 y %d con suma de dígitos con valor primo:"%N)
    
    for m in range(len(listaNum)):
        st = str(listaNum[m])
        for su in range(len(st)):
            a = st[su]
            listaSumas.append(st[su])
        for lis in range(len(listaSumas)):
            entero = int(listaSumas[lis])
            sumaPrimos += entero
            com = sonPrimos(sumaPrimos)
        if com == True:
            ans.append(listaNum[m])
        listaSumas = []
        sumaPrimos = 0
    for fin in range(len(ans)):
        if fin < len(ans)-1:
            print(ans[fin],end= ", ")
        elif fin == len(ans)-1:
            print(ans[fin])

#mostrarPrimos()



#5

def sumarValoresMatriz(mat,par):
    cnt = 0
    for i in range(len(par)):
        for key in mat:
            for j in range(len(mat[key])):
                if par[i][0] == key and par[i][1] == mat[key][j][0] :
                    cnt += mat[key][j][1]
    return cnt

disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}

#print(sumarValoresMatriz(disp, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)]))

































