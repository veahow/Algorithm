#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n;
int ans;
int num[MAXN];
int dp[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%d",&num[i]);
    for(int i = 0; i < MAXN; ++i)
        dp[i] = 1;

    ans = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j)
            if(num[i] > num[j]) dp[i] = max(dp[i],dp[j]+1);
        ans = max(ans,dp[i]);
    }

    printf("%d\n",ans);
    return 0;
}
