        if i == 0:
            pom1 = [0 for i in range(26)]
            for j in range(len(T[i])):
                pom1[T[i][j]-97]+=1
            pom.append(pom1)
            licz.append(1)
            continue