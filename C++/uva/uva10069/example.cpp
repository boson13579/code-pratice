#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int MAXN = 10010;
const int BASE = 1000000000;

struct bignum {
    int len;
    int data[30];

    bignum() : len(0) { }

    bignum(const bignum &v) : len(v.len) {
        memcpy(data, v.data, len * sizeof(int));
    }
    bignum(int v) : len(0) {
        while (v > 0)
            data[len++] = v % BASE, v /= BASE;
    }
    bignum &operator = (const bignum &v) {
        len = v.len;
        memcpy(data, v.data, len * sizeof(int));
        return *this;
    }
    int &operator [] (int i) {
        return data[i];
    }
    int operator [] (int i) const {
        return data[i];
    }
};

bignum operator + (const bignum &a, const bignum &b)
{
    bignum r;
    int i, carry = 0;
    for (i = 0; i < a.len || i < b.len || 0 < carry; ++i)
    {
        if (i < a.len)
            carry += a[i];
        if (i < b.len)
            carry += b[i];
        r[i] = carry % BASE;
        carry /= BASE;
    }
    r.len = i;
    return r;
}

bignum dp[MAXN][105];
char src[MAXN], dst[MAXN];

int main()
{
    freopen("test.in", "r", stdin);
	freopen("test.out","w", stdout);
    int cases;
    scanf("%d%*c", &cases);
    while (cases--)
    {
        gets(src + 1);
        gets(dst + 1);

        int ls, ld;
        ls = strlen(src + 1);
        ld = strlen(dst + 1);

        int c = 0;
        for (int i = 1; i <= ls; ++i)
            if (src[i] == dst[1])
                dp[i][1] = bignum(++c);
            else 
                dp[i][1] = bignum(c);

        for (int i = 2; i <= ls; ++i)
        {
            for (int j = 2; j <= ld; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if (src[i] == dst[j])
                   dp[i][j] = dp[i][j] + dp[i-1][j-1];
            }
        }

        for (int i = dp[ls][ld].len - 1; i >= 0; --i)
            if(dp[ls][ld][i] == 0)
                std::cout<<"000000000";
            else
                printf("%d", dp[ls][ld][i]);
        printf("\n");
        /*
        for(int i=0 ; i<=ls ; i++){
            for(int t=0 ; t<=ld ; t++){
                std::cout<<dp[i][t].data[0]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<src[1]<<"\n";
        std::cout<<dst[1]<<"\n";
        */
    }
    return 0;
}