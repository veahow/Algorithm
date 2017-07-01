#include <cstdio>

int main()
{
    int K,i,day,ans = 0;
    scanf("%d",&K);
    for(i = 1; i * (i + 1) / 2 < K; ++i)
        ans += i*i;
    day = i * (i + 1) / 2;
    if(day == K) ans += i * i;
    else ans += (i - (day - K)) * i;
    printf("%d\n",ans);
    return 0;
}
