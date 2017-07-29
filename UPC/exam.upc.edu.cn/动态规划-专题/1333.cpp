#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50 + 5;
int m,n,map[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];

int Max(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d",&map[i][j]);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= m; ++k)
                for(int l = 1; l <= n; ++l){
                    int maxn = Max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]);
                    if(i == k && j == l) dp[i][j][k][l] = map[i][j] + maxn;
                    else dp[i][j][k][l] = map[i][j] + map[k][l] + maxn;
                }
    printf("%d\n",dp[m][n][m][n]);
    return 0;
}
//四维解法，可优化到三维。更深层次的优化需要运用最小费用最大流解法。