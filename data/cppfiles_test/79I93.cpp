#include <cstdio>
#include <queue>
using namespace std;
inline int rd(){
	register int x=0,f=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
int n,h[1500010],to[1500010],at[300010],tot;
int dis[1500010],pre[1500010],ans[300010];
struct edge{int to,next;bool w;}e[1500010];
bool vis[1500010];
inline void add(const int &u,const int &v,const int &w){
	e[++tot]=(edge){v,h[u],w},h[u]=tot;
}
void build(int l,int r,int p){
	if(l==r){at[l]=p,to[p]=l;return;}
	int mid=l+r>>1;
	add(p,p<<1,0);
	add(p,p<<1|1,0);
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
}
inline void qadd(int l,int r,int p,const int &b,const int &e){
	if(b<=l && e>=r){
		add(4*(n+1)+e,p,1);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid)qadd(l,mid,p<<1,b,e);
	if(e>mid)qadd(mid+1,r,p<<1|1,b,e);
}
inline void bfs(const int &s){
	deque<int> q;
	q.push_back(s),vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop_front();
		for(int i=h[u],v;i;i=e[i].next){
			v=e[i].to;
			if(vis[v])continue;
			if(e[i].w){
				dis[v]=dis[u]+1;
				pre[v]=u,vis[v]=1;
				q.push_back(v);
			}
			else{
				dis[v]=dis[u];
				pre[v]=u,vis[v]=1;
				q.push_front(v);
			}
		}
	}
}
int main(){
	n=rd(),build(0,n,1);
	for(int i=1;i<=n;++i)
		qadd(0,n,1,i-rd(),i);
	for(int i=1;i<=n;++i)
		add(at[i],4*(n+1)+i+rd(),0);
	bfs(at[n]);
	if(!pre[at[0]])return puts("-1"),0;
	printf("%d\n",dis[at[0]]);
	tot=0;
	for(int i=at[0];i!=at[n];i=pre[i])
		if(to[i])ans[++tot]=to[i];
	for(int i=tot;i;--i)printf("%d ",ans[i]);
	putchar('0');
	putchar('\n');
	return 0;
}