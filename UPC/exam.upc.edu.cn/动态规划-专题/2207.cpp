#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10000;
int m,n;
int w[MAXN];
int c[MAXN];
int dp[MAXN];

int main()
{
    scanf("%d%d",&m,&n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d",&w[i],&c[i]);
    memset(dp,0,sizeof(dp));

    for(int i = 0; i < n; ++i)
        for(int j = m; j >= w[i]; --j)
            dp[j] = max(dp[j],dp[j-w[i]]+c[i]);

    printf("%d\n",dp[m]);

    return 0;
}
