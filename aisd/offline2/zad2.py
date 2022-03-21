# Marcel Duda
# tworzę drugą tablicę w której będę trzymał te przedziały które nie zawierają się w innych przedziałach
# przez całą tablicę L przechodzę i dla każdego sprawdzam czy dany L[i] zawiera się w jakimś przedziale 
# w drugiej tablicy jeśli tak to zwiększam poziom danego przedziału a jeśli nie to dokładam L[i] 
# na koniec drugiej tablicy, jeśli L[i] zawiera któryś z przedziałów już obecny w tablicy to 
# zamieniam to miejsce w tablicy na L[i] i przechodzę jeszcze raz po wszystkich dotychczasowych
# przedziałach aż do i by sprawdzić jego poziom

from zad2testy import runtests

def depth(L):
    x = len(L)
    pom = [[0 for i in range(3)] for j in range(x)]
    k = 0
    for i in range(x):
        flaga = 0
        for j in range(k):
            if L[i][0] >= pom[j][0] and L[i][1] <= pom[j][1]:
                pom[j][2] += 1
                flaga = 1
            elif L[i][0] <= pom[j][0] and L[i][1] >= pom[j][1]:
                pom[j][0] = L[i][0] 
                pom[j][1] = L[i][1]
                pom[j][2] = 0
                p = j
                flaga = 2
                break
        if flaga == 2:
            for j in range(i):
                if L[j][0] >= pom[p][0] and L[j][1] <= pom[p][1]:
                    pom[p][2] += 1
        elif flaga == 0:
            pom[k][0] = L[i][0]
            pom[k][1] = L[i][1]
            pom[k][2] = 0
            k += 1
    max = 0
    for i in range(k):
        if pom[i][2] > max:
            max = pom[i][2]
    return max

runtests( depth ) 
