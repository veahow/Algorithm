#include <cstdio>

int n;

int main()
{
    int i = 2;
    scanf("%d",&n);
    while(i != n){
        if(n % i == 0){
            printf("%d\n",n/i);
            break;
        }else i++;
    }
    return 0;
}
