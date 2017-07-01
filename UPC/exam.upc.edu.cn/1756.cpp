#include <cstdio>

const int MAXN = 100 + 5;
int n,m;
char map[MAXN][MAXN];
char new_map[MAXN][MAXN];

void Input()
{
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%c",&map[i][j]);
            if(map[i][j] == '*') new_map[i][j] = '*';
        }
        getchar();
    }
}

void Judge(int row,int col)
{
    int count = 0;
    if(row - 1 >= 1){
        if(map[row-1][col] == '*') count++;
    }
    if(row - 1 >= 1 && col - 1 >= 1){
        if(map[row-1][col-1] == '*') count++;
    }
    if(row - 1 >= 1 && col + 1 <= m){
        if(map[row-1][col+1] == '*') count++;
    }
    if(row + 1 <= n){
        if(map[row+1][col] == '*') count++;
    }
    if(row + 1 <= n && col - 1 >= 1){
        if(map[row+1][col-1] == '*') count++;
    }
    if(row + 1 <= n && col + 1 <= m){
        if(map[row+1][col+1] == '*') count++;
    }
    if(col - 1 >= 1){
        if(map[row][col-1] == '*') count++;
    }
    if(col + 1 <= m){
        if(map[row][col+1] == '*') count++;
    }

    new_map[row][col] = (char)(count + 48);
}

void Print()
{
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            printf("%c",new_map[i][j]);
        printf("\n");
    }
}

int main()
{
    Input();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(map[i][j] == '?') Judge(i,j);
        }
    }
    Print();
    return 0;
}
