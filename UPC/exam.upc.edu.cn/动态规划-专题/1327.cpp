#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int a;
    int b;
}Node;

const int MAXN = 1005;
int N;
int n;
Node rec[MAXN];
int dp[MAXN];
int ans;

bool cmp(Node x,Node y)
{
    if(x.a == y.a) return x.b < y.b;
    else return x.a < y.a;
}

int main()
{
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            scanf("%d%d",&rec[i].a,&rec[i].b);
            if(rec[i].a > rec[i].b) swap(rec[i].a,rec[i].b);
        }
        sort(rec,rec+n,cmp);
        ans = 1;
        for(int i = 0; i < n; ++i)
            dp[i] = 1;

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j)
                if(rec[i].a > rec[j].a && rec[i].b > rec[j].b) dp[i] = max(dp[i],dp[j]+1);
            ans = max(ans,dp[i]);
        }

        printf("%d\n",ans);
    }
    return 0;
}
