#include <cstdio>

int main()
{
    char ch;
    bool flag = true;
    while((ch = getchar()) != EOF){
        if(ch == '"'){
            printf("%s",flag ? "``" : "''");
            flag = !flag;
        }else printf("%c",ch);
    }
    return 0;
}
