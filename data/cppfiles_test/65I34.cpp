#include<bits\stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
const int N=200005;
int A,B;
int n;
int a[N];
char ss[N];
int op[N];
int ans[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	scanf("%s",ss+1);
	if (ss[n]=='L'&&(n&1))
	{
		for (int u=1;u<=n;u++)
		{
			if (u&1) op[u]=1;
			else op[u]=0;
		}
	}
	else
	{
		for (int u=1;u<=n;u++)
		{
			if (u&1) op[u]=0;
			else op[u]=1;
		}
	}
	for (int u=1;u<=n;u++) ans[u]=op[u];
	for (int u=1;u<n;u++)
	{
		if (op[u]==0&&ss[u]=='R') continue;
		if (op[u]==1&&ss[u]=='L') continue;
		swap(a[u],a[u+1]);
		swap(ans[u],ans[u+1]);
	}
	for (int u=1;u<=n;u++)
	printf("%d %c\n",a[u],ans[u]==0?'R':'L');
	return 0;
}