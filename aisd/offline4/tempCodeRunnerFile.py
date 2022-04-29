    # for i in range(len(T)):
    #     if ind[i]==0 and T[i][3] < p:
    #         flag = True
    #         for j in range(T[i][1]-mina,T[i][2]-mina+1):
    #             if miejsce[j] != 0:
    #                 flag = False
    #                 break
    #         if flag is True:
    #             for j in range(T[i][1]-mina,T[i][2]-mina+1):
    #                 miejsce[j] = 1
    #             ind[i] = 1
    #             tmp = []
    #             tmp.extend(sb(T,p-T[i][3],miejsce,ind,mina))
    #             sum = 0
    #             tmp.append(T[i])
    #             for k in range(len(tmp)):
    #                 sum+=tmp[k][0]*(tmp[k][2]-tmp[k][1])
    #             if sum > max:
    #                 wynik = tmp
    #                 max = sum
    #             for j in range(T[i][1]-mina,T[i][2]-mina+1):
    #                 miejsce[j] = 0
    #             ind[i] = 0
