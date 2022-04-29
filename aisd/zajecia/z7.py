# jak najmniej razy się zatrzymać do tankowania
# chcemy dojechać jak najtaniej (ale nie najmniej razy)
# tak jak b ale zawsze do pełna

def ciezarowka(T,L):
    p = L
    i = 1
    wynik = []
    wynik.append(0)
    while(p<len(T)):
        while(T[i]<p):
            i+=1
        wynik.append(i-1)
        p += T[i]
    return wynik

def ciezarowkb(T,L):
    p = 0
    i = 0
    while(p<len(T)):
        cost = T[i][0]
        j = i+1
        mincost = T[j][0]
        flag = False
        while(T[j][0]-T[i][0]<L and j < len(T)):
            if T[j][1] < cost:
                flag = True
                break
            if T[j][0]<mincost:
                mincost = T[j][0]
                minj = j
        if flag is False:
            j = minj
        p = T[j][0]-T[i][0]
        i = j

def ciezarowkc(T,L):
    p = L
    



# przykrywamy punkty płytkami o długości 1

def plytki(T):
    last_plytka = 0
    wynik = 0
    for i in range(len(T)):
        if T[i] > last_plytka:
            last_plytka = T[i]+1
            wynik+=1
    return wynik

# T = {t1,t2,...,tn}
# ti - deadline
# każde zadanie kosztuje 1 jednostkę czasu
# g(ti) - nagroda
# maksymalizacja nagród 

def zadania(T,G):
    T.sort()
    wynik = [] 
    


# ładowanie przyczepy
# L ladownosc
# k - ladunek o wagach l1 , l2 , ... ln
# li = 2*j
# zaladowac jak najwiecej do przyczepy

def przyczepa(L,K):
    K.sort()
    wynik = []
    for i in range(len(K),-1,-1):
        if K[i]<L:
            L-=K[i]
            wynik.append(K[i])
    return wynik

# A = {a1,a2,...,an} -całkowite
# znaleźć takie x : suma|ai-x| - minimalna

def odleglosc(A):
    d = A//2
    if A%2 == 0:
        return (A[d]+A[d+1])/2
    return A[d+1]


