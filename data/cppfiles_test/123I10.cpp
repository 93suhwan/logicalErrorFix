#include<bits/stdc++.h>
#define R register
#define x first
#define y second
#define ll long long
#define db double
#define mp make_pair
#define pb push_back
#define pi pair<int,int>
#define lb(x) (x&-x)
#define all(x) x.begin(),x.end()
#define wt(x) write(x),puts("")
#define ot(x) write(x),putchar(' ')
#define F(i,start,end) for(R int (i)=(start);(i)<=(end);i++)
#define T(i,end,start) for(R int (i)=(start);(i)>=(end);i--)
const int N=2e5+5,M=N<<2,P=998244353;
const ll INF=1e18;
using namespace std;
template<typename T> void read(T &x)
{
	int f=1;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
void write(R ll x)
{
	if(x<0)
	{
		x=~x+1;
		putchar('-');
 	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}
int n,k,tot,b,dfn[N],dep[N],r[N],fa[N],id[N];
ll ans=-INF,cur,val;
vector<int> e[N];
bool vis[N];
namespace segment_tree
{
	#define ls u<<1
	#define rs u<<1|1
	#define mid (l+r>>1)
	int mx[M],pos[M],tag[M];
	void merge(int u)
	{
		mx[u]=max(mx[ls],mx[rs]);	
		pos[u]=mx[ls]>mx[rs]?pos[ls]:pos[rs];
	}
	void update(int u,int k)
	{
		tag[u]+=k,mx[u]+=k;
	}
	void pushdown(int u)
	{
		if(tag[u])
			update(ls,tag[u]),update(rs,tag[u]),tag[u]=0;
	}
	void build(int u,int l,int r)
	{
		if(l==r)
			return pos[u]=id[l],mx[u]=dep[id[l]],void();
		build(ls,l,mid),build(rs,mid+1,r);
		merge(u);
	}
	void modify(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql>r||l>qr)
			return;
		if(ql<=l&&r<=qr)
			return update(u,k);
		pushdown(u);
		modify(ls,l,mid,ql,qr,k),modify(rs,mid+1,r,ql,qr,k);
		merge(u);	
	}
};
using namespace segment_tree;
void dfs(int u)
{
	dfn[u]=r[u]=++tot,id[tot]=u;
	for(int v:e[u])
		if(v^fa[u])
			fa[v]=u,dep[v]=dep[u]+1,dfs(v),r[u]=max(r[u],r[v]);
}
int main()
{
	read(n),read(k);
	F(i,2,n)
	{
		int u,v;
		read(u),read(v);
		e[u].pb(v),e[v].pb(u);
	}
	dep[1]=1,dfs(1);
	build(1,1,n);
	F(i,1,k)
	{
		int u=pos[1],p=0,v=mx[1];
		val+=v;
		while(u&&!vis[u])
		{
			modify(1,1,n,dfn[u],r[u],-v);
			modify(1,1,n,dfn[p],r[p],v);
			vis[u]=1,p=u,u=fa[u],v--;
		}
	}
	b=n-val;
	ans=(ll)(n-k-b)*(k-b);
	F(i,-1,1)
		if(n/2+i<=b&&n/2+i>=0)
			ans=min(ans,(ll)(n-k-n/2-i)*(k-n/2-i));
	wt(ans);
	return 0;
}