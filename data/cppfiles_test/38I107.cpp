#include<bits/stdc++.h>
#define R register int
#define I inline
#define ll long long
using namespace std;
const int N=1e6+3;
vector<char>a[N],b[N],c[N];
vector<int>w;
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	w.resize(m+1);
	for(R i=1;i<=n;i++)
	{
		a[i].resize(m+1);
		b[i].resize(m+1);
		c[i].resize(m+1);
		getchar();
		for(R j=1;j<=m;j++)
			a[i][j]=getchar();
	}
	
	for(R j=1;j<=m;j++)b[n][j]=(a[n][j]=='X');
	for(R i=n-1;i;i--)
		for(R j=1;j<=m;j++)b[i][j]=b[i+1][j]&&(a[i][j]=='X');
	for(R i=1;i<=n;i++)c[i][m]=(a[i][m]=='X');
	for(R j=m-1;j;j--)
		for(R i=1;i<=n;i++)c[i][j]=c[i][j+1]&&(a[i][j]=='X');
	for(R i=1;i<n;i++)
		for(R j=1;j<m;j++)
			if(b[i][j]&&c[i][j])w[j]=1;
	for(R i=1;i<=m;i++)w[i]+=w[i-1];
	int q;scanf("%d",&q);
	while(q--)
	{
		int l,r;scanf("%d%d",&l,&r);
		if(w[r-1]-w[l-1]>0)puts("NO");
		else puts("YES");
	}
}
int main()
{
//	int t;scanf("%d",&t);
//	while(t--)
	solve();
	return 0;

}
