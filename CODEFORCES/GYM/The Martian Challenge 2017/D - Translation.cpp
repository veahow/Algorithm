#include <cstdio>
#include <cstring>

const int MAXN = 1E5 + 5;
const char map_upper[26 + 5] = "nyUKZXkbvzIdshurMilNSVOtec";
const char map_lower[26 + 5] = "PgEfTYaWGHjDAmxQqFLRpCJBow";
int n;

void Print()
{
    char str[MAXN];
    scanf("%s",str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        if(str[i] >= 'A' && str[i] <= 'Z') printf("%c",map_upper[(int)(str[i] - 'A')]);
        if(str[i] >= 'a' && str[i] <= 'z') printf("%c",map_lower[(int)(str[i] - 'a')]);
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    for(int i = 1; i <= n-1; ++i){
        Print();
        putchar(' ');
    }
    Print();
    putchar('\n');
    return 0;
}
