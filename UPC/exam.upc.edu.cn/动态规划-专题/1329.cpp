#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 105;
int N;
int num[MAXN][MAXN];
int ans[MAXN][MAXN];

int maxsum(int x,int y);

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j <= i; ++j)
            scanf("%d",&num[i][j]);

    printf("%d\n",maxsum(0,0));

    return 0;
}

int maxsum(int x,int y)
{
    if(x == N - 1) return num[x][y];
    if(ans[x+1][y] == 0) ans[x+1][y] = maxsum(x+1,y);
    if(ans[x+1][y+1] == 0) ans[x+1][y+1] = maxsum(x+1,y+1);
    return num[x][y]+max(ans[x+1][y],ans[x+1][y+1]);
}
