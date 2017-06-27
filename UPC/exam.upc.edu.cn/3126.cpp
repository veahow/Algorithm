#include <cstdio>

const int MAXN = 50 + 5;
long long n;
char stack[MAXN];
long long ans;

long long Pow(long long x,long long y)
{
    long long fact = 1;
    for(int i = 1; i <= y; ++i)
        fact *= x;
    return fact;
}

int main()
{
    scanf("%lld",&n);
    scanf("%s",stack);
    for(int i = 0; i < n; ++i)
        if(stack[i] == 'B') ans += Pow(2,i);
    printf("%lld\n",ans);
    return 0;
}
