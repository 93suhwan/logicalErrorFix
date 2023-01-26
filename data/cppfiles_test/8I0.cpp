#include<bits/stdc++.h>
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define db double
#define il inline
#define re register
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define fi first
#define se second
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define MP(x,y) make_pair(x,y)
#define lowbit(x) ((x)&(~(x)+1))
#define iL (1<<20)
#define TEM template<class T>il void
#define Write(x,LC) write((x)),*iter++=LC
#define Writeneg(x,LC) writeneg((x)),*iter++=LC
#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
using namespace std;
namespace IO{
	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
	TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
	TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
	TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
	TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
	TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
	TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
}
using namespace IO;
#define MAXL 25
#define MAXA (1ll<<61)
#define MAXN 100005
#define MAXC 500005
#define MAXM 500005
#define MAXQ 500005
#define MAXK 500005
#define MAXS 500005
#define MAXT 500005
#define mod 1000000007
#define BS 1919810
#define mod1 1000000007
#define mod2 1000000009
struct Edge{int next,to;}E[MAXN<<1];int head[MAXN],cnt;
il void AddE(int x,int y){E[++cnt].next=head[x],E[cnt].to=y,head[x]=cnt;}
int n,m,B,val[MAXN],deg[MAXN],V[MAXN];
int fa[MAXN],son[MAXN],dep[MAXN],top[MAXN],sz[MAXN],dfn[MAXN],DFN;
void dfs1(int x,int fat){
	dep[x]=dep[fa[x]=fat]+1,sz[x]=1;
	for(re int i=head[x];i;i=E[i].next){
		if(E[i].to^fat){
			dfs1(E[i].to,x),sz[x]+=sz[E[i].to];
			if(deg[E[i].to]<=B&&sz[son[x]]<sz[E[i].to])son[x]=E[i].to;
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
	val[x]=w;if(deg[x]>B)return;
	re int W=Getval(val[x],val[fa[x]]);
	Add(dfn[x],W-V[dfn[x]]),V[dfn[x]]=W;
	for(re int i=head[x];i;i=E[i].next){
		re int y=E[i].to;
		if(y^fa[x])W=Getval(val[x],val[y]),Add(dfn[y],W-V[dfn[y]]),V[dfn[y]]=W;
	}
}
il ll Query(int x,int y){
	re ll ans=0;
	for(;top[x]^top[y];){
		dep[top[x]]<dep[top[y]]?x^=y^=x^=y:0;
		if(x^top[x])ans+=Qry(dfn[top[x]])-Qry(dfn[x]);
		ans+=(V[dfn[top[x]]]=Getval(val[top[x]],val[fa[top[x]]])),x=fa[top[x]];
	}
	dep[x]>dep[y]?x^=y^=x^=y:0;
	if(x^y)ans+=Qry(dfn[y])-Qry(dfn[x]);
	return ans;
}
int main(){
	read(n),read(m),B=ceil(pow(n,0.5));
	for(re int i=1;i<=n;++i)readneg(val[i]);
	for(re int i=1,x,y;i<n;++i)read(x),read(y),AddE(x,y),AddE(y,x),++deg[x],++deg[y];
	dfs1(1,0),dfs2(1,0);for(re int i=1;i<=n;++i)Add(i,V[i]);
	for(re int _=0,ty,x,y;_<m;++_){
		read(ty),read(x),readneg(y);
		if(ty==1)Modify(x,y);
		else Write(Query(x,y),'\n');
	}
}