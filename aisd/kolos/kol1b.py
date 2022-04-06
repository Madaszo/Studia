# Marcel Duda
# Buduję tablicę w której przechowywać będę zbiór unikalnych anagramów
# przechodzę po zadanej tablicy i sprawdzam czy dany wyraz jest anagramem któregoś już zapisanego w tablicy
# Jeśli nie to dodaję go do tablicy i przechodzę, a jeśli tak to zwiększam licznik odpowiedniego anagramu
# złożoność n^2 czasowa i n pamięciowa
from kol1btesty import runtests

def czy_anagram(s1,s2):         # złożonośc 3n gdzie n-len(s1)
    if(len(s1)!=len(s2)):
        return False
    pom1 = [0 for i in range(26)]
    pom2 = [0 for i in range(26)]
    for i in range(len(s1)):
        pom1[ord(s1[i])-97]+=1
        pom2[ord(s2[i])-97]+=1
    for i in range(len(pom1)):
        if pom1[i]!=pom2[i]:
            return False
    return True

def f(T):
    pom = []
    licz = []
    x = 1
    for i in range(len(T)):
        j = 0
        flag = True
        if i == 0:
            pom.append(T[i])
            licz.append(1)
            continue
        for j in range(len(pom)):
            if czy_anagram(pom[j],T[i]):
                licz[j]+=1
                flag = False
                break
        if flag:
            pom.append(T[i])
            licz.append(1)
    return max(licz)


# Zamien all_tests=False na all_tests=True zeby uruchomic wszystkie testy
runtests( f, all_tests=True)
