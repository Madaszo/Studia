class Heap:
    def __init__(self, n):
        self.t = [0 for i in range(n)]
        self.size = 0
    def parent(i): 
        (i-1)//2
    def heapify(self, i):
        p = self.parent(i)
        if p >= 0 and self.t[i] < self.t[p]:
            self.t[i] , self.t[p] = self.t[p] , self.t[i]
            self.heapify(p)
    def insert(self, val):
        if len(self.t) == self.size:
            return 1
        self.t[self.size]  = val
        self.size += 1
        self.heapify(self.size -1)
        return 0


# k tablic n elementowych posortowanych scalić używając heapa

# struktura która pozwala insert na logn i wyciągnąć mediane logn

def partition(t, p, r):
    n = len(t)
    q = t[r]
    i = p-1
    for j in range(p,r):
        if t[j] <=q :
            i+=1
            tmp = t[i]
            t[i] = t[j]
            t[j] = tmp
    t[r] = t[i+1]
    t[i+1] = q
    return i+1

def quick_sort(t, p , r):
    while p < r:
        q = partition(t, p, r)
        if q - p < r- q:
            quick_sort(t, p, q-1)
            p = q + 1
        else:
            quick_sort(t, q, r)
            r = q - 1

def iquick_sort(T):
    l = len(T)
    S = [(-1,-1) for i in range(l)]
    ptr = 0
    S[0] = (0,l-1)
    while ptr >= 0:
        p, r = S[ptr]
        ptr -= 1
        q = partition(T, p, r)
        if p < q -1:
            ptr += 1
            S[ptr] = (p, q-1)
        if q + 1 < r:
            ptr += 1        
            S[ptr] = (q+1 ,r)

def parent(i): (i-1)//2

def heapify(T,i):
    p = parent(i)
    max_ind = i
    if p >= 0 and T[i] < T[p]:
        max_ind = p
    if max_ind != i:
        T[i] , T[p] = T[p] , T[i]
        heapify(T,i)

def insert_to_min_heap(h, val):
    if len(h.t) == h.size: 
        return
    h.t[h.size] = val
    h.size += 1
    heapify(h.t, h.size -1)    
