
from zad4testy import runtests


def select_buildingsn(T,p):
    pom = [T[i][3] for i in range(len(T))]
    


def select_buildings(T,p):
    mina = T[0][1]
    maxb = T[0][2]

    for b in T:
        if b[1]<mina:
            mina = b[1]
        if b[2]>maxb:
            maxb = b[2]

    miejsce = [0 for i in range(maxb-mina+1)]
    wynik = []
    ind = [0 for i in range(len(T))]
    tmp = []
    max = 0
    for i in range(len(T)):
        if ind[i]==0 and T[i][3] < p:
            flag = True
            for j in range(T[i][1]-mina,T[i][2]-mina+1):
                if miejsce[j] != 0:
                    flag = False
                    break
            if flag is True:
                for j in range(T[i][1]-mina,T[i][2]-mina+1):
                    miejsce[j] = 1
                ind[i] = 1
                tmp = []
                tmp.extend(sb(T,p-T[i][3],miejsce,ind,mina,i))
                sum = 0
                tmp.append(i)
                for k in range(len(tmp)):
                    sum+=T[tmp[k]][0]*(T[tmp[k]][2]-T[tmp[k]][1])
                if sum > max:
                    tmp2 = tmp
                    max = sum
                for j in range(T[i][1]-mina,T[i][2]-mina+1):
                    miejsce[j] = 0
                ind[i] = 0
    wynik = tmp2
    return wynik

def sb(T,p,miejsce,ind,mina,l):
    
    wynik = []
    if p < 0:
        return wynik
    max = 0
    tmp = []
    for i in range(l,len(T)):
        if ind[i]==0 and T[i][3] < p:
            flag = True
            for j in range(T[i][1]-mina,T[i][2]-mina+1):
                if miejsce[j] != 0:
                    flag = False
                    break
            if flag is True:
                for j in range(T[i][1]-mina,T[i][2]-mina+1):
                    miejsce[j] = 1
                ind[i] = 1
                tmp = []
                tmp.append(i)
                tmp.extend(sb(T,p-T[i][3],miejsce,ind,mina,i))
                sum = 0
                for k in range(len(tmp)):
                    sum+=T[tmp[k]][0]*(T[tmp[k]][2]-T[tmp[k]][1])
                if sum > max:
                    wynik = tmp
                    max = sum
                for j in range(T[i][1]-mina,T[i][2]-mina+1):
                    miejsce[j] = 0
                ind[i] = 0
    return wynik
    
                
def select_buildings_zachlannie(T,p):
    pom = [ -1.0 for _ in range(len(T))]
    for i in range(len(T)):
        pom[i] = T[i][0]*(T[i][2]-T[i][1])/T[i][3]
    ind = [i for i in range(len(pom))]
    #print(pom,ind)
    mina = T[0][1]
    maxb = T[0][2]
    for b in T:
        if b[1]<mina:
            mina = b[1]
        if b[2]>maxb:
            maxb = b[2]
    for i in range(len(pom)):
        for j in range(len(pom)-i-1):
            if pom[j] < pom[j+1]:
                pom[j],pom[j+1],ind[j],ind[j+1] = pom[j+1],pom[j],ind[j+1],ind[j]
    #print(pom,ind)
    wynik = []
    miejsce = [0 for i in range(maxb-mina+1)]
    for i in range(len(pom)):
        if T[ind[i]][3] < p:
            flag = True
            for j in range(T[ind[i]][1]-mina,T[ind[i]][2]-mina+1):
                if miejsce[j] != 0:
                    flag = False
                    break 
            if flag is True:
                p-=T[ind[i]][3]
                for j in range(T[ind[i]][1]-mina,T[ind[i]][2]-mina+1):
                    miejsce[j] = 1
                wynik.append(ind[i])
    return wynik

runtests( select_buildings )