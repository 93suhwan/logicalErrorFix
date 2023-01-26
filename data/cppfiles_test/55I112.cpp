#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#define R register

using namespace std;

struct SEG
{
	int l,r,maxx,maxk,lazy;
}f[2100000],g[2100000];

struct INPUT
{
	int k,l,r;
}a[300010];

map<int,int>mp;
vector<pair<int,int>>vec[300010];

int n,m,dm[600010],cdm,caf,last[300010];
bool vis[300010];

inline int read()
{
	R char c=getchar();R int num=0;
	while (c<48||c>57) c=getchar();
	while (c>47&&c<58) num=num*10+c-48,c=getchar();
	return(num);
}

inline bool cmpa(R INPUT x,R INPUT y)
{
	return(x.k<y.k||(x.k==y.k&&x.l<y.l));
}

void build(R int k,R int l,R int r)
{
	f[k].l=l;
	f[k].r=r;
	if (l==r)
	{
		f[k].maxk=l;
		return;
	}
	R int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}

void buildg(R int k,R int l,R int r)
{
	g[k].l=l;
	g[k].r=r;
	if (l==r) return;
	R int mid=(l+r)>>1;
	buildg(k<<1,l,mid);
	buildg(k<<1|1,mid+1,r);
}

inline void pushdown(R int k)
{
	if (f[k].lazy)
	{
		if (f[k<<1].maxx<f[k].lazy)
		{
			f[k<<1].maxx=f[k].lazy;
			f[k<<1].maxk=f[k].maxk;
		}
		if (f[k<<1].lazy<f[k].lazy) f[k<<1].lazy=f[k].lazy;
		if (f[k<<1|1].maxx<f[k].lazy)
		{
			f[k<<1|1].maxx=f[k].lazy;
			f[k<<1|1].maxk=f[k].maxk;
		}
		if (f[k<<1|1].lazy<f[k].lazy) f[k<<1|1].lazy=f[k].lazy;
		f[k].lazy=0;
	}
} 

inline void pushdowng(R int k)
{
	if (g[k].lazy)
	{
		if (g[k<<1].maxx<g[k].lazy) g[k<<1].maxx=g[k].lazy;
		if (g[k<<1].lazy<g[k].lazy) g[k<<1].lazy=g[k].lazy;
		if (g[k<<1|1].maxx<g[k].lazy) g[k<<1|1].maxx=g[k].lazy;
		if (g[k<<1|1].lazy<g[k].lazy) g[k<<1|1].lazy=g[k].lazy;
		g[k].lazy=0;
	}
} 

SEG query(R int k,R int l,R int r)
{
	if (l<=f[k].l&&r>=f[k].r) return(f[k]);
	pushdown(k);
	R int mid=(f[k].l+f[k].r)>>1;
	if (r<=mid) return(query(k<<1,l,r));
	else if (l>mid) return(query(k<<1|1,l,r));
	else
	{
		R SEG q1=query(k<<1,l,mid);
		R SEG q2=query(k<<1|1,mid+1,r);
		return(q1.maxx<q2.maxx?q2:q1);
	}
}

SEG queryg(R int k,R int l)
{
	if (l<=g[k].l&&l>=g[k].r) return(g[k]);
	pushdowng(k);
	R int mid=(g[k].l+g[k].r)>>1;
	if (l<=mid) return(queryg(k<<1,l));
	else if (l>mid) return(queryg(k<<1|1,l));
}

void update(R int k,R int l,R int r,R SEG v)
{
	//printf("update l=%d r=%d %d %d\n",f[k].l,f[k].r,l,r);
	if (l<=f[k].l&&r>=f[k].r) 
	{
		if (v.maxx>f[k].maxx)
		{
			f[k].maxx=v.maxx;
			f[k].maxk=l;
		}
		if (v.maxx>f[k].lazy) f[k].lazy=v.maxx;
		return;
	}
	R int mid=(f[k].l+f[k].r)>>1;
	pushdown(k);
	if(r<=mid) update(k<<1,l,r,v);
    else if(l>mid) update(k<<1|1,l,r,v);
	else
	{
		update(k<<1,l,r,v);
		update(k<<1|1,l,r,v);
	}
	if (f[k<<1].maxx>f[k<<1|1].maxx)
	{
		f[k].maxx=f[k<<1].maxx;
		f[k].maxk=f[k<<1].maxk;
	}
	else
	{
		f[k].maxx=f[k<<1|1].maxx;
		f[k].maxk=f[k<<1|1].maxk;
	}
	return;
}

void updateg(R int k,R int l,R int r,R int v)
{
	//printf("update l=%d r=%d %d %d\n",g[k].l,g[k].r,l,r);
	if (l<=g[k].l&&r>=g[k].r) 
	{
		if (v>g[k].maxx) g[k].maxx=v;
		if (v>g[k].lazy) g[k].lazy=v;
		return;
	}
	R int mid=(g[k].l+g[k].r)>>1;
	pushdowng(k);
	if(r<=mid) updateg(k<<1,l,r,v);
    else if(l>mid) updateg(k<<1|1,l,r,v);
	else
	{
		updateg(k<<1,l,r,v);
		updateg(k<<1|1,l,r,v);
	}
	if (g[k<<1].maxx>g[k<<1|1].maxx) g[k].maxx=g[k<<1].maxx;
	else g[k].maxx=g[k<<1|1].maxx;
	return;
}

int main()
{
	n=read(),m=read();
	for (R int i=1;i<=m;i++)
	{
		a[i].k=read(),a[i].l=read(),a[i].r=read();
		dm[++cdm]=a[i].l;
		dm[++cdm]=a[i].r;
	}
	sort(dm+1,dm+cdm+1);
	for (R int i=1;i<=cdm;i++) if (dm[i]!=dm[i-1]) mp[dm[i]]=++caf;
	sort(a+1,a+1+m,cmpa);
	build(1,1,caf);
	buildg(1,1,caf);
	for (R int i=1;i<=m;i++)
	{
		R int k=a[i].k,l=mp[a[i].l],r=mp[a[i].r];
		vec[k].push_back({l,r});
	}
	for (R int i=1;i<=n;i++)
	{
		R int size=vec[i].size();
		R SEG maxx={0,0,0,0,0};
		for (R int j=0;j<size;j++)
		{
			R int l=vec[i][j].first,r=vec[i][j].second;
			SEG q=query(1,l,r);
			//printf("query f:l=%d r=%d maxx=%d\n",l,r,q.maxx);
			if (q.maxx>=maxx.maxx) maxx.maxx=q.maxx,maxx.maxk=q.maxk;
		}
		last[i]=queryg(1,maxx.maxk).maxx;
		maxx.maxx++;
		for (R int j=0;j<size;j++)
		{
			R int l=vec[i][j].first,r=vec[i][j].second;
			update(1,l,r,maxx);
			//printf("f:l=%d r=%d maxx=%d\n",l,r,maxx.maxx);
			updateg(1,l,r,i);
			//printf("g:l=%d r=%d i=%d\n",l,r,i);
		}
	} 
	R SEG q=query(1,1,caf);
	printf("%d\n",n-q.maxx);
	R int k=q.maxk;
	//printf("k=%d\n",k);
	R int tmp=queryg(1,k).maxx;
	vis[tmp]=1;
	//printf("tmp=%d\n",tmp);
	R int cnt=0;
	for (R int i=1;i<=n;i++) if (!vis[i]) cnt++;
	if (n==68166) printf("cnt=%d\n",cnt);
	while (tmp!=0) tmp=last[tmp],vis[tmp]=1;
	for (R int i=1;i<=n;i++) if (!vis[i]) printf("%d ",i);
}