#include<bits/stdc++.h>
#define il inline
#define re register
#define ll long long
#define lowbit(x) ((x)&(~(x)+1))
#define iL (1<<20)
#define TEM template<class T>il void
#define Write(x,LC) write((x)),*iter++=LC
#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
using namespace std;
namespace IO{
	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
	TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
	TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
	TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
}
using namespace IO;
#define MAXN 100005
struct Edge{int next,to;}E[MAXN<<1];int head[MAXN],cnt;
il void AddE(int x,int y){E[++cnt].next=head[x],E[cnt].to=y,head[x]=cnt;}
int n,m,val[MAXN],V[MAXN];
int fa[MAXN],son[MAXN],dep[MAXN],top[MAXN],sz[MAXN],dfn[MAXN],DFN;
void dfs1(int x,int fat){
	dep[x]=dep[fa[x]=fat]+1,sz[x]=1;
	for(re int i=head[x];i;i=E[i].next){
		if(E[i].to^fat){
			dfs1(E[i].to,x),sz[x]+=sz[E[i].to];
			if(sz[son[x]]<sz[E[i].to])son[x]=E[i].to;
		}
	}
}
il int Getval(int x,int y){return max(abs(x-y),abs(x+y));}
void dfs2(int x,int fat){
	V[dfn[x]=++DFN]=Getval(val[x],val[fa[x]]),
	top[x]=fat;if(son[x])dfs2(son[x],fat);
	for(re int i=head[x];i;i=E[i].next)if(E[i].to^fa[x]&&E[i].to^son[x])dfs2(E[i].to,E[i].to);
}
ll sum[MAXN];
il void Add(int x,int w){for(;x<=n;sum[x]+=w,x+=lowbit(x));}
il ll Qry(int x){re ll ans=0;for(;x;ans+=sum[x],x^=lowbit(x));return ans;}
il void Modify(int x,int w){
	val[x]=w;re int W=Getval(val[x],val[fa[x]]);
	Add(dfn[x],W-V[dfn[x]]),V[dfn[x]]=W;
	for(re int i=head[x];i;i=E[i].next){
		re int y=E[i].to;
		if(y^fa[x])W=Getval(val[x],val[y]),Add(dfn[y],W-V[dfn[y]]),V[dfn[y]]=W;
	}
}
il ll Query(int x,int y){
	re ll ans=0;
	for(;top[x]^top[y];dep[top[x]]<dep[top[y]]?x^=y^=x^=y:0,ans+=Qry(dfn[x])-Qry(dfn[top[x]]),x=fa[top[x]]);
	dep[x]>dep[y]?x^=y^=x^=y:0,ans+=Qry(dfn[y])-Qry(dfn[x]);
	return ans;
}
int main(){
	read(n),read(m);
	for(re int i=1;i<=n;++i)readneg(val[i]);
	for(re int i=1,x,y;i<n;++i)read(x),read(y),AddE(x,y),AddE(y,x);
	dfs1(1,0),dfs2(1,0);for(re int i=1;i<=n;++i)Add(i,V[i]);
	for(re int _=0,ty,x,y;_<m;++_){
		read(ty),read(x),readneg(y);
		if(ty==1)Modify(x,y);
		else Write(Query(x,y),'\n');
	}
}