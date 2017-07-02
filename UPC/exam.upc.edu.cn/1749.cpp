#include <cstdio>
#include <cstring>

const int MAXN = 50;
int N;
int row,col;
int matrix[MAXN][MAXN];

void InitMagicSquare(int n)
{
    if(row == 1 && col != N){
        row = N;
        col = col + 1;
        matrix[row][col] = n;
        return ;
    }

    if(col == N && row != 1){
        col = 1;
        row = row - 1;
        matrix[row][col] = n;
        return ;
    }
    if(row == 1 && col == N){
        row = row + 1;
        matrix[row][col] = n;
        return ;
    }

    if(row != 1 && col != N){
        if(matrix[row-1][col+1] == -1){
            row = row - 1;
            col = col + 1;
        }else row = row + 1;

        matrix[row][col] = n;
        return ;
    }
}

int main()
{
    memset(matrix,-1,sizeof(matrix));
    scanf("%d",&N);
    row = 1;
    col = (N+1) / 2;
    matrix[row][col] = 1;

    for(int i = 2; i <= N * N; ++i)
        InitMagicSquare(i);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(j != N) printf("%d ",matrix[i][j]);
            else printf("%d\n",matrix[i][j]);
        }

    return 0;
}
