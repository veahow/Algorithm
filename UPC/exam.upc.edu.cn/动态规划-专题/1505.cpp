#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int N,E,arr[2*MAXN],dp[2*MAXN][2*MAXN];

int main()
{
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i){
        scanf("%d",&arr[i]);
        arr[i+N] = arr[i];
    }
    for(int j = 2; j < 2*N; ++j)
        for(int i = j - 1; i >= 1 && j - i < N; --i){
            for(int k = i; k < j; ++k)
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
            E = max(E,dp[i][j]);
        }
    printf("%d\n",E);
    return 0;
}
