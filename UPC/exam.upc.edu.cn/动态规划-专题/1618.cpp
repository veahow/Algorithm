#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
int n;
int arr[MAXN];
int dp1[MAXN],dp2[MAXN];
int ans1,ans2;

int main()
{
    while(scanf("%d",&arr[n]) != EOF) n++;

    for(int i = 0; i < n; ++i){
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j)
            if(arr[i] <= arr[j]) dp1[i] = max(dp1[i],dp1[j]+1);
            else dp2[i] = max(dp2[i],dp2[j]+1);
        ans1 = max(ans1,dp1[i]);
        ans2 = max(ans2,dp2[i]);
    }

    printf("%d\n%d\n",ans1,ans2);
    return 0;
}
