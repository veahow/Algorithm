#include <cstdio>

int n,x;
int num,r;
int count;

int main()
{
    scanf("%d%d",&n,&x);
    for(int i = 1; i <= n; ++i){
        num = i;
        while(num > 0){
            r = num % 10;
            if(r == x) count++;
            num = num / 10;
        }
    }
    printf("%d\n",count);
    return 0;
}
