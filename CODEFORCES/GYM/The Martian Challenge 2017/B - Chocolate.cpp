#include <cstdio>
#include <cstring>

const int MAXN = 10 + 5;
int k,n,m,satn,satm,ans;

int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i = 0; i < k; ++i){
        char str[MAXN];
        scanf("%s",str);
        if(strcmp(str,"Mars") != 0) satm++;
    }
    if(satm < m) ans = ans + m - satm;
    else satm = m;
    satn = k - satm;
    if(satn < n) ans = ans + n - satn;
    printf("%d\n",ans);
    return 0;
}
