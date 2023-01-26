#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int n,a[200005],cnt;
struct stree
{
	int add,sum;
	signed mul,l,r,ls,rs;
}t[10000005];
inline void givem(int now,int x)
{
	t[now].add*=x,t[now].add%=mod;
	t[now].sum*=x,t[now].sum%=mod;
	t[now].mul*=x,t[now].mul%=mod;
}
inline void givea(int now,int x)
{
	t[now].add+=x,t[now].add%=mod;
	t[now].sum+=x*(t[now].r-t[now].l+1),t[now].sum%=mod;
}
inline void pd(int now)
{
	int mid=(t[now].l+t[now].r)/2;
	if(!t[now].ls) t[now].ls=++cnt,t[cnt]={0,0,1,t[now].l,mid,0,0};
	if(!t[now].rs) t[now].rs=++cnt,t[cnt]={0,0,1,mid+1,t[now].r,0,0};
	givem(t[now].ls,t[now].mul);
	givem(t[now].rs,t[now].mul);
	givea(t[now].ls,t[now].add);
	givea(t[now].rs,t[now].add);
	t[now].add=0,t[now].mul=1;
}
const int inf=1e9+5;
inline void build()
{
	t[++cnt]={0,0,1,0,inf,0,0};
}
inline void add(int now,int l,int r,int d)
{
	if(t[now].l==l&&t[now].r==r)
	{
		givea(now,d);
		return ;
	}
	pd(now);
	if(t[t[now].ls].r>=r) add(t[now].ls,l,r,d);
	else if(t[t[now].rs].l<=l) add(t[now].rs,l,r,d);
	else add(t[now].ls,l,t[t[now].ls].r,d),add(t[now].rs,t[t[now].rs].l,r,d);
	t[now].sum=(t[t[now].ls].sum+t[t[now].rs].sum)%mod;
}
inline void mul(int now,int l,int r,int d)
{
	if(t[now].l==l&&t[now].r==r)
	{
		givem(now,d);
		return ;
	}
	pd(now);
	if(t[t[now].ls].r>=r) mul(t[now].ls,l,r,d);
	else if(t[t[now].rs].l<=l) mul(t[now].rs,l,r,d);
	else mul(t[now].ls,l,t[t[now].ls].r,d),mul(t[now].rs,t[t[now].rs].l,r,d);
	t[now].sum=(t[t[now].ls].sum+t[t[now].rs].sum)%mod;
}
inline int query(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	pd(now);
	if(t[t[now].ls].r>=r) return query(t[now].ls,l,r);
	else if(t[t[now].rs].l<=l) return query(t[now].rs,l,r);
	else return (query(t[now].ls,l,t[t[now].ls].r)+query(t[now].rs,t[t[now].rs].l,r))%mod;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	build();
	add(1,0,0,1);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		int lst=query(1,0,inf);
		if(i==1) add(1,0,0,-1);
		mul(1,1,inf,-1),add(1,1,inf,lst);
		mul(1,x+1,inf,0);
	}
	cout << query(1,0,inf);
	return 0;
}