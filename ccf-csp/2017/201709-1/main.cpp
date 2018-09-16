#include <cstdio>

using namespace std;

int main()
{
    int N, ans;
    int a, b, c;
    scanf("%d", &N);

    a = N / 50;
    b = (N - a*50) / 30;
    c = (N - a*50 - b*30) / 10;
    ans = a*7+b*4+c;

    printf("%d\n", ans);

    return 0;
}
