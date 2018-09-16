#include <cstdio>

int main()
{
    int n, isFirst = 1, i = 2, temp = 0, score = 0;

    for(;;)
    {
        scanf("%d", &n);
        if(n == 0) break;
        if(isFirst){
            if(n == 2) score += 2;
            isFirst = 0;
        }
        if(n == 1){
            score++;
            i = 2;
        }
        if(n == 2 && temp == 1) score += 2;
        if(n == 2 && temp == 2){
            score += 2*i;
            i++;
        }else i = 2;
        temp = n;
    }

    printf("%d\n", score);

    return 0;
}
