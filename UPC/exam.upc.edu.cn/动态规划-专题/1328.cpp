#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int n;
int l;
int dp[MAXN];
int ans;

int main()
{
    //freopen("data.txt","r",stdin);

    scanf("%d",&n);
    while(n--){
        char str[MAXN];
        ans = 1;
        scanf("%s",str);
        l = strlen(str);

        for(int i = 0; i < MAXN; ++i)
            dp[i] = 1;

        for(int i = 1; i < l; ++i){
            for(int j = 0;j < i; ++j)
                if(str[i] > str[j]) dp[i] = max(dp[i],dp[j]+1);
            ans = max(ans,dp[i]);
        }

        printf("%d\n",ans);
    }

    return 0;
}
