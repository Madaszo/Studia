# Duda Marcel
# wrzucamy do kolejki priorytetowej tyle pól do których możemy dojechać po czym ściągamy od najwyższego aż będziemy mogli dojechać do końca
class Kopiec:
    def __init__(self,n):
        self.t = [(0,0) for i in range(n)]
        self.size = 0
    def parent(self,i):
        return (i-1)//2
    def left(self,i):
        return 2*i +1
    def right(self,i):
        return 2*i+2
    def heapify(self,i):
        p = self.parent(i)
        if p >= 0 and self.t[i][0] > self.t[p][0]:
            tmp = self.t[i]
            self.t[i] = self.t[p]
            self.t[p] = tmp
            self.heapify(p)
    def insert(self, tmp):
        if len(self.t) <= self.size:
            self.t.append(tmp)
            self.size += 1
            self.heapify(len(self.t)-1)
        self.t[self.size] = tmp
        self.size += 1
        self.heapify(self.size -1)
    def get(self):
        tmp = self.t[0]
        self.t[0] = self.t[self.size-1]
        self.size -= 1
        self.heapifyg(0)
        return tmp
    def heapifyg(self,i):
        l = self.left(i)
        r = self.right(i)
        max_ind = i
        if(l < self.size and self.t[l][0] > self.t[max_ind][0]):
            max_ind = l
        if(r < self.size and self.t[r][0] > self.t[max_ind][0]):
            max_ind = r
        if max_ind != i:
            tmp = self.t[i]
            self.t[i] = self.t[max_ind]
            self.t[max_ind] = tmp
            self.heapifyg(max_ind)
        


import queue
from zad5testy import runtests


def plan(T):
    p = T[0]
    kopiec = Kopiec(len(T)+1)
    i = 1
    wynik = []
    wynik.append(0)
    while p < len(T)-1:
        for j in range(i,p+1):
            if T[j] != 0:
                tmp = (T[j],j)
                kopiec.insert(tmp)
            i+=1 
        tmp=kopiec.get()
        p+=tmp[0]
        wynik.append(tmp[1])
    wynik.sort()
    return wynik

# zmien all_tests na True zeby uruchomic wszystkie testy
runtests( plan, all_tests = True )