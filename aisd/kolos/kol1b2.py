def czy_anagram(pom1,s2):
    suma = 0
    for x in pom1:
        suma+=x
    if(x!=len(s2)):
        return False
    pom2 = [0 for i in range(26)]
    for i in range(suma):
        pom2[s2[i]-97]+=1
    for i in len(pom1):
        if pom1[i]!=pom2[i]:
            return False
    return True