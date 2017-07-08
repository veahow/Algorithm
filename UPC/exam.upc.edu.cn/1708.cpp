#include <cstdio>
#include <cstring>

const int MAXN = 1005;
char k[MAXN],c[MAXN],m[MAXN],ch;

int main()
{
    scanf("%s",k);
    scanf("%s",c);
    int lk = strlen(k),lc = strlen(c);
    int num = 0;
    if(lc > lk){
        for(int i = lk; i < lc; ++i)
            k[i] = k[i-lk];
    }

    for(int i = 0; i < lc; ++i){
        if(k[i] >= 'a' && k[i] <= 'z')
            num = (int)(k[i] - 'a');
        else num = (int)(k[i] - 'A');

        if(c[i] >= 'a' && c[i] <= 'z'){
            ch = c[i] - num ;
            if(ch < 'a') ch = ch + 26;
        }
        if(c[i] >= 'A' && c[i] <= 'Z'){
            ch = c[i] - num;
            if(ch < 'A') ch = ch + 26;
        }
        m[i] = ch;
    }

    printf("%s\n",m);

    return 0;
}
