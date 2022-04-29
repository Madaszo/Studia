# wycinka lasu drzewa mają różne wysokości chcemy jak największą sumę wysokości a nie możemy 2 kołosiebie

from cmath import inf


def las(T,n):
    if n < 0:
        return 0 
    return max(las(T,n-2)+T[n],las(T,n-1))


def las_iteracyjnie(T):
    pom = [0 for i in range(len(T))]
    for i in range(len(T)):
        if i > 2:
            pom[i] = T[i] + max(pom[i-2],pom[i-3])
        else:
            pom[i] = T[i]
    return max(pom[len(T)-1],pom[len(T)-2])

# spadające klocki żaden klocek nie może wisieć
def krazki(T,i):
    max = 0
    for j in range(i+1,len(T)):
        if zawiera(T[i],T[j]):
            tmp = krazki(T,j)
def zawiera(a,b):
    pass
# ładowanie promu na 2 pasach z samochodami w korku

def prom(T,d):
    for i in range(len(T)):
        if fun(T,i,d,d) is False:
            max = i
            break
    return max

def fun(T,i,L,R):
    if i == 0:
        return True
    else: return fun(T,i-1,L-T[i], R) or fun(T,i-1,L,R-T[i])
# głodna żaba n lilii na każdej lilii jest różna wartość odżywcza 
def zaba(T,i,j):
    if i >= len(T):
        return 0
    min = inf
    j += T[i]
    for k in range(j):
        tmp = 1 + zaba(T,i+k,j-k) 
        if tmp < min:
            min = tmp 
    return min

