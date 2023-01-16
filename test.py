
def solve(n):

    def dp(n):

        if(n<3):
            return n

        ans = n

        for i in range(1,n+1):
            
            temp = i**2
            
            if(temp > n):
                break
            else:
                ans = min(ans,1+dp(n-temp))
        
        return ans

    output = dp(n)

    return output

a = [1,1,3]

a.append(-1)

a.sort(reverse=True)

for i in range(0,len(a)):
    if(a[i]<i+1):
        print(i)
        break
