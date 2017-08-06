#include <cstdio>

const int MAXN = 200;
int n,k;
int dp[MAXN][MAXN];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)
        dp[i][1] = 1;
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k && j <= i; ++j)
            dp[i][j] = dp[i-1][j-1] + dp[i-j][j];

    printf("%d\n",dp[n][k]);
}
