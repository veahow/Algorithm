#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 5;
int N,K,P[MAXN],T[MAXN],f[MAXN];

int main()
{
    scanf("%d%d",&N,&K);
    for(int i = 1; i <= K; ++i)
        scanf("%d%d",P+i,T+i);
    f[N+1] = 0;
    int j = K;
    for(int i = N; i >= 1; --i){
        if(P[j] != i) f[i] = f[i+1] +1;
        while(P[j] == i){
            f[i] = max(f[i],f[i+T[j]]);
            j--;
        }
    }
    printf("%d\n",f[1]);
    return 0;
}
