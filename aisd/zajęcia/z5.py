# A - tablica liczb naturalnych
# T - Liczba naturalna
# czy A ma podzbiór którego suma to T


import sunau


def sort(A):
    pass

def podzbior_sum(A,T):
    sort(A)
    i,j = 0,0
    sum = 0
    while(sum != T and i < len(A) and j < len(A)):
        while(sum<T):
            sum+=A[j]
            j+=1
        while(sum>T):
            sum-=A[i]
            i+=1

def subsetSum(A,T):
    for a in A:
        if a == T:
            return True
    for i in range(len(A)):
        if A[i] == 0:
            continue
        tmp = A[i]
        A[i] = 0
        if(subsetSum(A,T-tmp)):
            return True
        
        

# A - Tablica liczb
# B - Tablica liczb
# najdłuższy podciąg A i B

def podciong(A,B):
    maxlen = 0
    for i in range(len(A)):
        for j in range(i+1,len(A)):
            k = 0
            while(k < len(B)):
                pass


# najdłuższy podciąg rosnący N logN
def lis(A):
    B = [0]
    nmax = 0
    for a in A:
        if nmax == 0:
            B[0] = a
            nmax = 1
            continue
        for i in range(nmax-1,-1,-1):
            if B[i]<a and i == nmax-1:
                B.append(a)
                nmax+=1
                break
            if B[i]<a and B[i+1]>a:
                B[i+1] = a
            if i == 0 and B[i]>a:
                B[i] = a
    return nmax

def binsearch(f,l,r,v):
    while l<r:
        mid = (l+r) // 2
        if f[mid] < v:
            l = mid + 1
        else:
            r = mid
    return l



# mnożenie ciągu macierzy tak by było jak najmniej operacji

def mcm(A):
    pass



# wydawanie monet

def wydawanie(A,T,B):
    for a in A:
        if a == T:
            return 1
    if B[T]>0:
        return B[T]
    min = -1
    for a in A:
        if T-a>=0:
            tmp = wydawanie(A,T-a,B) + 1
            if tmp < min or min<0:
                min = tmp 
    B[T] = min
    return B[T]

def coins(N,T):
    B = [0 for i in range(T+1)]
    return wydawanie(N,T,B)

A = [7, 3, 15, 1, 4, 5, 16, 1, 8]
print(lis(A))
N = [1,5,8]
T = 15
print(coins(N,T))