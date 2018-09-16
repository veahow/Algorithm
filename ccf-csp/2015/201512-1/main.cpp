#include <cstdio>

int main()
{
    long long n, a, b, sum = 0;
    scanf("%lld",&n);
    while(n!=0){
        a = n % 10;
        n = n / 10;
        sum += a;
    }
    printf("%lld\n", sum);
    return 0;
}
