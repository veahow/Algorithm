#include <cstdio>
#include <cstring>

int T,N,count[10];

int main()
{
    scanf("%d",&T);
    while(T--){
        memset(count,0,sizeof(count));
        scanf("%d",&N);
        while(N > 0){
            int n = N--,dgt;
            while(n > 0){
                dgt = n % 10;
                count[dgt]++;
                n = n / 10;
            }
        }
        for(int i = 0; i < 10; ++i)
            if(i != 9) printf("%d ",count[i]);
            else printf("%d\n",count[i]);
    }
    return 0;
}