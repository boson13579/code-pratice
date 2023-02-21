#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
#define MAXN (2007)
#define MAXM (4014)
struct qwq
{
    int nex, to, w;
}e[MAXM];
int h[MAXN], tot = 0;
inline void add(int x, int y, int z)
{
    e[++tot].to = y;
    e[tot].w = z;
    e[tot].nex = h[x];
    h[x] = tot;
}
long long dis[MAXN];
int coun[MAXN];
bool vis[MAXN];
#include <queue>
#define inf (long long)((long long)(1e16)+233)
queue<int> q;
inline void INIT() { for (int i = 1;i <= n;i++) dis[i] = inf; }
inline long long spfa()//关于SPFA，_____________
{
    INIT();
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    int x;
    while (!q.empty())
    {
        x = q.front();
        vis[x] = false;
        q.pop();
        for (int i = h[x], y;i;i = e[i].nex)
        {
            y = e[i].to;

            //			printf("x:%d dis:%lld  y:%d\n",x,dis[x],y);
            if (dis[y] > dis[x] + e[i].w)
            {
                dis[y] = dis[x] + e[i].w;
                if (!vis[y])
                {
                    coun[y] = coun[x] + 1;
                    if (coun[y] >= n) return (inf << 1);
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }
    return dis[n];
}
inline long long BF()
{
    INIT();
    dis[1] = 0;
    for (int k = 1;k < n;k++)
        for (int x = 1;x <= n;x++)
            for (int i = h[x], y;i;i = e[i].nex)
            {
                y = e[i].to;

                if (dis[y] > dis[x] + e[i].w) dis[y] = dis[x] + e[i].w;
            }
    long long ans = dis[n];
    for (int k = 1;k < n;k++)
        for (int x = 1;x <= n;x++)
            for (int i = h[x], y;i;i = e[i].nex)
            {
                y = e[i].to;
                if (dis[y] > dis[x] + e[i].w) dis[y] = dis[x] + e[i].w;
            }
    if (ans != dis[n]) return inf << 1;
    else return ans;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z;i <= m;i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, -z);
    }
    long long ans = BF();
    if (ans == inf << 1) puts("inf");
    else printf("%lld\n", -ans);
    return 0;
}