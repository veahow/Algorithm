#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXM = 60 + 5,MAXN = 32000 + 5;
int m,n;
int f[MAXM][MAXN];
int val[MAXM][3],wth[MAXM][3];

int main()
{
	int v,p,q;

    scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&v,&p,&q);
		if(!q)
		{
			val[i][0] = v;
			wth[i][0] = p;
		}else{
			if(!val[q][1])
			{
				val[q][1] = v;
				wth[q][1] = p;
			}else{
				val[q][2] = v;
				wth[q][2] = p;
			}
		}
	}

	memset(f,0,sizeof(f));
	 for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j){
			 if(j-val[i][0] >= 0){
				f[i][j] = max(f[i-1][j],f[i-1][j-val[i][0]]+val[i][0]*wth[i][0]);

				if(j-val[i][0]-val[i][1] >= 0) f[i][j] = max(f[i][j],f[i-1][j-val[i][0]-val[i][1]]+val[i][0]*wth[i][0]+val[i][1]*wth[i][1]);
				if(j-val[i][0]-val[i][2] >= 0) f[i][j] = max(f[i][j],f[i-1][j-val[i][0]-val[i][2]]+val[i][0]*wth[i][0]+val[i][2]*wth[i][2]);
				if(j-val[i][0]-val[i][1]-val[i][2] >=0 ) f[i][j] = max(f[i][j],f[i-1][j-val[i][0]-val[i][1]-val[i][2]]+val[i][0]*wth[i][0]+val[i][1]*wth[i][1]+val[i][2]*wth[i][2]);
			}else f[i][j] = f[i-1][j];
		}
	printf("%d\n",f[m][n]);
	return 0;
}
