#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    int v;
    int p;
}Arr;

const int MAXN = 30000;
int T;
int N,m;
Arr arr[MAXN];
int dp[MAXN];
int ans;

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&m);
        for(int i = 0; i < m; ++i)
            scanf("%d%d",&arr[i].v,&arr[i].p);
        memset(dp,0,sizeof(dp));
        ans = 0;

        for(int i = 0; i < m; ++i)
            for(int j = N; j >= arr[i].v; --j)
                dp[j] = max(dp[j],dp[j-arr[i].v]+arr[i].v*arr[i].p);

        printf("%d\n",dp[N]);
    }

    return 0;
}
