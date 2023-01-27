def ffff(n,playlist):
    k = playlist.split(' ')
    for i in range(len(k)):
        k[i] = int(k[i])
    ans = 0
    kk = []
    for i in range(len(k)):
        if (k[i] != k[i-1]) and (i != 0) and (k[i] not in kk):
            ans +=1
            kk.append(k[i])
    return ans 

print(int(ffff(input(),input())))


