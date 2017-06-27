#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 20 + 5;
const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

char Reverse(char ch)
{
    if(isalpha(ch)) return rev[ch - 'A'];
    else return rev[ch - '0' + 25];
}

int main()
{
    char str[MAXN];
    while(scanf("%s",str) != EOF){
        int len = strlen(str);
        int pal = 1,mir = 1;
        for(int i = 0; i < (len+1)/2; ++i){
            if(str[i] != str[len-1-i]) pal = 0;
            if(Reverse(str[i]) != str[len-1-i]) mir = 0;
        }
        printf("%s -- is %s.\n\n",str,msg[mir*2+pal]);
    }
    return 0;
}
