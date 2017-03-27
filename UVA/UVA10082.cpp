#include <cstdio>

char words[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    char ch;
    int i;
    while((ch = getchar()) != EOF){
        for(i = 1; words[i] && words[i] != ch; ++i);
        if(words[i]) putchar(words[i-1]);
        else putchar(ch);
    }
    return 0;
}
