#include <cstdio>

int L,R;
int count;

void Judge(int num)
{
    int n;
    while(num > 0){
        n = num % 10;
        if(n == 2) count++;
        num /= 10;
    }
}

int main()
{
    scanf("%d%d",&L,&R);
    for(int i = L; i <= R; ++i)
        Judge(i);
    printf("%d\n",count);
    return 0;
}
