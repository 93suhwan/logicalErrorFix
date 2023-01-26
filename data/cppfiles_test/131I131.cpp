#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
int n,a[N],head[N*30],cnt,nod,dis[N*30];
map<int,int>mp;
struct edge{
	int to,nxt;
}e[N*60];
priority_queue<int>q;
inline void addedge(int u,int v){
	e[++cnt]=(edge){v,head[u]},head[u]=cnt;
	e[++cnt]=(edge){u,head[v]},head[v]=cnt;
}
inline void dfs(int u,int p){
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].to!=p)dis[e[i].to]=dis[u]+1,dfs(e[i].to,u);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mp[a[i]]=++nod;
		if(a[i])q.push(a[i]);
	}
	while(q.size()){
		int u=q.top();
		q.pop();
		int g=__lg(u),v=0;
		if(1<<g!=u)v=(2<<g)-u;
		if(!mp.count(v)){
			mp[v]=++nod;
			if(v)q.push(v);
		}
		addedge(mp[u],mp[v]);
	}
	int U=0,V=0;
	dfs(1,0);
	U=max_element(dis+1,dis+nod+1)-dis;
	dis[U]=0;
	dfs(U,0);
	V=max_element(dis+1,dis+nod+1)-dis;
	cout<<U<<' '<<V<<' '<<dis[V]<<'\n';
	return 0;
}