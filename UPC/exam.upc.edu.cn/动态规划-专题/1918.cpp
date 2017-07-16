#include <cstdio>
#include <cstring>
#include <climits>

const int MAXN = 2000 + 5;
char A[MAXN],B[MAXN];
int K,f[MAXN][MAXN];

int dist(char a,char b)
{
    if(a-b >= 0) return a-b;
    else return b-a;
}

int main()
{
    gets(A);
    gets(B);
    scanf("%d",&K);
    int lenA = strlen(A),lenB = strlen(B);
    for(int i = lenA; i >= 1; --i)
        A[i] = A[i-1];
    for(int i = lenB; i >= 1; --i)
        B[i] = B[i-1];
    A[0] = ' ';
    B[0] = ' ';

    for(int i = 0; i <= lenA; ++i)
        for(int j = 0; j <= lenB; ++j){
            if(i+j){
                f[i][j] = INT_MAX;

                if(i && f[i][j] > f[i-1][j]+K) f[i][j] = f[i-1][j] + K;
                if(j && f[i][j] > f[i][j-1]+K) f[i][j] = f[i][j-1] + K;
                if((i*j) && f[i][j] > f[i-1][j-1]+dist(A[i],B[j])) f[i][j] = f[i-1][j-1] + dist(A[i],B[j]);
            }
        }
    printf("%d\n",f[lenA][lenB]);
    return 0;
}
