#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int N;
char str1[MAXN],str2[MAXN];
int dp[MAXN][MAXN];

int main()
{
    //freopen("data.txt","r",stdin);

    scanf("%d",&N);
    getchar();
    while(N--){
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        memset(dp,0,sizeof(dp));

        scanf("%s",str1);
        int l = strlen(str1);
        for(int i = l - 1,j = 0; i >= 0; --i)
            str2[j++] = str1[i];

        for(int i = 1; i <= l; ++i)
            for(int j = 1; j <= l; ++j)
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

        printf("%d\n",l-dp[l][l]);
    }
    return 0;
}
