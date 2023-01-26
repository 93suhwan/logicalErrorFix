#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,q,m;
vector<char> s;
string ss;
namespace SA {
	const int N=::N*4;
	int sig='z',c[N],x[N],y[N],sa[N],ht[N],rk[N],st[20][N];
	void base_sort() {
		fr(i,1,sig) c[i]=0;
		fo(i,0,s.size()) ++c[x[i]];
		fr(i,1,sig) c[i]+=c[i-1];
		rf(i,s.size()-1,0) sa[--c[x[y[i]]]]=y[i];
	}
	void getSA() {
		fo(i,0,s.size()) x[i]=s[i],y[i]=i;
		base_sort();
		for(int k=1,cur;k<=s.size();k<<=1) {
			cur=0;
			fo(i,s.size()-k,s.size()) y[cur++]=i;
			fo(i,0,s.size()) if(sa[i]>=k) y[cur++]=sa[i]-k;
			base_sort(); swap(x,y);
			x[sa[0]]=cur=1;
			fo(i,1,s.size()) if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]) x[sa[i]]=cur;
			else x[sa[i]]=++cur;
			if(cur==s.size()) break;
			sig=cur;
		}
	}
	void getht() {
		fo(i,0,s.size()) rk[sa[i]]=i;
		int k=0;
		fo(i,0,s.size()) {
			if(rk[i]==0) continue;
			int j=sa[rk[i]-1];
			if(k) --k;
			while(i+k<s.size()&&j+k<s.size()&&s[i+k]==s[j+k]) ++k;
			ht[rk[i]]=k;
		}
	}
	int getlcp(int i,int j) {
		if(i==j) return s.size()-i;
		i=rk[i],j=rk[j];
		if(i>j) swap(i,j); ++i;
		int k=__lg(j-i+1);
		return min(st[k][i],st[k][j-(1<<k)+1]);
	}
	void build() {
		getSA(); getht();
		fo(i,1,s.size()) st[0][i]=ht[i];
		fr(k,1,19) if(1<<k<s.size()) fr(i,1,s.size()-(1<<k))
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
	}
} using SA::sa; using SA::rk; using SA::ht; using SA::getlcp;

int fir[N],to[N<<1],eds,nxt[N<<1];
char wei[N<<1],val[N];
void addedge(int u,int v,char c) {
	to[++eds]=v;
	wei[eds]=c;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int siz[N],son[N],top[N],fa[N],dep[N],up[N],dn[N];
void dfs1(int u) {
	siz[u]=1; dep[u]=dep[fa[u]]+1;
	foredge(i,u,v) if(v!=fa[u]) {
		val[v]=wei[i]; fa[v]=u; dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
int stk[N],tp,len[N];
void dfs2(int u) {
	if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
	else {
		stk[tp=1]=u;
		while(stk[tp]!=top[u]) ++tp,stk[tp]=fa[stk[tp-1]];
		if(stk[tp]==1) --tp;
		fr(i,1,tp) up[stk[i]]=s.size(),s.push_back(val[stk[i]]);
		rf(i,tp,1) dn[stk[i]]=s.size(),s.push_back(val[stk[i]]);
	}
	foredge(i,u,v) if(v!=fa[u]&&v!=son[u])
		top[v]=v,dfs2(v);
}
int LCA(int u,int v) {
	while(top[u]^top[v]) {
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		u=fa[top[u]];
	} return dep[u]<dep[v]?u:v;
}
struct Query {int id,l,r,op;};
vector<Query> buc[N<<1];
int ans[N];
int pos[N];
int cmp(int p) {
	fr(i,1,tp) {
		int z=getlcp(stk[i],p);
		if(z<len[i]) return s[p+z]-s[stk[i]+z];
	} return 0;
}
void getbuc() {
	fr(i,1,q) {
		static int u,v,l,r,lca;
		cin>>u>>v>>l>>r;
		lca=LCA(u,v); tp=0;
		while(top[u]!=top[lca]) {
			stk[++tp]=up[u];
			len[tp]=dep[u]-dep[top[u]]+1;
			u=fa[top[u]];
		}
		if(u!=lca) {
			stk[++tp]=up[u];
			len[tp]=dep[u]-dep[lca];
		}
		int res=tp;
		while(top[v]!=top[lca]) {
			stk[++tp]=dn[top[v]];
			len[tp]=dep[v]-dep[top[v]]+1;
			v=fa[top[v]];
		}
		if(v!=lca) {
			stk[++tp]=dn[son[lca]];
			len[tp]=dep[v]-dep[lca];
		}
		reverse(stk+res+1,stk+tp+1);
		reverse(len+res+1,len+tp+1);
		int L=-1,R=s.size();
		rf(k,19,0) if(L+(1<<k)<s.size()&&cmp(sa[L+(1<<k)])<0) L+=1<<k;
		rf(k,19,0) if(R-(1<<k)>=0&&cmp(sa[R-(1<<k)])>0) R-=1<<k;
		if(L>=0) buc[L].push_back((Query){i,l,r,-1});
		if(R>=1) buc[R-1].push_back((Query){i,l,r,1});
	}
}
int BIT[N]; void add(int x,int v) {for(;x<=m;x+=x&-x) BIT[x]+=v;}
int ask(int x) {int z=0; for(;x;x&=x-1) z+=BIT[x]; return z;}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1,u,v;i<n;++i) {
		static char c;
		cin>>u>>v>>c;
		addedge(u,v,c);
		addedge(v,u,c);
	}
	dfs1(1); top[1]=1; dfs2(1);
	fr(i,1,m) {
		cin>>ss;
		s.push_back('#');
		pos[i]=s.size();
		fo(j,0,ss.size()) s.push_back(ss[j]);
	}
	//for(auto x:s) cout<<x; cout<<endl;
	SA::build();
	getbuc();
	fo(i,0,s.size()) {
		if(s[sa[i]]!='#') {
			int bl=upper_bound(pos+1,pos+m+1,sa[i])-pos-1;
			if(bl) add(bl,1);
		}
		for(auto p:buc[i]) ans[p.id]+=p.op*(ask(p.r)-ask(p.l-1));
	}
	fr(i,1,q) cout<<ans[i]<<endl;
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}
