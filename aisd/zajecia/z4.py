# Dane są liczby naturalne ze zbioru [0, 10^9] struktura która w czasie O(1):
# zresetować strukturę
# dodać licz liczbę do struktury
# sprawdzić czy liczba jest w strukturze


# n liczb naturalnych [0 ; n*n -1]
def binsearch(a,B):
    pass

def sort(B):
    pass


def countin_sort(t,n):
    t2 =[[0 for i in range(2)] for i in range(n)]
    for i in range(len(t)):
        t2[i][0] = t[i] // n
        t2[i][1] = t[i] % n
# radix sort dla podstawy n

# mamy tablicę A która zawiera n liczb wartości pochodzą ze zbioru B gdzie |B| = logn
def counting(A,B):
    sort(B)
    C = [0 for i in range(len(B))]
    for a in A:
        C[binsearch(a,B)] += 1
    j = 0
    for i in range(len(A)):
        while(C[j] == 0):
            j += 1
        A[i] = B[j] 
        C[j] -= 1 

# partition dzieli 3 części, mniejsze, równe, i większe od x
def quickersort(A, p = 0, r = 0):
    if p < r:
        np, nr = partition(A,p,r)
        quickersort(A,p,nr)
        quickersort(A,np,r)

def partition(A,p,r):
    x = A[r]
    i = p - 1
    for j in range(p,r):
        if A[j] < x:
            i += 1
             
# szukamy parami różnych liczb takich że y - x jest najewiększe ale między nimi nie ma żadnej innej
# dzielimy na n bucketów i porównujemy max z jednego bucketa i min z drugiego