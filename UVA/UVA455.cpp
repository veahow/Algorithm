#include <cstdio>
#include <cstring>

const int MAXN = 80 + 5;
int N;
char str[MAXN];

int main()
{
    scanf("%d",&N);
    getchar();
    while(N--){
        scanf("%s",str);
        int len = strlen(str);

        for(int i = 1,j; i <= len; ++i){
            if(len % i == 0){
                for(j = i; j < len; ++j)
                    if(str[j] != str[j%i]) break;
                if(j == len){
                    printf("%d\n",i);
                    break;
                }
            }
        }
        if(N) printf("\n");
    }
    return 0;
}
