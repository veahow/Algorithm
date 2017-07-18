#include <cstdio>
#include <cstring>

const int MAXN = 105;
int R,C;
int hgt[MAXN][MAXN];
int dp[MAXN][MAXN];

int dfs(int row, int col)
{
    if(dp[row][col] != 0) return dp[row][col];
    int maxx = 1;

    if(row + 1 < R && hgt[row][col] > hgt[row+1][col]){
        int num = dfs(row+1,col) + 1;
        if(num > maxx) maxx = num;
    }
    if(row - 1 >= 0 && hgt[row][col] > hgt[row-1][col]){
        int num = dfs(row-1,col) + 1;
        if(num > maxx) maxx = num;
    }
    if(col + 1 < C && hgt[row][col] > hgt[row][col+1]){
        int num = dfs(row,col+1) + 1;
        if(num > maxx) maxx = num;
    }
    if(col - 1 >= 0 && hgt[row][col] > hgt[row][col-1]){
        int num = dfs(row,col-1) + 1;
        if(num > maxx) maxx = num;
    }
    return hgt[row][col] = maxx;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&C);
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                scanf("%d",&hgt[i][j]);
        int ans = 0;
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j){
                dp[i][j] = dfs(i,j);
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        printf("%d\n",ans);
    }

    return 0;
}
