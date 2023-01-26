#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 1e5+5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
int T,n,ans[N],deg[N];vi v[N];
queue<int>q;int cnt[N];
bool check(int val)
{
	for(int i=0;i<n;i++)deg[i]=v[i].size(),cnt[i]=0;
	while(!q.empty())q.pop();
	for(int i=0;i<n;i++)
		if(deg[i]==1)
			q.push(i);
	int g=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		deg[now]=0;bool ok=false;int rem;
		for(int i=0;i<v[now].size();i++)
		{
			int to=v[now][i];
			if(deg[to])
			{
				ok=true;
				rem=to;
				deg[to]--;
				if(deg[to]==1)
					q.push(to);
			}
		}
		if(ok){
			if(cnt[now]%val==0)cnt[rem]++,g=__gcd(g,cnt[now]);
			else if((cnt[now]+1)%val==0)cnt[now]++,g=__gcd(g,cnt[now]);
			else return false;
		}else if(cnt[now]%val!=0)return false;
		else g=__gcd(g,cnt[now]);
	}
	return g==val;
}
void solve()
{
	scanf("%d",&n);ans[n]=0;
	for(int i=0;i<n;i++)v[i].clear();
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	ans[1]=1;
	for(int i=1;i<n;i++)ans[1]=1ll*ans[1]*2%mod;
	for(int i=2;i<=n-1;i++)
		if((n-1)%i==0)
			ans[i]=check(i),ans[1]=(ans[1]-ans[i]+mod)%mod;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return;
}
int main()
{
//	cin>>T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}