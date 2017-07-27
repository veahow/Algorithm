#include <cstdio>

using namespace std;

int List[1000000];

int MaxSubseqSum(int n)
{
    int ThisSum=0,MaxSum=0;

    for(int i=0;i<n;++i){
        scanf("%d",List+i);
        ThisSum+=List[i];
        if(ThisSum<0) ThisSum=0;
        if(ThisSum>MaxSum) MaxSum=ThisSum;
    }

    return MaxSum;
}

int main()
{
    int N;
    int n;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        printf("%d\n",MaxSubseqSum(n));
    }
    return 0;
}
